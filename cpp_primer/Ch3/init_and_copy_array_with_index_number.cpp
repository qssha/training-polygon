#include <iostream>

int main() {
    constexpr size_t array_len = 10;
    int number_arr[array_len] = {};
    int number_arr_copy[array_len] = {};

    for (size_t i = 0; i < array_len; ++i) {
        number_arr[i] = i;
    }

    for (size_t i = 0; i < array_len; ++i) {
        number_arr_copy[i] = number_arr[i];
    }


    for (auto& number : number_arr) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    for (auto& number : number_arr_copy) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
