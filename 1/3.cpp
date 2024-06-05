#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void selectionSort(std::vector<std::string>& arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < arr.size(); j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

int main() {
    std::vector<std::string> phones = {"23-45-67", "12-34-56", "98-76-54", "55-55-55"};

    std::cout << "Исходный список телефонов: ";
    for (const auto& phone : phones) {
        std::cout << phone << " ";
    }
    std::cout << std::endl;

    selectionSort(phones);

    std::cout << "Отсортированный список телефонов: ";
    for (const auto& phone : phones) {
        std::cout << phone << " ";
    }
    std::cout << std::endl;

    return 0;
}
