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

class Any
{
    public:
        Any() : anyData_(0) {}

        template <typename T>
        Any(const T& value) : anyData_(new ValueHolder<T>(value)) {}

        Any(const Any& otherAny)
        {
            if (otherAny.anyData_ != 0) {
                anyData_ = otherAny.anyData_->clone();
            } else {
                anyData_ = 0;
            }
        }

        Any& operator=(const Any& otherAny)
        {
            if (anyData_ != otherAny.anyData_) {
                delete anyData_;

                anyData_  = otherAny.anyData_->clone();
            }

            return *this;
        }

        template <typename T>
        T* cast()
        {
            ValueHolder<T>* data = dynamic_cast<ValueHolder<T>* >(anyData_);

            if (data) {
                return &(data->data_);
            } else {
                return 0;
            }
        }

        ~Any()
        {
            delete anyData_;
        }

        ICloneable* anyData_;
};

int main(int argc, char *argv[])
{
    Any empty;
    Any i(10);
    Any copy(i);


    int *iptr = i.cast<int>();
    std::cout << *iptr << std::endl;

    char* cptr = empty.cast<char>();
    std::cout << cptr << std::endl;

    return 0;
}
