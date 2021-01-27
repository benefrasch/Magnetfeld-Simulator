#include "Wire_parts.h"
#include "Constants.h"
#include <iostream>


std::vector<wire_part> Wire_parts::ring(float radius)
{
	std::vector<wire_part> wire_part_vector = {};
	float middle_x = simulation_size_x / 2, middle_y = simulation_size_y / 2, middle_z = simulation_size_z / 2;
	for (int current_part = 0; current_part < simulation_wire_parts_count; ++current_part) {
		wire_part temp = {
			middle_x,
			middle_y - cos((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius,
			middle_z + sin((long double)current_part / simulation_wire_parts_count * 2 * PI) * radius,
			0,
			(long double)current_part / simulation_wire_parts_count * 2 * PI,
			((long double)radius * 2 * PI) / simulation_wire_parts_count,
		};
		wire_part_vector.push_back(temp);
	}
	return wire_part_vector;
}

std::vector<wire_part> Wire_parts::coil(float radius, float coil_total_length, float coil_winding_count)
{
	std::vector<wire_part> wire_part_vector = {};
	float middle_x = simulation_size_x / 2, middle_y = simulation_size_y / 2, middle_z = simulation_size_z / 2;

	float diffx = coil_total_length / simulation_wire_parts_count;


	return wire_part_vector;
}
