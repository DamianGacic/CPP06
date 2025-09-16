#include "Identify.hpp"

Base*	generate(void)
{
	// Static variable ensures srand() is called only once across all function calls
	// This prevents re-seeding with the same time value when called rapidly
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(0))); // Seed random number generator with current time
		seeded = true; // Mark as seeded to prevent future calls to srand()
	}
	int rnd = std::rand() % 3; // Generate random integer: 0, 1, or 2

	// Create and return appropriate derived class instance based on random choice
	switch (rnd) // Create and return appropriate derived class instance based on rnd
	{
		case (0):
			return (new A()); // Instantiate class A derived from Base
		case (1):
			return (new B()); // Instantiate class B derived from Base
		case (2):
			return (new C()); // Instantiate class C derived from Base
		default:
			return (NULL); // Safety fallback - should never execute
	}
}
void	identify(Base* base_pointer)
{
	if (dynamic_cast<A*>(base_pointer) != NULL) // Try casting to A*
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base_pointer) != NULL) // Try casting to B*
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base_pointer) != NULL) // Try casting to C*
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}
void	identify(Base& base_reference)
{
	try
	{
		(void)dynamic_cast<A&>(base_reference); // Try casting to A&
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& exception)
	{
		(void)exception; // Suppress unused variable warning
	}

	try
	{
		(void)dynamic_cast<B&>(base_reference); // Try casting to B&
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& exception)
	{
		(void)exception; // Suppress unused variable warning
	}

	try
	{
		(void)dynamic_cast<C&>(base_reference); // Try casting to C&
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& exception)
	{
		(void)exception; // Suppress unused variable warning
	}
	std::cout << "unknown" << std::endl;
}
