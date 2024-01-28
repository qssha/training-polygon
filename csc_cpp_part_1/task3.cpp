#include <iostream>

unsigned gcd(unsigned a, unsigned b)
{
    return !b ? a : gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    std::cout << gcd(18, 6) << std::endl;
    return 0;
}

