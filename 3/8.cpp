#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    const int SIZE = 1000;
    std::vector<int> sequence(SIZE);

    // Заполнение последовательности случайными числами
    for (int i = 0; i < SIZE; ++i) {
        sequence[i] = std::rand() % 2001 - 1000;  // Числа в диапазоне от -1000 до 1000
    }

    // Сортировка последовательности
    std::sort(sequence.begin(), sequence.end());

    // Вывод отсортированной последовательности
    for (const auto& num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
