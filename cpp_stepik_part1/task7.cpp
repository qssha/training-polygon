#include <iostream>

void strcat(char *to, const char *from)
{
    int toEndNum = 0, fromEndNum = 0;

    while (to[toEndNum] != '\0') { toEndNum++; }

    while (from[fromEndNum] != '\0') {
        to[toEndNum + fromEndNum] = from[fromEndNum];
        fromEndNum++;
    }

    to[toEndNum + fromEndNum] = '\0';
}

int main(int argc, char *argv[])
{
    char str1[15] = "Hello";
    char str2[] = "world";

    strcat(str1, str2);

    std::cout << str1 << std::endl;
    
    return 0;
}
