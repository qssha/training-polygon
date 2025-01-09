#include <iostream>
#include <vector>
#include <iterator>

int main() {
    int int_arr[] = {1, 2, 3, 4, 5};
    std::vector<int> int_vec(std::begin(int_arr), std::end(int_arr));

    for (auto& number : int_vec) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
