#include <cstddef>

template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

template <typename T, typename Comp>
T minimum(Array<T> const& array, Comp less)
{
    int min = 0;
    
    for (size_t i = 1; i < array.size(); ++i) {
        if (less(array[i], array[min])) min = i;
    }

    return array[min];
}

int main(int argc, char *argv[])
{

    return 0;
}
