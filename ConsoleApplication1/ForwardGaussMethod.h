#pragma once

#include <vector>
class ForwardGaussMethod
{
public:
	void Apply(std::vector<std::vector<double>>& matrix)
	{
		for (int i = 0; i < matrix.size(); i++)
			for (int j = i + 1; j < matrix.size(); j++)
				RowXMinusYWithCoef(j, i, matrix[j][i] / matrix[i][i], matrix);
	}

	void ApplyBack(std::vector<std::vector<double>>& matrix)
	{
		for (int i = matrix.size() - 1; i >= 0; i--)
			for (int j = i - 1; j >= 0; j--)
				RowXMinusYWithCoef(j, i, matrix[j][i] / matrix[i][i], matrix);
	}

private:
	void RowXMinusYWithCoef(int x, int y, double coef,
			std::vector<std::vector<double>>& matrix)
	{
		for (int i = 0; i < matrix.back().size(); i++)
			matrix[x][i] -= coef * matrix[y][i];
	}
};

