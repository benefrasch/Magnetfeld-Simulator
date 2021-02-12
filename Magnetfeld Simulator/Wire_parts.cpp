#include "Wire_parts.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>


std::vector<wire_part> Wire_parts::ring(float radius)
{
	std::vector<wire_part> wire_part_vector = {};
	float middle_x = simulation_size / 2, middle_y = simulation_size / 2, middle_z = simulation_size / 2;
	long double last_x = 0,
		last_y = middle_y - cos((long double)0 / simulation_wire_parts_count * 2 * PI) * radius,
		last_z = middle_z + sin((long double)0 / simulation_wire_parts_count * 2 * PI) * radius;
	for (int current_part = 0; current_part < simulation_wire_parts_count + 1; ++current_part) {
		wire_part temp = {
			middle_x,
			middle_y - cos((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius,
			middle_z + sin((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius,
			0,
			middle_y - cos((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius - last_y,
			middle_z + sin((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius - last_z,
		};
		last_x = temp.x, last_y = temp.y, last_z = temp.z;
		wire_part_vector.push_back(temp);
		//std::cout << temp.x<< "  " << temp.y << "  " << temp.z << "  " << temp.wirepart_x << "  " << temp.wirepart_y << "  " << temp.wirepart_z << "\n";
	}
	wire_part_vector.erase(wire_part_vector.begin());
	return wire_part_vector;
}

std::vector<wire_part> Wire_parts::coil(const float radius, const float coil_total_length, const int coil_winding_count)
{
	std::vector<wire_part> wire_part_vector = {};
	const float middle_x = simulation_size / 2, middle_y = simulation_size / 2, middle_z = simulation_size / 2;
	long double last_x = (simulation_size - coil_total_length) / 2,
		last_y = middle_y - cos((long double)0 / simulation_wire_parts_count * 2 * PI) * radius,
		last_z = middle_z + sin((long double)0 / simulation_wire_parts_count * 2 * PI) * radius;

	const float diffx = coil_total_length / simulation_wire_parts_count;
	const int wireparts_in_winding = simulation_wire_parts_count / coil_winding_count;
	int current_winding_part = 0;
	for (float x = (simulation_size - coil_total_length) / 2;
		x <= simulation_size / 2 + coil_total_length / 2;
		x += diffx, ++current_winding_part) {
		if (current_winding_part >= wireparts_in_winding) current_winding_part = 0;
		wire_part temp = {
			x,
			middle_y - cos((long double)current_winding_part / wireparts_in_winding * 2 * PI) * radius,
			middle_z + sin((long double)current_winding_part / wireparts_in_winding * 2 * PI) * radius,
			x - last_x,
			middle_y - cos((long double)current_winding_part / wireparts_in_winding * 2 * PI) * radius - last_y,
			middle_z + sin((long double)current_winding_part / wireparts_in_winding * 2 * PI) * radius - last_z,
		};
		last_x = temp.x, last_y = temp.y, last_z = temp.z;
		wire_part_vector.push_back(temp);
		//std::cout << temp.x << "  " << temp.y << "  " << temp.z << "  " << temp.wirepart_x << "  " << temp.wirepart_y << "  " << temp.wirepart_z << "\n";
	}
	wire_part_vector.erase(wire_part_vector.begin());
	return wire_part_vector;
}
