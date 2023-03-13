#pragma once
#include "SolvingMethod.h"
#include "ForwardGaussMethod.h"
#include "ReverseGaussMethod.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include <algorithm>

class SolvingByGaussMethod : public SolvingMethod
{
public:
	std::vector<double> GetSolve(std::vector<std::vector<double>> matrix) override
	{
		if (GetDeterminant(matrix) != 0)
		{
			forwardGaussMethod.Apply(matrix);
			return reverseGaussMethod.Apply(matrix);
		}
		else
		{

		}
		std::any_of(matrix.begin(), matrix.end(),
			[](const auto& vec)
			{
				return std::all_of(vec.begin(), vec.end(),
					[](const auto& el)
					{
						return el == 0;
					});
			})////////////
	}

	double GetDeterminant(std::vector<std::vector<double>> matrix) override
	{
		double determinant = 1;
		forwardGaussMethod.Apply(matrix);
		for (int i = 0; i < matrix.size(); i++)
			determinant *= matrix[i][i];

		if (typeid(determinant).name() == "double")
			return determinant;
		else
			return 0;
	}
	
private:

	ReverseGaussMethod reverseGaussMethod;
	ForwardGaussMethod forwardGaussMethod;
};

