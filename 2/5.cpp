#include <iostream>

void printRange(int A, int B) {
    if (A < B) {
        std::cout << A << " ";
        if (A < B - 1) {
            printRange(A + 1, B);
        }
    } else {
        std::cout << A << " ";
        if (A > B + 1) {
            printRange(A - 1, B);
        }
    }
    std::cout << B << " ";
}

int main() {
    int A, B;
    std::cout << "Введите два целых числа (A и B): " << std::endl;
    std::cin >> A >> B;

    printRange(A, B);
    std::cout << std::endl;

    return 0;
}
