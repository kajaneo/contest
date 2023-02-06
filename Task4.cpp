#include <iostream>

/*Объявить и заполнить двумерный динамический массив случайными числами от 1 до 70.
Показать его на экран. Для заполнения и показа на экран написать отдельные функции.
 (подсказка: функции должны принимать три параметра – указатель на динамический массив,
 количество строк, количество столбцов). Количество строк и столбцов выбирает пользователь.
Ннаписать функцию, которая вычисляет сумму элементов, расположенных на побочной диагонали матрицы. */
void full(int r, int c, int** matrix) { //функция рандомного заполнения матрицы поэлементно
    srand((unsigned)time(NULL));
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            matrix[i][j] = 1 + rand() % 70;
        }
    }
}

void print(int r, int c, int** matrix){ //функция вывода матрицы
    srand((unsigned)time(NULL));
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            std::cout << matrix[i][j]<< " ";
        }
        std::cout << std::endl;
    }
}

double summ(int r, int c, int** matrix){ //функция подсчета суммы побочной диагонали
    int summ = 0;
    for (int i = 0; i < r; ++i) {
        summ += matrix[i][r - 1 - i];
    }
    std::cout << "Сумма побочной диагонали равна: " << summ;
}

int main() {
    setlocale(LC_ALL, "RU");
    int row, column;
    std::cout << "Введите количество строк матрицы: "<< std::endl;
    std::cin >> row;
    std::cout << "Введите количество столбцов матрицы: "<< std::endl;
    std::cin >> column;
    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new int[column];
    }

    full(row, column, matrix);
    print(row, column, matrix);
    summ(row, column, matrix);

    for (int i = 0; i < column; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
