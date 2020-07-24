#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
    public:
        explicit Array(size_t size = 0, const T& value = T())
            : size_(size), data(new T[size_])
        {
            for (size_t i = 0; i < size_; ++i) {
                data[i] = value;
            }
        }

        Array(const Array & otherArray)
            : size_(otherArray.size_), data(new T[size_])
        {
            for (size_t i = 0; i < size_; ++i) {
                data[i] = otherArray.data[i];
            }
        }

        ~Array()
        {
            delete [] data;
        }

        Array& operator=(const Array & otherArray)
        {
            if (data != otherArray.data) {
                delete [] data;

                size_ = otherArray.size_;
                data = new T[size_];

                for (size_t i = 0; i < size_; ++i) {
                    data[i] = otherArray.data[i];
                }
            }

            return *this;
        }

        size_t size() const
        {
            return size_;
        }

        T& operator[](size_t index) 
        {
            return data[index];
        }

        const T& operator[](size_t index) const
        {
            return data[index];
        }

    private:
        size_t size_;
        T * data;
};

int main(int argc, char *argv[])
{
    Array<int> arr(10, 20);
    return 0;
}
