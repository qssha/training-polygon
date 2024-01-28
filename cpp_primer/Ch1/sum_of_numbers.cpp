#include <iostream>

int main(int argc, char *argv[]) {
    int value = 0, sum = 0;
    std::cout << "Enter numbers to sum:" << std::endl;

    while (std::cin >> value) {
        sum += value;
    }

    std::cout << "Sum of numbers is " << sum << std::endl;

    return 0;
}
