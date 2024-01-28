#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cout << "Enter two numbers:";
    std::cout << std::endl;

    std::cin >> a >> b;
    std::cout << "The product of " << a << " and " << b << " is " << a * b
              << std::endl;

    /*
    std::cout << "The product of ";
    std::cout << a;
    std::cout << " and ";
    std::cout << b;
    std::cout << " is ";
    std::cout << a * b;
    std::cout << std::endl;
    */

    return 0;
}
