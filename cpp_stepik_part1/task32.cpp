#include <iostream>

struct ICloneable {
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
    ValueHolder(const T& value) : data_(value) {}

    ValueHolder* clone() const
    {
        return new ValueHolder(data_);
    }

    ~ValueHolder() {}

    T data_;
};

int main(int argc, char *argv[])
{
    ValueHolder<int> f(10);
    ValueHolder<int> *b = f.clone();

    std::cout << b->data_ << std::endl;


    delete b;
    return 0;
}
