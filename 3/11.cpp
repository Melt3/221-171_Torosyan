#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

struct Student {
    char name[50];
};

int compareStudents(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int main() {
    std::vector<Student> students = {
        {"John"},
        {"Alice"},
        {"Bob"},
        {"Charlie"},
        {"David"}
    };

    // Сортировка студентов по именам
    qsort(students.data(), students.size(), sizeof(Student), compareStudents);

    // Вывод отсортированного списка студентов
    for (const auto& student : students) {
        std::cout << student.name << std::endl;
    }

    return 0;
}
