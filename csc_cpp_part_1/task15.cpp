#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {
    String(const char *str = "") : size(strlen(str)) {
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

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

    void append(String &other) {
        char *newstr = new char[this->size + other.size + 1];
        strcpy(newstr, this->str);
        strcpy(newstr + size, other.str);
        delete [] this->str;
        this->str = newstr;
        this->size = strlen(str);
    }

	size_t size;
	char *str;
};


int main(int argc, char *argv[])
{
    String str1("");
   
    String str2("Helo");

    str1.append(str2);

    std::cout << str1.str << std::endl;
    
    return 0;
}
