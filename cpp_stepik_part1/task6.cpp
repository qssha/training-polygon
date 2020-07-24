#include <iostream>

unsigned strlen(const char *str) {
    int i = 0;

    while (str[i++] != '\0') { 
    }

    return --i;
}

int main(int argc, char *argv[])
{
    char st[] = "";
    std::cout << strlen(st) << std::endl;
    return 0;
}
