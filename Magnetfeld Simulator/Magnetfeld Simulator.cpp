#include <iostream>
#include <tuple>
#include "BMP.h"
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "Constants.h"


static BMP bmp(image_size_x, image_size_y, false);

int main()
{

	Vektor vektor = B_Vektor::vektor(40, 40, 50);

	std::cout << "\n\n" << vektor.x << "	" << vektor.y << "	" << vektor.z << "	";

	bmp.write("output.bmp");
}

