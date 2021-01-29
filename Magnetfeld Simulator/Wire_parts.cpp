#include "Wire_parts.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>


std::vector<wire_part> Wire_parts::ring(float radius)
{
	std::vector<wire_part> wire_part_vector = {};
	float middle_x = simulation_size / 2, middle_y = simulation_size / 2, middle_z = simulation_size / 2;
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

std::vector<wire_part> Wire_parts::coil(const float radius, const float coil_total_length, const float coil_winding_count)
{
	std::vector<wire_part> wire_part_vector = {};
	const float middle_x = simulation_size / 2, middle_y = simulation_size / 2, middle_z = simulation_size / 2;
	const float diffx = coil_total_length / simulation_wire_parts_count;
	const int wireparts_in_winding = simulation_wire_parts_count / coil_winding_count;
	int current_winding_part = 0;
	for (float x = simulation_size / 2 - coil_total_length / 2;
		x <= simulation_size / 2 + coil_total_length / 2;
		x += diffx, ++current_winding_part) {
		if (current_winding_part == wireparts_in_winding) current_winding_part = 0;
		wire_part temp = {
			x,
			middle_y - cos((long double)current_winding_part / coil_winding_count * 2 * PI) * radius,
			middle_z + sin((long double)current_winding_part / coil_winding_count * 2 * PI) * radius,
			0,
			(long double)current_winding_part / coil_winding_count * 2 * PI,
			sqrt(pow(((long double)radius * 2 * PI) / coil_winding_count, 2) + pow(diffx, 2)),
		};
		wire_part_vector.push_back(temp);
		std::cout << temp.x << "	" << temp.y << "	" << temp.z << "	" << temp.length << "	" << temp.rotation_x << "	" << temp.rotation_z << "\n";
	}
	return wire_part_vector;
}
