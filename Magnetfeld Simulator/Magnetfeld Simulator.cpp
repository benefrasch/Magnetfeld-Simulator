#include <iostream>
#include <tuple>
#include "BMP.h"
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "Constants.h"


static BMP bmp(image_size_x, image_size_y, false);

int main()
{

	

	bmp.write("output.bmp");
}

