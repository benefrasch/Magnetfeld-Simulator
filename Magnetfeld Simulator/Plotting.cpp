#include "Plotting.h"
#include "Constants.h"

static BMP bmp(image_size, image_size, false);

bool plot_vector(std::vector<wire_part>* parts, long double y_start, bool inverted) {
	long double x = simulation_size / 2,
		y = y_start;
	if (!inverted)
		while (x <= simulation_size / 2 && x >= 0) {
			Vektor b_vektor = B_Vektor::vektor(parts, x, y, simulation_size / 2);
			long double b_value = sqrt(pow(b_vektor.x, 2) + pow(b_vektor.y, 2) + pow(b_vektor.z, 2));
			b_vektor.x /= b_value * image_size, b_vektor.y /= b_value * image_size, b_vektor.z /= b_value * image_size;
			x += b_vektor.x, y += b_vektor.y;
			if (!(x<0 || x>simulation_size || y<0 || y>simulation_size))
				bmp.set_pixel(x * (image_size / simulation_size), y * (image_size / simulation_size), 255, 255, 255, 255);
		}
	else
		while (x >= simulation_size / 2 && x <= simulation_size) {
			Vektor b_vektor = B_Vektor::vektor(parts, x, y, simulation_size / 2);
			long double b_value = sqrt(pow(b_vektor.x, 2) + pow(b_vektor.y, 2) + pow(b_vektor.z, 2));
			b_vektor.x *= -1, b_vektor.y *= -1, b_vektor.z *= -1;
			b_vektor.x /= b_value * image_size, b_vektor.y /= b_value * image_size, b_vektor.z /= b_value * image_size;
			x += b_vektor.x, y += b_vektor.y;
			if (!(x<0 || x>simulation_size || y<0 || y>simulation_size))
				bmp.set_pixel(x * (image_size / simulation_size), y * (image_size / simulation_size), 255, 255, 255, 255);
		}
	return true;
}
void Plotting::plotLines(std::vector<wire_part>* parts)
{
	std::vector<long double> start_y_values;
	long double first_step = step_size * -(B_Vektor::vektor(parts, simulation_size / 2, simulation_size / 2, simulation_size / 2).x);
	for (long double y_start = simulation_size / 2;
		y_start < (double)simulation_size / 2 + radius - 0.0001;
		y_start += first_step / -(B_Vektor::vektor(parts, simulation_size / 2, y_start, simulation_size / 2).x)) {
		start_y_values.push_back(y_start);
	}
	for (long double y_start = simulation_size / 2;
		y_start > (double)simulation_size / 2 - radius + 0.0001;
		y_start -= first_step / -(B_Vektor::vektor(parts, simulation_size / 2, y_start, simulation_size / 2).x)) {
		start_y_values.push_back(y_start);
	}

	std::cout << "\n starting calculation...\n\n";
	std::vector<std::future<bool>> graphs;
	for (double y_start : start_y_values)
	{
		graphs.push_back(std::async(plot_vector, parts, y_start, false)); //plot graph to both left and right side
		graphs.push_back(std::async(plot_vector, parts, y_start, true));
	}

	for (int graph = 0; graph < graphs.size(); ++graph) {
		graphs[graph].wait();
		std::cout << "Waiting for calculations to finish - " << graph << " out of " << (graphs.size()) << " done!\n";
		bmp.write("C:/Users/benef/Desktop/output.bmp");
	}
}


