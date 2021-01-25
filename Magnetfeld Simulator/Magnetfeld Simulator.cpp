#include <iostream>
#include <tuple>
#include "BMP.h"
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "Constants.h"


static BMP bmp(image_size_x, image_size_y, false);

int main()
{

	long double x = 0.5, 
				y = 0.5;

	bmp.set_pixel((simulation_size_x / 2)*(image_size_x / simulation_size_x), (long float)(simulation_size_y / 2 - radius)*(image_size_y / simulation_size_y), 255, 0, 0, 255);
	bmp.set_pixel((simulation_size_x / 2)*(image_size_x / simulation_size_x), (long float)(simulation_size_y / 2 + radius)*(image_size_y / simulation_size_y), 255, 0, 0, 255);

	std::vector<wire_part> parts = Wire_parts::ring();
	for (int i = 0; i < 10000; ++i) {
		Vektor b_vektor = B_Vektor::vektor(&parts,x, y, simulation_size_z/2);
		x += b_vektor.x; y += b_vektor.y;
		bmp.set_pixel(x * (image_size_x / simulation_size_x), y * (image_size_y / simulation_size_y), 255, 255, 255, 255);
		//std::cout << "\n" << b_vektor.x << "	" << b_vektor.y << "	" << b_vektor.z << "		" << x << "	" << y;
	}
	bmp.write("output.bmp");

	
}

