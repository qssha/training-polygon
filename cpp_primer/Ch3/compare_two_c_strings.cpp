#include <iostream>
#include <cstring>

bool is_two_c_strings_equal(const char* first_str, const char* second_str) {
    while (*first_str || *second_str) {
        if (*first_str != *second_str) {
            return false;
        }
        ++first_str;
        ++second_str;
    }

    return *first_str == *second_str ? true : false;
}

int main() {
    const char* first_str = "cstring";
    const char* second_str = "cstring";

    std::cout << is_two_c_strings_equal(first_str, second_str) << std::endl;
    std::cout << is_two_c_strings_equal("", "") << std::endl;

    second_str = "string";
    std::cout << is_two_c_strings_equal(first_str, second_str) << std::endl;
    std::cout << is_two_c_strings_equal(second_str, first_str) << std::endl;
    std::cout << is_two_c_strings_equal(first_str, "") << std::endl;
    std::cout << is_two_c_strings_equal("", second_str) << std::endl;

    return 0;
}
