#include <iostream>

void recursive_print() {
    int n;
    std::cin >> n;

    if (n != 0) {
        recursive_print();
        std::cout << n << " ";
    }
}

int main(int argc, char *argv[])
{
    recursive_print();
    return 0;
}
