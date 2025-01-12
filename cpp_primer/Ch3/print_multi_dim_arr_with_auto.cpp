#include <iostream>
#include <iterator>

int main() {
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    for (const auto& row : ia) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    constexpr const auto rowCnt = static_cast<size_t>(3), colCnt = static_cast<size_t>(4);

    for (auto i = static_cast<size_t>(0); i != rowCnt; ++i) {
        for (auto j = static_cast<size_t>(0); j != colCnt; ++j) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (auto row = ia; row != ia + 3; ++row) {
        for (auto col = *row; col != *row + 4; ++col) {
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
