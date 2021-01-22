#include "B_Vektor.h"
#include "Wire_parts.h"
#include <vector>
#include "Constants.h"
#include <math.h>
#include <iostream>

Vektor B_Vektor::vektor(float x, float y, float z)
{
	std::vector<wire_part> parts = Wire_parts::ring();
	for (int current_part = 0; current_part < simulation_wire_parts_count; ++current_part) {
		wire_part part = parts[current_part];
		//std::cout << part.x << "   " << part.y << "   " << part.z << "\n";
		//bmp.set_pixel(part.y * (image_size_x / simulation_size_y), part.z * (image_size_y / simulation_size_z), 255, 255, 255, 255);

		Vektor diff = { x - part.x, y - part.y , z - part.z };
		float r = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));









		//Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm 
		//float dx = diffx, dy = diffy, dz = diffz;
		//dx = sin(asin(dx / r) - part.rotation_y) * r; //effect of y rotation axis to x value
		//dx = sin(asin(dx / r) - part.rotation_z) * r; //effect of z rotation axis to x value
		//dy = sin(asin(dy / r) - part.rotation_x) * r; //effect of x rotation axis to y value
		//dy = sin(asin(dy / r) - part.rotation_z) * r; //effect of z rotation axis to y value
		//dz = sin(asin(dz / r) - part.rotation_x) * r; //effect of x rotation axis to z value
		//dz = sin(asin(dz / r) - part.rotation_y) * r; //effect of y rotation axis to z value	
		//std::cout << dx << "  " << dy << "  " << dz << "\n";


	}

	return Vektor{ 1,2,3 };
}
