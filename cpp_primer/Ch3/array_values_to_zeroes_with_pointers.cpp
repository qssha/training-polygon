#include <iostream>

int main() {
    constexpr size_t arr_size = 3;
    int arr[arr_size] = {1, 2, 3};

    for (size_t i = 0; i < arr_size; ++i) {
        *(arr + i) = 0;
    }

    for (auto& number : arr) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
