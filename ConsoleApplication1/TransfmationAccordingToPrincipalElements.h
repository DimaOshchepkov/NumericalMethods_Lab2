#pragma once
#include <vector>
#include <algorithm>

class TransfmationAccordingToPrincipalElements
{
public:
	void Apply(std::vector<std::vector<double>>& matrix)
	{
		std::vector<double> maxElements;
		for (int i = 0; i < matrix.size(); i++)
			matrix[i].push_back(*std::max_element(matrix[i].begin(), matrix[i].end()));

		std::sort(matrix.begin(), matrix.end(),
			[](const std::vector<double>& a, const std::vector<double>& b)
			{
				return a.back() < b.back();
			});
		for (auto& vec : matrix)
			vec.pop_back();
	}
};

