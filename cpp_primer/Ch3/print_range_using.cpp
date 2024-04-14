#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    int first_number = 0, second_number = 0;

    cout << "Enter two numbers, second number must be equal or greater "
                 "than first"
              << endl;
    cin >> first_number >> second_number;

    if (first_number > second_number) {
        cout << "First number greater than second. Exit" << endl;
    } else {
        while (first_number <= second_number) {
            cout << first_number++ << endl;
        }
    }
    return 0;
}
