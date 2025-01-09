#include <iostream>
#include <cstring>

int main() {
    constexpr const char first_str[] = "Hello ";
    constexpr const char second_str[] = "world!";
    constexpr size_t sum_length = strlen(first_str) + strlen(second_str);
    char third_str[sum_length + 1];

    strcpy(third_str, first_str);
    strcat(third_str, second_str);

    std::cout << third_str << std::endl;

    return 0;
}
