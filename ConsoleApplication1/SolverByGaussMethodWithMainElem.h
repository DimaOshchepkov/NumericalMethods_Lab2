#pragma once

#include <iostream>
#include <typeinfo>
#include "SolvingMethod.h"
#include "ForwardGaussMethod.h"
#include "ReverseGaussMethod.h"
#include "TransfmationAccordingToPrincipalElements.h"

class SolverByGaussMethodWithMainElem : public SolvingMethod
{
public:
	std::vector<double> GetSolve(std::vector<std::vector<double>> matrix) override
	{
		transfmationAccordingToPrincipalElements.Apply(matrix);
		forwardGaussMethod.Apply(matrix);
		if (GetDeterminant(matrix) != 0)
			return reverseGaussMethod.Apply(matrix);
		else
		{
			for (int i = matrix.size() - 1; i >= 0; i--)
				if (matrix[i][matrix.size()] != 0 &&
					std::all_of(matrix[i].begin(), std::next(matrix[i].begin(), matrix.size() - 1),
						[](const auto& el)
						{
							return el == 0;
						}))
				{
					std::cout << "No solution" << std::endl;
					return {};
				}

				std::cout << "Endlessly solution\n";
				return {};
		}
	}



	double GetDeterminant(std::vector<std::vector<double>> matrix) override
	{
		double determinant = 1;
		forwardGaussMethod.Apply(matrix);
		for (int i = 0; i < matrix.size(); i++)
			determinant *= matrix[i][i];

		if (std::isnan(determinant))
			return 0;
		else
			return determinant;
	}
private:

	TransfmationAccordingToPrincipalElements transfmationAccordingToPrincipalElements;
	ReverseGaussMethod reverseGaussMethod;
	ForwardGaussMethod forwardGaussMethod;
};

