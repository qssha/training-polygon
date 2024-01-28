#include <iostream>

int main(int argc, char *argv[]) {
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int count = 1;
        while (std::cin >> val) {
            if (val == currVal) {
                ++count;
            } else {
                std::cout << currVal << " occurs " << count
                          << (count == 1 ? " time" : " times") << std::endl;
                currVal = val;
                count = 1;
            }
        }
        std::cout << currVal << " occurs " << count << " times" << std::endl;
    }
    return 0;
}
