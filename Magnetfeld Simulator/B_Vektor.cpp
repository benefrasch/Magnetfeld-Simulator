#include "B_Vektor.h"
#include "Constants.h"
#include <future>

std::vector<long double> B_Vektor::vektor(std::vector<wire_part>* parts_pointer, long double x, long double y, long double z)
{
	std::vector<long double> gesamt = { 0,0,0 };


	for (const wire_part& part : *parts_pointer) {
		std::vector<long double> diff = {
			(x - part.x) ,
			(y - part.y) ,
			(z - part.z) ,
		};
		long double r = sqrt(pow(diff[0], 2) + pow(diff[1], 2) + pow(diff[2], 2));
		std::vector<long double> kreuzvektor = {
			(4 * PI) * (part.wirepart_y * diff[2] - part.wirepart_z * diff[1]) / pow(r, 3) ,
			(4 * PI) * (part.wirepart_z * diff[0] - part.wirepart_x * diff[2]) / pow(r, 3) ,
			(4 * PI) * (part.wirepart_x * diff[1] - part.wirepart_y * diff[0]) / pow(r, 3) ,
		};
		gesamt[0] += kreuzvektor[0]; gesamt[1] += kreuzvektor[1]; gesamt[2] += kreuzvektor[2];
	}
	return gesamt;
}