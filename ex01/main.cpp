
#include "Serializer.hpp"

int main(void)
{
	Data test_data = {1234, 123.999, "abc_XYZ"}; // Initialize test data structure
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "  Data before serializing    " << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Integer: " << test_data.int_val << std::endl;
	std::cout << "Double:  " << test_data.double_val << std::endl;
	std::cout << "String:  " << test_data.text << std::endl;
	std::cout << "Adress:  " << &test_data << std::endl; // Show original address

	uintptr_t	serialized_ptr = Serializer::serialize(&test_data); // Convert pointer to integer
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "  Data after serializing     " << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "uintptr value: " << serialized_ptr << std::endl;
	std::cout << "Adress:        " << &serialized_ptr << std::endl; // Address of the integer

	Data* deserialized_ptr =	Serializer::deserialize(serialized_ptr); // Convert integer back to pointer
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Data after deserializing:    " << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Integer: " << deserialized_ptr->int_val << std::endl;
	std::cout << "Double:  " << deserialized_ptr->double_val << std::endl;
	std::cout << "String:  " << deserialized_ptr->text << std::endl;
	std::cout << "Adress:  " << deserialized_ptr << std::endl; // Show deserialized address
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "    Pointer adress before/after   " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Original ptr:     " << &test_data << std::endl;
	std::cout << "Deserialized ptr: " << deserialized_ptr << std::endl;
	std::cout << "Are pointers equal:   " << (deserialized_ptr == &test_data ? "YES" : "NO") << std::endl; // Verify successful round-trip

	return(0);
}
