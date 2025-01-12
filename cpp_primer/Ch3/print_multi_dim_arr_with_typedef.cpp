#include <iostream>
#include <iterator>

int main() {
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    using const_ref_int_array = int(&)[4];
    using const_ref_int = const int&;

    for (const_ref_int_array col : ia) {
        for (const_ref_int row : col) {
            std::cout << row << " ";
        }
        std::cout << std::endl;
    }

    constexpr const size_t rowCnt = 3, colCnt = 4;
    using index_type = size_t;

    for (index_type i = 0; i != rowCnt; ++i) {
        for (index_type j = 0; j != colCnt; ++j) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    using pointer_to_int_arr = int(*)[4];
    using pointer_to_arr_elem = int*;

    for (pointer_to_int_arr row = ia; row != ia + 3; ++row) {
        for (pointer_to_arr_elem col = *row; col != *row + 4; ++col) {
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
