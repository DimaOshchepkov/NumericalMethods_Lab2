#pragma once
#include "SolvingMethod.h"
#include <vector>

class SolverOfSLE
{
private:
	SolvingMethod* solvingMethod;
	std::vector<std::vector<double>> matrix;

public:
	SolverOfSLE(SolvingMethod* solvingMethod,
			std::initializer_list<std::initializer_list<double>> matrix = {}) :
			solvingMethod(solvingMethod)
	{
		for (auto row : matrix)
			this->matrix.push_back(row);
	}
	SolverOfSLE(SolvingMethod* solvingMethod, int x, int y) :
			matrix(x, std::vector<double>(y)),
			solvingMethod(solvingMethod) {}

	~SolverOfSLE() 
	{ 
		delete solvingMethod;
	}

	void SetStrategy(SolvingMethod* solvingMethod)
	{
		if (this->solvingMethod != nullptr)
			delete this->solvingMethod;
		this->solvingMethod = solvingMethod;
	}
	void SetMatrix(std::vector<std::vector<double>> matrix)
	{
		this->matrix = matrix;
	}
	double GetDeterminant()
	{
		return solvingMethod->GetDeterminant(matrix);
	}
	
	std::vector<double> GetSolve()
	{
		return solvingMethod->GetSolve(matrix);
	}
};

