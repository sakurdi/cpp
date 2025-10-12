#include "Serializer.hpp"

	struct Data
	{
		
		std::string prophecy;
		int year;

		Data(): prophecy(nostra), year(1555) {}
		Data(const std::string &str, int y): prophecy(str), year(y) {}
	};

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}