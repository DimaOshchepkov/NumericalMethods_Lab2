#pragma once

#include "SolvingMethodOfReverseMatrix.h"

#include <vector>
class GetterOfReverseMatrix
{
private:
	SolvingMethodOfReverseMatrix* solvingMethod;
	std::vector<std::vector<double>> matrix;

public:
	GetterOfReverseMatrix(SolvingMethodOfReverseMatrix* solvingMethod,
		std::initializer_list<std::initializer_list<double>> matrix = {}) :
		solvingMethod(solvingMethod)
	{
		for (auto row : matrix)
			this->matrix.push_back(row);
	}
	GetterOfReverseMatrix(SolvingMethodOfReverseMatrix* solvingMethod, int x, int y) :
		matrix(x, std::vector<double>(y)),
		solvingMethod(solvingMethod) {}

	~GetterOfReverseMatrix()
	{
		delete solvingMethod;
	}

	void SetStrategy(SolvingMethodOfReverseMatrix* solvingMethod)
	{
		if (this->solvingMethod != nullptr)
			delete this->solvingMethod;
		this->solvingMethod = solvingMethod;
	}
	void SetMatrix(std::vector<std::vector<double>> matrix)
	{
		this->matrix = matrix;
	}

	std::vector<std::vector<double>> GetReverseMatrix()
	{
		return solvingMethod->GetReverseMatrix(matrix);
	}
};

