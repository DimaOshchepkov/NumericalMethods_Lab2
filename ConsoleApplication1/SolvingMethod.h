#pragma once

#include <vector>

class SolvingMethod
{
public:
	virtual std::vector<double> GetSolve(std::vector<std::vector<double>> matrix) = 0;
	virtual double GetDeterminant(std::vector<std::vector<double>> matrix) = 0;
	virtual ~SolvingMethod() {}
};

