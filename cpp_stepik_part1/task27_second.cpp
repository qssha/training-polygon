#include <iostream>
#include <cstddef> // size_t
#include <cstring>
#include <algorithm>


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


    String(const String &other) 
        : size(other.size), str(new char[other.size + 1]) 
    {
        strcpy(str, other.str);
    }

    void swap(String &a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }

    String &operator=(const String &other)
    {
        if (this != &other) {
            String(other).swap(*this);
        }

        return *this;
    }

    void append(String &other) {
        char *newstr = new char[this->size + other.size + 1];
        strcpy(newstr, this->str);
        strcpy(newstr + size, other.str);
        delete [] this->str;
        this->str = newstr;
        this->size = strlen(newstr);
    }

    String (char *str, size_t n) : size(n) {
        this->str = new char[size + 1];

        for (size_t i = 0; i < size; i++) {
            this->str[i] = str[i];
        }

        this->str[size] = '\0';
    }

    size_t size;
    char *str;

    struct Slice {
        Slice(char *str, int lowerBound) : slice(str), lowerBound(lowerBound) {}

        String operator[](int j) {
            return String(slice, j - lowerBound);
        }

        char *slice;
        int lowerBound;
    };

    Slice operator[](int i) const {
        char *slice = str + i;

        return Slice(slice, i);
    }
};

int main(int argc, char *argv[])
{
    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"

    std::cout << hello.str << std::endl;
    std::cout << hell.str << std::endl;
    std::cout << ell.str << std::endl;

    return 0;
}
