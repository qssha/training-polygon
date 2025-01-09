#include <iostream>

int txt_size() {
    int a;
    std::cin >> a;
    return a;
}

int main() {
    // G++ supports a C99 feature that allows dynamically sized arrays.
    // https://stackoverflow.com/questions/1204521/dynamic-array-in-stack
    // https://stackoverflow.com/questions/1887097/why-arent-variable-length-arrays-part-of-the-c-standard
    const char cstr[5] = "Test";
    int arr[4 * 7 - 14];

    int arr_txt_size[txt_size()];
    arr_txt_size[100] = 1024;
    std::cout << arr_txt_size[100] << std::endl;

    unsigned buf_size = 1024;
    int ia[buf_size];

    return 0;
}
