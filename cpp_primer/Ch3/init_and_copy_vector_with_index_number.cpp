#include <iostream>
#include <vector>

int main() {
    size_t vector_len = 10;
    std::vector<int> number_vec(vector_len), number_vec_copy(vector_len);

    for (size_t i = 0; i < number_vec.size(); i++) {
        number_vec[i] = i;
    }

    for (size_t i = 0; i < number_vec_copy.size(); i++) {
        number_vec_copy[i] = number_vec[i];
    }

    for (auto& number : number_vec) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    for (auto& number : number_vec_copy) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
