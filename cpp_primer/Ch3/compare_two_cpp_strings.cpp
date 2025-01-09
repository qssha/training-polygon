#include <iostream>
#include <string>

bool is_two_cpp_strings_equal(const std::string& first_str, const std::string& second_str) {
    if (first_str.size() != second_str.size()) {
        return false;
    }

    for (size_t i = 0; i < first_str.size(); ++i) {
        if (first_str[i] != second_str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string first_str = "string", second_str = "string";

    std::cout << is_two_cpp_strings_equal(first_str, second_str) << std::endl;
    std::cout << is_two_cpp_strings_equal("", "") << std::endl;

    first_str[0] = 'S';
    std::cout << is_two_cpp_strings_equal(first_str, second_str) << std::endl;

    return 0;
}
