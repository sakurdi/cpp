#ifndef SERALIZER_HPP
#define SERALIZER_HPP

#define nostra \
"Le lyon ieune le vieux surmontera, \
En champ bellique par singulier duelle, \
Dans cage d’or les yeux luy creuera, \
Deux classes une puis mourir mort cruelle."

#include <iostream>
#include <stdint.h> 
class Serializer
{
public:
	struct Data
	{
		
		std::string prophecy;
		int year;

		Data(): prophecy(nostra), year(1555) {}
		Data(const std::string &str, int y): prophecy(str), year(y) {}
	};
	
private:
	Serializer(/* args */);
	Serializer(const Serializer &obj);
	Serializer &operator=(const Serializer &obj);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif