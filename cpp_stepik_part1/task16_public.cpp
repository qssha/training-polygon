#include <iostream>

struct Cls {
    Cls(char c, double d, int  i) : c(c), d(d), i(i)
    {}
                                  
    public:
        char c;
        double d;
        int i;
};




int main(int argc, char *argv[])
{
    Cls test('b', 3.2, 1313333);

    std::cout << &(test.c) << std::endl;
    std::cout << &(test.d) << std::endl;
    std::cout << &(test.i) << std::endl;

    std::cout << "#####" << std::endl;
    std::cout << (double*)(&test) + 1 << std::endl;
    std::cout << (int*)(&test) + 4  << std::endl;

   
    return 0;
}
   
