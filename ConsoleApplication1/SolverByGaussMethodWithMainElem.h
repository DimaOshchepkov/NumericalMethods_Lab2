#pragma once

#include <iostream>
#include "SolvingMethod.h"
#include "ForwardGaussMethod.h"
#include "ReverseGaussMethod.h"
#include "TransfmationAccordingToPrincipalElements.h"

class SolverByGaussMethodWithMainElem : public SolvingMethod
{
public:
	std::vector<double> GetSolve(std::vector<std::vector<double>> matrix) override
	{
		if (GetDeterminant(matrix) == 0)
		{
			std::cout << "Determinate equval zero\n";
			return {};
		}
		forwardGaussMethod.Apply(matrix);
		return reverseGaussMethod.Apply(matrix);
	}

	double GetDeterminant(std::vector<std::vector<double>> matrix) override
	{
		double determinant = 1;
		transfmationAccordingToPrincipalElements.Apply(matrix);
		forwardGaussMethod.Apply(matrix);
		for (int i = 0; i < matrix.size(); i++)
			determinant *= matrix[i][i];

		return determinant;
	}
private:

	TransfmationAccordingToPrincipalElements transfmationAccordingToPrincipalElements;
	ReverseGaussMethod reverseGaussMethod;
	ForwardGaussMethod forwardGaussMethod;
};

