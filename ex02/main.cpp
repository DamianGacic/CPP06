
#include "Identify.hpp"
#include "Base.hpp"

int main(void)
{
	for (int i = 1; i <= 5; i++)
	{
		std::cout << "\n--- Test " << i << " ---" << std::endl;
		Base* obj = generate(); // Create random instance
		identify(obj); // Test pointer
		identify(*obj); // Test reference
		delete obj; // Cleanup
	}
	return (0);
}
