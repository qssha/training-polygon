#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {
    String(size_t n, char c) : size(n)  {
        this->str = new char[n + 1];

        for (size_t i = 0; i < n; i++) {
            this->str[i] = c;
        }

        this->str[n] = '\0';
    }

    ~String() {
        delete [] this->str;
    }


	size_t size;
	char *str;
};

int main(int argc, char *argv[])
{
    String mystr(3, '\0');

    std::cout << mystr.str << std::endl;
    
    return 0;
}
