#include "Plotting.h"
#include "Constants.h"

static BMP bmp(image_size, image_size, false);

bool plotLine(std::vector<wire_part>* parts, long double y_start, bool inverted) {
	long double x = simulation_size / 2,
		y = y_start;
	if (!inverted)
		while (x <= simulation_size / 2 && x >= 0) { //as long as in frame and current half
			std::vector<long double> b_vektor = B_Vektor::vektor(parts, x, y, simulation_size / 2); //get the vector for current position
			long double b_value = sqrt(pow(b_vektor[0], 2) + pow(b_vektor[1], 2)); //total for unit vector
			b_vektor[0] /= b_value * image_size, b_vektor[1] /= b_value * image_size;
			x += b_vektor[0], y += b_vektor[1];
			if (!(x<0 || x>simulation_size || y<0 || y>simulation_size))
				bmp.set_pixel(x * (image_size / simulation_size), y * (image_size / simulation_size), 255, 255, 255, 255);
		}
	else
		while (x >= simulation_size / 2 && x <= simulation_size) {
			std::vector<long double> b_vektor = B_Vektor::vektor(parts, x, y, simulation_size / 2);
			long double b_value = sqrt(pow(b_vektor[0], 2) + pow(b_vektor[1], 2));
			b_vektor[0] *= -1, b_vektor[1] *= -1; //make the line go to the right
			b_vektor[0] /= b_value * image_size, b_vektor[1] /= b_value * image_size;
			x += b_vektor[0], y += b_vektor[1];
			if (!(x<0 || x>simulation_size || y<0 || y>simulation_size))
				bmp.set_pixel(x * (image_size / simulation_size), y * (image_size / simulation_size), 255, 255, 255, 255);
		}
	return true;
}
void Plotting::plotLines(std::vector<wire_part>* parts)
{
	std::vector<long double> start_y_values;
	long double first_step = step_size_lines * -(B_Vektor::vektor(parts, simulation_size / 2, simulation_size / 2, simulation_size / 2)[0]);
	for (long double y_start = simulation_size / 2;
		y_start < (double)simulation_size / 2 + radius - 0.0001;
		y_start += first_step / -(B_Vektor::vektor(parts, simulation_size / 2, y_start, simulation_size / 2)[0])) {
		start_y_values.push_back(y_start);
	}
	for (long double y_start = simulation_size / 2;
		y_start > (double)simulation_size / 2 - radius + 0.0001;
		y_start -= first_step / -(B_Vektor::vektor(parts, simulation_size / 2, y_start, simulation_size / 2)[0])) {
		start_y_values.push_back(y_start);
	}

	std::cout << "\n starting calculation...\n\n";
	std::vector<std::future<bool>> graphs;
	for (double y_start : start_y_values)
	{
		graphs.push_back(std::async(plotLine, parts, y_start, false)); //plot graph to both left and right side
		graphs.push_back(std::async(plotLine, parts, y_start, true));
	}

	for (int graph = 0; graph < graphs.size(); ++graph) {
		graphs[graph].wait();
		std::cout << "Waiting for calculations to finish - " << graph << " out of " << (graphs.size()) << " done!\n";
		bmp.write("C:/Users/benef/Desktop/output.bmp");
	}
}

void Plotting::plotField(std::vector<wire_part>* parts)
{
	for (int x = step_size_vector; x < image_size; x += step_size_vector) {
		for (int y = step_size_vector; y < image_size; y += step_size_vector) {

			std::vector<long double> b_vektor = B_Vektor::vektor(parts, x * simulation_size / image_size, y * simulation_size / image_size, simulation_size / 2);

			long double b_value = sqrt(pow(b_vektor[0], 2) + pow(b_vektor[1], 2));
			b_vektor[0] /= (b_value), b_vektor[1] /= (b_value);
			float x1 = x, y1 = y;
			for (int i = 0; i < step_size_vector / 2; ++i) {
				x1 += b_vektor[0], y1 += b_vektor[1];
				bmp.set_pixel(x1, y1, 100, 100, 100, 255);
			}
			bmp.set_pixel(x, y, 255, 0, 255, 255);
		}
	}
	bmp.write("C:/Users/benef/Desktop/output.bmp");
}

