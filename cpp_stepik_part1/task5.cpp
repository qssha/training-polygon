#include <iostream>


void print_array(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void rotate(int a[], unsigned size, int shift)
{
    int trueShift = shift % size;
    int temp;

    for (int i = 0; i < trueShift; ++i) {
       temp = *a; 

       for (int* p  = a; p < a + size - 1; ++p) {
           *p = *(p + 1);
       }

       *(a + size - 1) = temp;
    }
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4, 5};

    rotate(a, 5, 7);

    print_array(a, 5);
   
    return 0;
}
