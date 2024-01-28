#include <iostream>
#include <typeinfo>

int main() {
    auto literal = 3.14L;

    std::cout << typeid(literal).name() << std::endl;

    return 0;
}
