#include <cstddef>

template <typename U, typename T>
void copy_n(T* output, U* input, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        output[i] = static_cast<T>(input[i]);
    }
}

int main(int argc, char *argv[])
{
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4); 
    return 0;
}
