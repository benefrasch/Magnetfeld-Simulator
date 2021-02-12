#pragma once
#include <vector>
struct wire_part
{
	long double x;
	long double y;
	long double z;
	long double wirepart_x;
	long double wirepart_y;
	long double wirepart_z;
};

static class Wire_parts {

public:
	static std::vector<wire_part> ring(float radius);
	static std::vector<wire_part> coil(float radius, float coil_total_length, int coil_winding_count);
};