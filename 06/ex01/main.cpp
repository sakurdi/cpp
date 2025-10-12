#include "Serializer.hpp"

int main()
{
	Serializer::Data data;
	Serializer::Data *data_ptr = &data;
	uintptr_t serial = Serializer::serialize(data_ptr);
	std::cout << "Data_ptr addr: " <<static_cast<void*>(data_ptr) << std::endl;
	std::cout << "serial addr: 0x" << std::hex << serial << std::endl;
	std::cout << data.prophecy << std::endl << "-" << data.year << std::endl;

	Serializer::Data* dePtr = Serializer::deserialize(serial);
	std::cout << "-------Addr check after deserialize-------" << std::endl;
	std::cout << dePtr->prophecy << std::endl << "-" << dePtr->year << std::endl;
	std::cout << "dePtr addr: " << static_cast<void*>(data_ptr) << std::endl;

}