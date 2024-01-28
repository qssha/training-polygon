#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a = (int *)malloc(sizeof(int) * 10);
    a[5] = 100;

    printf("%d\n", a[5]);

    free(a);
    a = 0;

    printf("%d\n", a[5]);

    return 0;
}
