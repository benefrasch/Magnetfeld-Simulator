#include <Windows.h>
#include <iostream>
#include "Wire_parts.h"
#include "Constants.h"
#include "Plotting.h"

#include "B_Vektor.h"

int main() {

	//std::vector<wire_part> parts = Wire_parts::ring(radius);
	std::vector<wire_part> parts = Wire_parts::coil(radius, coil_total_length, coil_winding_count);

	auto start = std::chrono::high_resolution_clock::now();

	//Plotting::plotLines(&parts);
	//Plotting::plotField(&parts);

	// middle vs. end of coil
	//std::vector<long double> b_vektor1 = B_Vektor::vektor(&parts, 0.5, 0.5, 0.5);
	//std::cout << b_vektor1[0] << "\n";
	//std::vector<long double> b_vektor2 = B_Vektor::vektor(&parts, 0.3, 0.5, 0.5);
	//std::cout << b_vektor2[0] << "\n"; 

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "all done! Only took " << (int)elapsed.count() << " seconds.";
}