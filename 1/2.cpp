#include <iostream>
#include <cstdlib>
#include <ctime>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int max_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;
        std::swap(arr[max_idx], arr[i]);
    }
}

int main() {
    srand(time(0));

    const int n = 10;
    int arr[n];

    // Заполняем массив случайными числами в интервале [0, 100]
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
