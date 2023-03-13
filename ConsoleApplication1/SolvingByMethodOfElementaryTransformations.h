#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <typeinfo>

#include "SolvingMethodOfReverseMatrix.h"
#include "ForwardGaussMethod.h"
#include "TransfmationAccordingToPrincipalElements.h"
class SolvingByMethodOfElementaryTransformations :
    public SolvingMethodOfReverseMatrix
{
public:
    std::vector<std::vector<double>> GetReverseMatrix(std::vector<std::vector<double>> matrix) override
    {
        if (GetDeterminant(matrix) != 0)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                std::vector<double> v(matrix[i].size() - 1);
                v[i] = 1;
                matrix[i].insert(matrix[i].end(), v.begin(), v.end());
            }
            transfmationAccordingToPrincipalElements.Apply(matrix);
            forwardGaussMethod.Apply(matrix);
            forwardGaussMethod.ApplyBack(matrix);

            for (int i = 0; i < matrix.size(); i++)
            {
                MultiplyRowByCoef(matrix, i, 1 / matrix[i][i]);
            }

            std::vector<std::vector<double>> reverseMatrix(matrix.size());
            for (int i = 0; i < matrix.size(); i++)
            {
                std::copy(std::next(matrix[i].begin(), matrix.size() + 1), matrix[i].end(),
                    std::back_inserter(reverseMatrix[i]));
            }
            return reverseMatrix;
        }
        else
        {
            std::cout << "Determinant eqval zero\n";
            return {};
        }
        
    }
private:
    void MultiplyRowByCoef(std::vector<std::vector<double>>& matrix, int row, double coef)
    {
        for (double& el : matrix[row])
            el = el * coef;
    }
    double GetDeterminant(std::vector<std::vector<double>> matrix)
    {
        double determinant = 1;
        transfmationAccordingToPrincipalElements.Apply(matrix);
        forwardGaussMethod.Apply(matrix);
        for (int i = 0; i < matrix.size(); i++)
            determinant *= matrix[i][i];

        if (typeid(determinant).name() == "double")
            return determinant;
        else return 0;
    }
    TransfmationAccordingToPrincipalElements transfmationAccordingToPrincipalElements;
    ForwardGaussMethod forwardGaussMethod;
};

