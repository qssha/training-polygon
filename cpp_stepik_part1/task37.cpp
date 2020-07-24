#include <iostream>

template <typename T, typename V>
struct SameType
{
    static const bool value = false;
};

template <typename T>
struct SameType<T, T>
{
    static const bool value = true;
};

struct Dummy { };
typedef int type;

int main(int argc, char *argv[])
{
    std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
    std::cout << SameType<int, type>::value << std::endl; // 1, type == int
    std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
    std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
    std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа

    return 0;
}
