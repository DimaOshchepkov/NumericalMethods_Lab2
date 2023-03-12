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
    for (auto el : vec)
        os << el << ' ';
    return os << '\n';
}

int main()
{
    SolverOfSLE* solver = new SolverOfSLE(new SolvingByGaussMethod(),
        {
            {4, -5, 2, 1},
            {3, -3, 2, 2},
            {2, -3, 1, 3},
        }
    );
    std::cout << solver->GetDeterminant() << '\n';
    std::cout << solver->GetSolve() << '\n';

    std::cout << "------------------------------------\n";

    solver->SetStrategy(new SolverByGaussMethodWithMainElem());
    solver->SetMatrix({
            {4, -5, 2, 1},
            {3, -3, 2, 2},
            {2, -3, 1, 3},
        });

    std::cout << solver->GetDeterminant() << '\n';
    std::cout << solver->GetSolve() << '\n';

    std::cout << "------------------------------------\n";

    GetterOfReverseMatrix* getterReverseMatrix = new GetterOfReverseMatrix(new SolvingByMethodOfElementaryTransformations(),
        {
            {4, -5, 2, 1},
            {3, -3, 2, 2},
            {2, -3, 1, 3},
        });
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
