#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::unordered_set<int> numbers;
    int num;

    while (input >> num) {
        if (num > 0) {
            numbers.insert(num);
        } else if (num < 0) {
            numbers.erase(-num);
        } else if (num == 0) {
            std::vector<int> sorted_numbers(numbers.begin(), numbers.end());
            std::sort(sorted_numbers.begin(), sorted_numbers.end());

            for (const int& n : sorted_numbers) {
                output << n << " ";
            }
            output << std::endl;
            break;
        }
    }

    input.close();
    output.close();

    return 0;
}
