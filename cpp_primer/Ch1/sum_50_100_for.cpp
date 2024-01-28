#include <iostream>

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 1; i <= 50; ++i) {
        sum += i;
    }

    std::cout << "Sum of 1 to 50 inclusive is " << sum << std::endl;

    return 0;
}
