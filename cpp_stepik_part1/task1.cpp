#define MAX(x, y, r) /* присваивает r максимум из x и y */ { \
    int xmac = x; \
    int ymac = y; \
    int rmac = r; \
    (rmac) = (xmac) > (ymac) ? (xmac) : (ymac); \
    r = rmac; \
    }

#include <iostream>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a, b, c); // теперь c равно 20
    std::cout << a << " " << b << " " << c << std::endl;
    MAX(a += b, b, c); // теперь a = с = 30 

    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}
