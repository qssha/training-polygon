#include <cstddef>

template <typename T, size_t N>
int array_size(T (&array)[N])
{
    return N;
}

int main(int argc, char *argv[])
{
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    array_size(ints); // вернет 4
    array_size(doubles); // вернет 1
    //array_size(iptr); // тут должна произойти ошибка компиляции

    return 0;
}
