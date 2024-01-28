#include <iostream>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **tarray = new int *[cols];
    tarray[0] = new int[cols * rows];

    for (unsigned i = 1; i < cols; ++i) {
        tarray[i] = tarray[i - 1] + rows;
    }

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            tarray[j][i] = m[i][j];
        }
    }

    return tarray;
}


int main(int argc, char *argv[])
{
    int a[2][2] = {{1, 2}, {3, 4}};

    
    return 0;
}
