#include <iostream>

unsigned strlen(const char *str) {
    int i = 0;

    while (str[i++] != '\0') { 
    }

    return --i;
}


int strstr(const char *text, const char *pattern)
{
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int checkNumber = 0;

    if (textLen < patternLen) {
       return -1; 
    }
    else if (patternLen == 0) {
        return 0;
    }

    for (int i = 0; i < textLen; i++) {
        if (text[i] == pattern[checkNumber]) {
            checkNumber++;
        }
        else {
            checkNumber = 0;

            if (text[i] == pattern[0]) i--;
        }

        if (checkNumber == patternLen) return i - checkNumber + 1;
    }

    return -1;
}


int main(int argc, char *argv[])
{
    char str1[] = "Hellopasd";
    char str2[] = "H";

    std::cout << strstr(str1, str2) << " 0" << std::endl;

    char str3[]  = "asddsd";
    char str4[] = "asd";

    std::cout << strstr(str3, str4) << " 0" << std::endl;

    char str5[]  = "asdasd";
    char str6[] = "sda";

    std::cout << strstr(str5, str6) << " 1" << std::endl;

    char str7[]  = "H";
    char str8[] = "H";

    std::cout << strstr(str7, str8) << " 0" << std::endl;


    char str9[]  = "";
    char str10[] = "";

    std::cout << strstr(str9, str10) << " 0" << std::endl;

    char str11[] = "hhello";
    char str12[] = "hello";

    std::cout << strstr(str11, str12) << " 1" << std::endl;

    return 0;
}
