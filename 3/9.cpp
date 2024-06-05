#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void quickSort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main() {
    std::srand(std::time(0));
    const int SIZE = 1000;
    std::vector<int> arr(SIZE);

    // Заполнение массива случайными числами от 50 до 100
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = 50 + std::rand() % 51;
    }

    // Сортировка массива
    quickSort(arr, 0, SIZE - 1);

    // Вывод отсортированного массива
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
