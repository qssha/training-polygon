#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {
    String(const char *str = "") : size(strlen(str)) {
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

	size_t size;
	char *str;
};

int main(int argc, char *argv[])
{
    char charstr[] = "Hello world";
    String str(charstr);

    std::cout << str.size << std::endl;

    return 0;
}
