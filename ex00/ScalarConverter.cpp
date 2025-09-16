
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}


bool	ScalarConverter::is_char_literal(const std::string& input_string)
{
	if (input_string.length() == 1 && !std::isdigit(input_string[0]) && std::isprint(input_string[0])) // Check if single printable non-digit character
		return (true);
	return (false);
}
bool	ScalarConverter::is_int(const std::string& input_string, long& value)
{
	char*		end_ptr;
	long		parsed_int;
	parsed_int = strtol(input_string.c_str(), &end_ptr, 10); // Convert string to long integer
	if (*end_ptr == '\0' && parsed_int <= std::numeric_limits<int>::max() && parsed_int >= std::numeric_limits<int>::min()) // Check valid int range
	{
		value = parsed_int;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::is_float(const std::string& input_string, float& value)
{
	char*	end_ptr;
	double	parsed_double;

	parsed_double = strtod(input_string.c_str(), &end_ptr); // Convert string to double first
	if (*end_ptr == 'f' && *(end_ptr + 1) == '\0') // Check for 'f' suffix
	{
		if (!std::isnan(parsed_double) && !std::isinf(parsed_double) &&
			(parsed_double > std::numeric_limits<float>::max() || parsed_double < -std::numeric_limits<float>::max())) // Check float range
			return (false);
		value = static_cast<float>(parsed_double);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::is_double(const std::string& input_string, double& value)
{
	char*	end_ptr;
	double	parsed_double;

	parsed_double = strtod(input_string.c_str(), &end_ptr); // Convert string to double
	if (*end_ptr == '\0') // Check if entire string was consumed
	{
		value = parsed_double;
		return (true);
	}
	return (false);
}

void	ScalarConverter::convert(const std::string& input_string)
{
	if (is_char_literal(input_string) == true) // Try char literal first
	{
		print_char(input_string[0]);
		return ;
	}

	long int_val;
	if (is_int(input_string, int_val)) // Try integer conversion
	{
		print_int(int_val);
		return ;
	}

	float float_val;
	if (is_float(input_string, float_val)) // Try float conversion
	{
		print_float(float_val);
		return ;
	}

	double double_val;
	if (is_double(input_string, double_val)) // Try double conversion
	{
		print_double(double_val);
		return ;
	}

	std::cout << "Invalid input" << std::endl; // No valid conversion found
}

void	ScalarConverter::print_char(char c)
{
	std::cout << "char: \'" << c << "\'" << std::endl; // Display as character
	std::cout << "int: " << static_cast<int>(c) << std::endl; // Cast to int
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl; // Cast to float
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; // Cast to double
}

void	ScalarConverter::print_int(long int_val)
{
	if (int_val >= 0 && int_val <= 127 && std::isprint(static_cast<int>(int_val))) // Check if printable as char
		std::cout << "char: \'" << static_cast<char>(int_val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << int_val << std::endl; // Display as integer
	std::cout << "float: " << static_cast<float>(int_val) << ".0f" << std::endl; // Cast to float
	std::cout << "double: " << static_cast<double>(int_val) << ".0" << std::endl; // Cast to double
}

void	ScalarConverter::print_float(float float_val)
{
	if (std::isnan(float_val) || std::isinf(float_val)) // Check for special values
		std::cout << "char: impossible" << std::endl;
	else if (float_val >= 0 && float_val <= 127 && std::isprint(static_cast<int>(float_val))) // Check if printable as char
		std::cout << "char: \'" << static_cast<char>(float_val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (std::isnan(float_val) || std::isinf(float_val)) // Check for special values
		std::cout << "int: impossible" << std::endl;
	else if (float_val > std::numeric_limits<int>::max() || float_val < std::numeric_limits<int>::min()) // Check int range
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(float_val) << std::endl;

	if (std::isnan(float_val) || std::isinf(float_val))
		std::cout << "float: " << float_val << "f" << std::endl; // Special values as-is
	else if (float_val == static_cast<int>(float_val))
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_val << "f" << std::endl; // Integer values with .0
	else
		std::cout << "float: " << std::setprecision(7) << float_val << "f" << std::endl; // Preserve precision for non-integers
	if (std::isnan(static_cast<double>(float_val)) || std::isinf(static_cast<double>(float_val)))
		std::cout << "double: " << static_cast<double>(float_val) << std::endl; // Special values as-is
	else if (static_cast<double>(float_val) == static_cast<int>(static_cast<double>(float_val)))
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(float_val) << std::endl; // Integer values with .0
	else
		std::cout << "double: " << std::setprecision(15) << static_cast<double>(float_val) << std::endl; // Preserve precision for non-integers
}

void	ScalarConverter::print_double(double double_val)
{
	if (std::isnan(double_val) || std::isinf(double_val)) // Check for special values
		std::cout << "char: impossible" << std::endl;
	else if (double_val >= 0 && double_val <= 127 && std::isprint(static_cast<int>(double_val))) // Check if printable as char
		std::cout << "char: \'" << static_cast<char>(double_val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (std::isnan(double_val) || std::isinf(double_val)) // Check for special values
		std::cout << "int: impossible" << std::endl;
	else if (double_val > std::numeric_limits<int>::max() || double_val < std::numeric_limits<int>::min()) // Check int range
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(double_val) << std::endl;

	if (std::isnan(double_val) || std::isinf(double_val))
		std::cout << "float: " << static_cast<float>(double_val) << "f" << std::endl; // Special values as-is
	else if (double_val == static_cast<int>(double_val))
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(double_val) << "f" << std::endl; // Integer values with .0
	else
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(double_val) << "f" << std::endl; // Preserve precision for non-integers
	if (std::isnan(double_val) || std::isinf(double_val))
		std::cout << "double: " << double_val << std::endl; // Special values as-is
	else if (double_val == static_cast<int>(double_val))
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_val << std::endl; // Integer values with .0
	else
		std::cout << "double: " << std::setprecision(15) << double_val << std::endl; // Preserve precision for non-integers
}
