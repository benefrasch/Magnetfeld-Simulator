#pragma once
#include <vector>
struct wire_part
{
	float x;
	float y;
	float z;
	float rotation_x;
	float rotation_y;
	float rotation_z;
	float length;
};

static class Wire_parts {

public:
	static std::vector<wire_part> ring();
};