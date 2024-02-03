template <typename T>
class matrix
{
public:
	virtual T& operator()(unsigned int, unsigned int) = 0;
	virtual unsigned int get_width() = 0;
	virtual unsigned int get_height() = 0;
	virtual ~matrix() = 0;
};

template <typename T>
matrix<T>::~matrix()
{
}


template <typename T>
class flat_array_matrix : public matrix<T>
{
public:
	flat_array_matrix(unsigned int height, unsigned int width) :
		height(height), width(width), matrix(new T[height * width])
	{
	}

	T& operator()(unsigned int i, unsigned int j)
	{
		return matrix[i * width + j];
	}

	unsigned int get_width()
	{
		return width;
	}

	unsigned int get_height()
	{
		return height;
	}

	~flat_array_matrix()
	{
		delete[] matrix;
	}

private:
	unsigned int height;
	unsigned int width;
	T* matrix;
};

template <typename T>
class pointer_array_matrix : public matrix<T>
{
public:
	pointer_array_matrix(unsigned int height, unsigned int width) :
		height(height), width(width)
	{
		matrix = new T*[height];
		for (unsigned int i = 0; i < height; i++)
		{
			matrix[i] = new T[width];
		}
	}

	T& operator()(unsigned int i, unsigned int j)
	{
		return matrix[i][j];
	}

	unsigned int get_width()
	{
		return width;
	}

	unsigned int get_height()
	{
		return height;
	}

	~pointer_array_matrix()
	{
		for (unsigned int i = 0; i < height; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

private:
	unsigned int height;
	unsigned int width;
	T** matrix;
};
