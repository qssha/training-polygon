#include <iostream>

struct Cls {
    Cls(char c, double d, int  i) : c(c), d(d), i(i)
    {}
                                  
    private:
        char c;
        double d;
        int i;
};

char &get_c(Cls &cls) {
    return *((char*)&cls);
}

double &get_d(Cls &cls) {
    return *((double*)(&cls) + 1);
}

int &get_i(Cls &cls) {
    return *((int*)(&cls) + 4);
}

int main(int argc, char *argv[])
{
    Cls test('a', 3.2, 131);

    std::cout << get_c(test) << std::endl;
    std::cout << get_d(test) << std::endl;
    std::cout << get_i(test)  << std::endl;

    return 0;
}
