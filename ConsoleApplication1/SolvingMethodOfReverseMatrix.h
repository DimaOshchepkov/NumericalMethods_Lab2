#pragma once

#include <vector>
class SolvingMethodOfReverseMatrix
{
public:
	virtual std::vector<std::vector<double>> GetReverseMatrix(std::vector<std::vector<double>> matrix) = 0;
};

