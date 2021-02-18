#pragma once
#include <vector>
#include "Wire_parts.h"
#include "B_Vektor.h"
#include "BMP.h"
#include <future>
class Plotting
{
public:
	static void plotLines(std::vector<wire_part>* parts);
	static void plotField(std::vector<wire_part>* parts); //not really useful, bc. high maximum and low minimum
};

