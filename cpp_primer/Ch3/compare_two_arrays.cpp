#include <iostream>

bool is_arrays_equal(int* first_arr, int* second_arr, size_t arr_size) {
    for (size_t i = 0; i < arr_size; ++i) {
        if (*(first_arr + i) != *(second_arr + i)) {
            return false;
        }
    }
    return true;
}

int main() {
    constexpr size_t arr_size = 3;
    int first_arr[arr_size] = {1, 2, 3}, second_arr[arr_size] = {1, 2, 3};

    std::cout << is_arrays_equal(first_arr, second_arr, arr_size) << std::endl;

    first_arr[0] = 0;
    std::cout << is_arrays_equal(first_arr, second_arr, arr_size) << std::endl;

    return 0;
}
