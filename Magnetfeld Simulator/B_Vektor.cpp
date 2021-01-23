#include "B_Vektor.h"
#include "Wire_parts.h"
#include <vector>
#include "Constants.h"
#include <math.h>
#include <iostream>

Vektor B_Vektor::vektor(long double x, long double y, long double z)
{
	Vektor gesamt = {0,0,0};
	std::vector<wire_part> parts = Wire_parts::ring();
	for (int current_part = 0; current_part < simulation_wire_parts_count; ++current_part) {
		wire_part part = parts[current_part];
		//bmp.set_pixel(part.y * (image_size_x / simulation_size_y), part.z * (image_size_y / simulation_size_z), 255, 255, 255, 255);

		Vektor diff = { (x - part.x), (y - part.y) , (z - part.z) };
		long double r = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));
		Vektor wirepart = { //berechnet den Vektor des Kabelabschnittes - frag mich nicht, wie
			part.length * cos(part.rotation_z) * sin(part.rotation_x),
			part.length * sin(part.rotation_z),
			part.length * cos(part.rotation_z) * cos(part.rotation_x),
		};
		Vektor kreuzvektor = {
			(wirepart.y * diff.z - wirepart.z * diff.y)* Current* mu0,
			(wirepart.z * diff.x - wirepart.x * diff.z)* Current* mu0,
			(wirepart.x * diff.y - wirepart.y * diff.x)* Current* mu0
		};



		//std::cout << part.x << "   " << part.y << "   " << part.z << "			";
		//std::cout << diff.x << "			" << diff.y << "			" << diff.z << "			" << sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2)) << "		||	";
		//std::cout << wirepart.x << "			" << wirepart.y << "			" << wirepart.z << "			" << sqrt(pow(wirepart.x, 2) + pow(wirepart.y, 2)+ pow(wirepart.z, 2)) << "		||	";
		std::cout << kreuzvektor.x << "	" << kreuzvektor.y  << "	" << kreuzvektor.z ;
		std::cout << "\n";

		//Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm Ich bin dumm 
		//float dx = diffx, dy = diffy, dz = diffz;
		//dx = sin(asin(dx / r) - part.rotation_y) * r; //effect of y rotation axis to x value
		//dx = sin(asin(dx / r) - part.rotation_z) * r; //effect of z rotation axis to x value
		//dy = sin(asin(dy / r) - part.rotation_x) * r; //effect of x rotation axis to y value
		//dy = sin(asin(dy / r) - part.rotation_z) * r; //effect of z rotation axis to y value
		//dz = sin(asin(dz / r) - part.rotation_x) * r; //effect of x rotation axis to z value
		//dz = sin(asin(dz / r) - part.rotation_y) * r; //effect of y rotation axis to z value	
		//std::cout << dx << "  " << dy << "  " << dz << "\n";

		gesamt.x += kreuzvektor.x; gesamt.y += kreuzvektor.y; gesamt.z += kreuzvektor.z;
	}


	return gesamt;
}
