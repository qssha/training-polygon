#include <iostream>
using namespace std;

int main()
{
    // put your code here
    int number;
    int a, b;
    cin >> number;

    for (int i = 0; i < number; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}
