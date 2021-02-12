#include "B_Vektor.h"
#include "Constants.h"
#include <future>

Vektor B_Vektor::vektor(std::vector<wire_part>* parts_pointer, long double x, long double y, long double z)
{
	Vektor gesamt = { 0,0,0 };


	for (const wire_part& part : *parts_pointer) {
		Vektor diff = {
			(x - part.x) ,
			(y - part.y) ,
			(z - part.z) ,
		};
		long double r = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));
		Vektor kreuzvektor = {
			(4 * PI) * (part.wirepart_y * diff.z - part.wirepart_z * diff.y) / pow(r, 3) ,
			(4 * PI) * (part.wirepart_z * diff.x - part.wirepart_x * diff.z) / pow(r, 3) ,
			(4 * PI) * (part.wirepart_x * diff.y - part.wirepart_y * diff.x) / pow(r, 3) ,
		};
		gesamt.x += kreuzvektor.x; gesamt.y += kreuzvektor.y; gesamt.z += kreuzvektor.z;
	}
	return gesamt;
}