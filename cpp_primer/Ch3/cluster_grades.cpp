#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned> grades(11, 0);
    unsigned grade;

    while (std::cin >> grade) {
        if (grade <= 100) {
            ++(*(grades.begin() + grade / 10));
        }
    }

    for (auto& cluster_grade : grades) {
        std::cout << cluster_grade << " ";
    }

    std::cout << std::endl;

    return 0;
}
