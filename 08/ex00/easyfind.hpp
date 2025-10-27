#include <algorithm> 
#include <stdexcept>

template <typename T>typename T::value_type &easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	else
		throw std::runtime_error("Item not found");
}