
#ifndef SERIALIZER_H
#define SERIALIZER_H


#include <iostream>
#include <string>
#include <stdint.h>

#include "Data.hpp"

class Serializer
{
	public:
		~Serializer();

		static uintptr_t	serialize(Data* data_pointer);
		static Data*		deserialize(uintptr_t raw_int);

	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
};

#endif // SERIALIZER_H
