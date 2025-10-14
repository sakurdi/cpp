#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *elems;
	size_t n;

public:
	Array() : elems(NULL), n(0) {}

	Array(size_t size) : elems(NULL), n(size)
	{
		if (n > 0)
			elems = new T[n]();
	}

	Array(const Array &obj) : elems(NULL), n(obj.n)
	{
		if (n > 0)
		{
			elems = new T[n];
			for (size_t i = 0; i < n; i++)
				elems[i] = obj.elems[i];
		}
	}

	Array &operator=(const Array &obj)
	{
		if (this != &obj)
		{
			delete[] elems;
			n = obj.n;
			elems = NULL;
			if (n > 0)
			{
				elems = new T[n];
				for (size_t i = 0; i < n; i++)
					elems[i] = obj.elems[i];
			}
		}
		return *this;
	}

	~Array()
	{
		delete[] elems;
	}

	T &operator[](size_t index)
	{
		if (index >= n)
			throw std::out_of_range("Tu débordes garçon");
		return elems[index];
	}

	const T &operator[](size_t index) const
	{
		if (index >= n)
			throw std::out_of_range("Tu débordes garçon");
		return elems[index];
	}

	size_t size() const
	{
		return n;
	}
};

#endif