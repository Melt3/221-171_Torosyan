#include <iostream>
#include <vector>
#include <cmath>

// Функция для нахождения простых делителей числа n
std::vector<int> findPrimeFactors(int n) {
    std::vector<int> factors;

    // Проверка делимости на 2
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    // Проверка делимости на нечетные числа от 3 до sqrt(n)
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // Если после всех делений n > 2, то оно простое
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int n;
    std::cout << "Введите натуральное число больше 1: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Число должно быть больше 1." << std::endl;
        return 1;
    }

    std::vector<int> factors = findPrimeFactors(n);

    std::cout << "Простые делители числа " << n << ": ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
