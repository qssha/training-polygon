#include <iostream>


int strstr(const char *text, const char *pattern)
{
    if (*pattern == '\0') return 0;

    const char *start = text;
    const char *current, *current_pattern;

    while (*text) {
        current = text;
        current_pattern = pattern;

        while (*current == *current_pattern && *++current_pattern != '\0' && *++current != '\0') {
        }

        if (*current_pattern == '\0') {
            return text - start;
        }

        text++;
    }

    return -1;
}


int main(int argc, char *argv[])
{
    char str1[] = "hhello";
    char str2[] = "o";

    std::cout << strstr(str1, str2) << " 1" << std::endl;

    return 0;
}
