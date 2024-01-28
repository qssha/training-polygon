#include <iostream>

template <class T>
void foo(T a, T b)
{
    std::cout << "same types" << std::endl;
}

template <class T, class V>
void foo(T a, V b)
{
    std::cout << "different types" << std::endl;
}

template<>
void foo<int, int>(int a, int b)
{
    std::cout << "both parameters are int" << std::endl;
}

int main(int argc, char *argv[])
{
    foo(3, 4);
    return 0;
}
