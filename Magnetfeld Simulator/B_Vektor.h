#pragma once
#include <tuple>
#include <vector>
#include "Wire_parts.h"
#include <math.h>
#include <iostream>


static class B_Vektor
{
public:
	static std::vector<long double> vektor(std::vector<wire_part>*parts, long double x, long double y, long double z);
};

