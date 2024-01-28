#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item first_book, second_book;
    std::cin >> first_book >> second_book;
    std::cout << first_book + second_book << std::endl;
    return 0;
}
