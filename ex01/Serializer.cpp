
#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
}

uintptr_t	Serializer::serialize(Data* data_pointer)
{
	return (reinterpret_cast<uintptr_t>(data_pointer)); // Cast pointer to integer
}
Data*		Serializer::deserialize(uintptr_t raw_int)
{
	return (reinterpret_cast<Data*>(raw_int)); // Cast integer back to pointer
}
