#include <cstddef>
#include <new>
#include <iostream>

struct Test {
    public:
        Test(long init_t) : t(init_t) {}
        long t;

        Test(const Test& otherTest) {
            t = otherTest.t;
        }

        ~Test()
        {
            std::cout << "Destructing" << std::endl;
        }

    private:
        Test& operator=(const Test& otherTest);
};

template <typename T>
class Array
{
    public:
        explicit Array(size_t size, const T& value = T())
            : size_(size)
        {
            data = (T*) (new char[size_ * sizeof(T)]);

            for (size_t i = 0; i < size_; ++i) {
                new (data + i) T(value);
            }
        }

        Array() : size_(0), data(0) {}

        Array(const Array & otherArray)
            : size_(otherArray.size_)
        {
            data = (T*) (new char[size_ * sizeof(T)]);
                for (size_t i = 0; i < size_; ++i) {
                    new (data + i)  T(*(otherArray.data + i));
                }
        }

        ~Array()
        {
            for (size_t i = 0; i < size_; ++i) {
                data[i].~T();
            }

            operator delete[] (data);
        }

        Array& operator=(const Array & otherArray)
        {
            if (data != otherArray.data) {
                this->~Array();

                size_ = otherArray.size_;
                data = (T*) (new char[size_ * sizeof(T)]);

                for (size_t i = 0; i < size_; ++i) {
                    new (data + i) T(*(otherArray.data + i));
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
        T *data;
        size_t size_;
};

int main(int argc, char *argv[])
{
    Test t(1111111);

    Array<Test> arr(1, t);

    //Array<Test> arr2;




    
    return 0;
}
