#pragma once
#include "SolvingMethod.h"

#include <vector>
#include <iostream>

class SolverByItarationMethod : public SolvingMethod
{
	double GetDeterminant(std::vector<std::vector<double>> matrix) override
	{
		return -1;
	}
};

