#include "B_Vektor.h"
#include "Wire_parts.h"
#include <vector>
#include "Constants.h"
#include <math.h>

std::tuple<float, float, float> B_Vektor::vektor(float x, float y, float z)
{
	std::vector<wire_part> parts = Wire_parts::ring();
	for (int current_part = 0; current_part < simulation_wire_parts_count; ++current_part) {
		wire_part part = parts[current_part];
		//std::cout << part.x << "   " << part.y << "   " << part.z << "\n";
		//bmp.set_pixel(part.y * (image_size_x / simulation_size_y), part.z * (image_size_y / simulation_size_z), 255, 255, 255, 255);

		float diffx = x - part.x, diffy = y - part.y, diffz = z - part.z;
		float r = sqrt(pow(diffx, 2) + pow(diffy, 2) + pow(diffz, 2));
	}

	return std::make_tuple(1, 2, 3);
}
