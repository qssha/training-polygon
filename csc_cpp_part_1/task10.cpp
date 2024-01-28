#include <iostream>

#define BUFF_SIZE 32

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

char *getline()
{
    char temp = 0;
    int currentLen = BUFF_SIZE, count = 0;
    char *str = new char[BUFF_SIZE];

    while (std::cin.get(temp) && temp !='\n') {
        if (count > currentLen - 1) {
            str = resize(str, currentLen, currentLen * 2);
            currentLen *= 2;
        }

        str[count++] = temp;
    }

    str = resize(str, currentLen, count);
    str[count] = '\0';

    return str;
}

int main(int argc, char *argv[])
{
    std::cout << getline() << std::endl;
    
    return 0;
}
