#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item item, temp_item;
    while (std::cin >> temp_item) {
        item += temp_item;
    }
    std::cout << item << std::endl;
    return 0;
}
