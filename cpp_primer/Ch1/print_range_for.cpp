#include <iostream>

int main(int argc, char *argv[]) {
    int first_number = 0, second_number = 0;
    std::cout << "Enter two numbers, second number must be equal or greater "
                 "than first"
              << std::endl;
    std::cin >> first_number >> second_number;

    if (first_number > second_number) {
        std::cout << "First number greater than second. Exit" << std::endl;
    } else {
        for (int i = first_number; i <= second_number; ++i) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
