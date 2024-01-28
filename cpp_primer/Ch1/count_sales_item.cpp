#include <iostream>
#include "Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item currItem, nextItem;

    if (std::cin >> currItem) {
        int count = 1;
        while (std::cin >> nextItem) {
            if (currItem.isbn() == nextItem.isbn()) {
                count++;
            } else {
                std::cout << currItem.isbn() << " " << count << std::endl;
                currItem = nextItem;
                count = 1;
            }
        }
        std::cout << currItem.isbn() << " " << count << std::endl;
    }

    return 0;
}
