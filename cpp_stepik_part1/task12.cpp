#include <iostream>

int min(int *arr, unsigned size) {
    int min = arr[0];

    for (unsigned i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int rowWithMin = 0;
    int minElem = min(m[0], cols);
    int currentMin;

    for (unsigned i = 1; i < rows; ++i) {
        currentMin = min(m[i], cols);
        if (currentMin < minElem) {
            rowWithMin = i;
            minElem = currentMin;
        }
    }

    if (rowWithMin != 0) {
        int *temp = m[0];
        m[0] = m[rowWithMin];
        m[rowWithMin] = temp;
    }
}



int main(int argc, char *argv[])
{
    
    return 0;
}
