#include <iostream>
#include <iterator>

int main() {
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    for (const int (&row)[4] : ia) {
        for (const int& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    constexpr const size_t rowCnt = 3, colCnt = 4;

    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int (*row)[4] = ia; row != ia + 3; ++row) {
        for (int* col = *row; col != *row + 4; ++col) {
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
