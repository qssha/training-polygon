#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
    if (size == new_size) return (char*) str;

    char *newstr = new char[new_size];

    for (int i = 0; i < new_size; ++i) {
        newstr[i] = str[i];
    }

    delete[] str;

    return newstr;
}

int main(int argc, char *argv[])
{
    
    return 0;
}
