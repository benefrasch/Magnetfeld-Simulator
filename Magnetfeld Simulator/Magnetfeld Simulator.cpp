#include <iostream>
#include <tuple>
#include "BMP.h"
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "Constants.h"
#include <Windows.h>
#include <future>
#include <chrono>

static BMP bmp(image_size_x, image_size_y, false);
static int done_graphs = 0;


bool plot_vector(std::vector<wire_part>* parts, long double y_start, bool inverted) {
	long double x = simulation_size_x / 2,
		y = y_start;
	if (!inverted)
		while (x <= simulation_size_x / 2 && x >= 0) {
			Vektor b_vektor = B_Vektor::vektor(parts, x, y, simulation_size_z / 2);
			x += b_vektor.x, y += b_vektor.y;
			if (!(x<0 || x>simulation_size_x || y<0 || y>simulation_size_y))
				bmp.set_pixel(x * (image_size_x / simulation_size_x), y * (image_size_y / simulation_size_y), 255, 255, 255, 255);
		}
	else
		while (x >= simulation_size_x / 2 && x <= simulation_size_x) {
			Vektor b_vektor = B_Vektor::vektor(parts, x, y, simulation_size_z / 2);
			b_vektor.x *= -1, b_vektor.y *= -1, b_vektor.z *= -1;
			x += b_vektor.x, y += b_vektor.y;
			if (!(x<0 || x>simulation_size_x || y<0 || y>simulation_size_y))
				bmp.set_pixel(x * (image_size_x / simulation_size_x), y * (image_size_y / simulation_size_y), 255, 255, 255, 255);
		}
	bmp.write("output.bmp");
	++done_graphs;
	return true;
}

int main()
{


	/*std::cout << "Please type the radius you want to use. (default value 0.04m) \n(This value will be used for calculation of the Wire and/or the origin area of the magnetic field lines)\n";
	float radius = 0.04;
	std::cin >> radius;
	std::cout << "so you have chosen " << radius << "\n\n";

	std::cout << "How big should your first step be? (default value 0.001m)\n";
	float step_size = 0.001;
	std::cin >> step_size;
	std::cout << "so you have chosen " << step_size << "\n\n";*/


	//std::vector<wire_part> parts = Wire_parts::ring(radius);
	std::vector<wire_part> parts = Wire_parts::coil(radius, coil_total_length, coil_winding_count);

	return 0;

	auto start = std::chrono::high_resolution_clock::now();

	std::vector<long double> start_y_values;
	long double first_step = step_size * -(B_Vektor::vektor(&parts, simulation_size_x / 2, simulation_size_y / 2, simulation_size_z / 2).x);
	for (long double y_start = simulation_size_y / 2;
		y_start < (double)simulation_size_y / 2 + radius - 0.001;
		y_start += first_step / -(B_Vektor::vektor(&parts, simulation_size_x / 2, y_start, simulation_size_z / 2).x)) {
		start_y_values.push_back(y_start);
		start_y_values.push_back((simulation_size_y / 2) - (y_start - (simulation_size_y / 2)));
		//std::cout << y_start << "  " << (B_Vektor::vektor(&parts, simulation_size_x / 2, y_start, simulation_size_z / 2).x) << "\n";
	}

	std::cout << "\n starting calculation...\nAlso expect the calculation never to finish, but if it is above 90%, it is ok. This shit buggy. \n\n";
	std::vector<std::future<bool>> graphs;
	for (double y_start : start_y_values)
	{
		std::cout << "Y-Value " << y_start << " started calculating" << "\n";
		graphs.push_back(std::async(plot_vector, &parts, y_start, false)); //plot graph to both left and right side
		graphs.push_back(std::async(plot_vector, &parts, y_start, true));
	}

	while (done_graphs < start_y_values.size() * 2) {
		std::cout << "Waiting for calculations to finish - " << done_graphs << " out of " << (start_y_values.size() * 2) << " done!\n";
		Sleep(10000);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "all done! Only took " << (float)elapsed.count() / 60 << " minutes.";
}