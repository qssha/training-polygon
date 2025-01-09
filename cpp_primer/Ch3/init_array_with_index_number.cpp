#include <iostream>

int main() {
    constexpr size_t array_len = 10;
    int number_arr[array_len] = {};

    for (size_t i = 0; i < array_len; ++i) {
        number_arr[i] = i;
    }

    for (auto& number : number_arr) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
