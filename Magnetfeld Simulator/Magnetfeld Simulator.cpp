#include <iostream>
#include "BMP.h"
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "Constants.h"
#include <Windows.h>
#include <future>
#include <chrono>
#include "Plotting.h"


int main() {

	//std::vector<wire_part> parts = Wire_parts::ring(radius);
	std::vector<wire_part> parts = Wire_parts::coil(radius, coil_total_length, coil_winding_count);

	auto start = std::chrono::high_resolution_clock::now();

	Plotting::plotLines(&parts);

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "all done! Only took " << (int)elapsed.count() << " seconds.";
}