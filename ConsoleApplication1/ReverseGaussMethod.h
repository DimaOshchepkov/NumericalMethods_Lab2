#pragma once

#include <vector>

class ReverseGaussMethod
{
public:
	std::vector<double> Apply(const std::vector<std::vector<double>>& matrix)
	{
		std::vector<double> answer(matrix.size());
		for (int i = answer.size() - 1; i >= 0; i--)
		{
			double bi = matrix[i].back();
			for (int j = i + 1; j < matrix.size(); j++)
				bi -= matrix[i][j] * answer[j];
			answer[i] = bi / matrix[i][i];
		}

		return answer;
	}
};

