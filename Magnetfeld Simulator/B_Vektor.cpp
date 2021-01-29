#include "B_Vektor.h"
#include "Constants.h"


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
		Vektor wirepart = { //berechnet den Vektor des Kabelabschnittes - frag mich nicht, wie
			part.length * cos(part.rotation_z) * sin(part.rotation_x),
			part.length * sin(part.rotation_z),
			part.length * cos(part.rotation_z) * cos(part.rotation_x),
		};
		Vektor kreuzvektor = {
			(4 * PI) * (wirepart.y * diff.z - wirepart.z * diff.y) / pow(r, 3) ,
			(4 * PI) * (wirepart.z * diff.x - wirepart.x * diff.z) / pow(r, 3) ,
			(4 * PI) * (wirepart.x * diff.y - wirepart.y * diff.x) / pow(r, 3) ,
		};

		//std::cout << part.x << "  " << part.y << "  " << part.z << "\n";
		//std::cout << wirepart.x << "  " << wirepart.y << "  " << wirepart.z << "\n";
		//std::cout << diff.x << "  " << diff.y << "  " << diff.z << "\n";
		//std::cout << kreuzvektor.x << "  " << kreuzvektor.y << "  " << kreuzvektor.z << "\n";

		gesamt.x += kreuzvektor.x; gesamt.y += kreuzvektor.y; gesamt.z += kreuzvektor.z;
	}


	return gesamt;
}
