#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void quickSortColumn(std::vector<std::vector<int>>& arr, int left, int right, int col) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2][col];

    while (i <= j) {
        while (arr[i][col] < pivot)
            i++;
        while (arr[j][col] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSortColumn(arr, left, j, col);
    if (i < right)
        quickSortColumn(arr, i, right, col);
}

int main() {
    std::srand(std::time(0));
    const int ROWS = 10;
    const int COLS = 10;
    std::vector<std::vector<int>> matrix(ROWS, std::vector<int>(COLS));

    // Заполнение матрицы случайными числами от 5 до 61
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = 5 + std::rand() % 57;
        }
    }

    // Сортировка первого столбца
    quickSortColumn(matrix, 0, ROWS - 1, 0);

    // Вывод отсортированной матрицы
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
