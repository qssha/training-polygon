#include <iostream>

void swap_numbers(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main(int argc, char* argv[]) {
    int first_number = 0, second_number = 0;

    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> first_number >> second_number;

    if (first_number > second_number)
        swap_numbers(&first_number, &second_number);
    while (first_number <= second_number) {
        std::cout << first_number++ << std::endl;
    }
    return 0;
}
