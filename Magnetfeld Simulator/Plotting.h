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
	static void plotHeatmap(std::vector<wire_part>* parts);
};

