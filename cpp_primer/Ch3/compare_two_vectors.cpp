#include <iostream>
#include <vector>

bool is_two_vectors_equal(const std::vector<int>& first_vec, const std::vector<int>& second_vec) {
    if (first_vec.size() != second_vec.size()) {
        return false;
    }

    for (size_t i = 0; i < first_vec.size(); ++i) {
        if (first_vec[i] != second_vec[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    constexpr size_t vec_size = 3;
    std::vector<int> first_vec(vec_size), second_vec(vec_size);
    
    std::cout << is_two_vectors_equal(first_vec, second_vec) << std::endl;

    first_vec[0] = 1;
    std::cout << is_two_vectors_equal(first_vec, second_vec) << std::endl;

    return 0;
}
