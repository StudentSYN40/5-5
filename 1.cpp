#include <iostream>
#include <iomanip>


int main()
{
    int rows, cols;
    std::cout << "rows = ";
    std::cin >> rows;

    std::cout << "cols = ";
    std::cin >> cols;

    int **mas = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        mas[i] = new int[cols];
    }

    std::cout << "\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "rows[" << i + 1 << "] cols[" << j + 1 << "] = ";
            std::cin >> mas[i][j];
        }
    }

    std::cout << "\nOriginal matrix:\n\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::setw(4) << mas[i][j];
        }
        std::cout << "\n";
    }

    int min_size = std::min(rows, cols); // находим минимальный размер для инвертирования матрицы

    for (int i = 0; i < min_size; i++) // проходим по диагонали матрицы
    {
        for (int j = i; j < min_size; j++)
        {
            int temp = mas[i][j];
            mas[i][j] = mas[j][i];
            mas[j][i] = temp;
        }
    }

    std::cout << "\nInverted matrix:\n\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::setw(4) << mas[i][j];
        }
        std::cout << "\n";
    }

    // освобождаем память
    for (int i = 0; i < rows; i++)
    {
        delete[] mas[i];
    }

    delete[] mas;

    return 0;
}