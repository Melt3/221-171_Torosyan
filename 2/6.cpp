#include <iostream>

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}

int main() {
    int N;
    std::cout << "Введите натуральное число: ";
    std::cin >> N;

    std::cout << "Сумма цифр числа " << N << " равна " << sumOfDigits(N) << std::endl;

    return 0;
}
