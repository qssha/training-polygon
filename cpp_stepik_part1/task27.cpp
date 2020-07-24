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

    String(const String &other, int bound, bool check) 
        : size(other.size), str(new char[other.size + 1]) 
    {
        strcpy(str, other.str);
        startSlice = bound;
        isSliced = check;
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

    size_t size;
    char *str;
    int startSlice = 0;
    bool isSliced = false;

    String operator[](int i) const {
        if (!isSliced) {
            char *slice = new char[size - i];

            for (int k = size; k >= i; k--) {
                slice[k - i] = str[k];
            }

            String slicedString(slice);
            slicedString.startSlice = i;
            slicedString.isSliced = true;

            return String(slicedString, i, true);
        }
        else {
            if (i == startSlice) return "";
            int sliceSize = i - startSlice;
            char *slice = new char[sliceSize + 1];

            for (int k = 0; k <= sliceSize; k++) {
                slice[k] = str[k];
            }
            slice[sliceSize] = '\0';
            String slicedString(slice);
            slicedString.isSliced = false;

            return String(slicedString, 0, false);
        }
    }
};

int main(int argc, char *argv[])
{
    String const hello("hello");
    String const hell = hello[0][1]; // теперь в hell хранится подстрока "hell"
    String const ell  = hello[4][4]; // теперь в ell хранится подстрока "ell"

    std::cout << hello.str << std::endl;
    std::cout << hell.str << std::endl;
    std::cout << ell.str << std::endl;

    return 0;
}
