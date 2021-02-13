#pragma once
#include <tuple>
#include <vector>
#include "Wire_parts.h"
#include <math.h>
#include <iostream>

struct Vektor
{
	double x, y, z;
};

static class B_Vektor
{
public:
	 static Vektor vektor(std::vector<wire_part>* parts,long double x, long double y, long double z);
};

