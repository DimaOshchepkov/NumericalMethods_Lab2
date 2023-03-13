// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SolvingByGaussMethod.h"
#include "SolvingMethod.h"
#include "SolverByGaussMethodWithMainElem.h"
#include "SolverOfSLE.h"
#include "SolvingMethodOfReverseMatrix.h"
#include "SolvingByMethodOfElementaryTransformations.h"
#include "GetterOfReverseMatrix.h"

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& vec)
{
    if (vec.empty())
        os << "{}";
    for (auto el : vec)
        os << el << ' ';
    return os << '\n';
}

std::vector<std::vector<double>> ReadMatrix()
{
    try
    {
        std::cout << "Input size\n";
        int size = 0;
        std::cin >> size;

        std::vector<std::vector<double>> matrix(size, std::vector<double>(size + 1));
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size + 1; j++)
                std::cin >> matrix[i][j];

        return matrix;
    }
    catch(...)
    {
        std::cerr << "Input error\n";
        return {};
    }
}

int main()
{
    std::cout << "Input matrix\n";
    auto matrix = ReadMatrix();

    SolverOfSLE* solver = new SolverOfSLE(new SolvingByGaussMethod());
    solver->SetMatrix(matrix);
    std::cout << solver->GetDeterminant() << '\n';
    std::cout << solver->GetSolve() << '\n';

    std::cout << "------------------------------------\n";

    solver->SetStrategy(new SolverByGaussMethodWithMainElem());

    std::cout << solver->GetDeterminant() << '\n';
    std::cout << solver->GetSolve() << '\n';

    std::cout << "------------------------------------\n";

    GetterOfReverseMatrix* getterReverseMatrix = new GetterOfReverseMatrix(new SolvingByMethodOfElementaryTransformations());
    getterReverseMatrix->SetMatrix(matrix);
    std::cout << getterReverseMatrix->GetReverseMatrix();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
