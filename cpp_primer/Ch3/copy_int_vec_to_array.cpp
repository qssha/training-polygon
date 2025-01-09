#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_vec{1, 2, 3, 4, 5};
    constexpr size_t int_arr_len = 5;
    int int_arr[int_arr_len];

    for (size_t i = 0; i < int_arr_len; ++i) {
        int_arr[i] = int_vec[i]; 
    }

    for (size_t i = 0; i < int_arr_len; ++i) {
        std::cout << int_arr[i] << " "; 
    }
    std::cout << std::endl;

    return 0;
}
