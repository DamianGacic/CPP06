
#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H


#include <iostream>
#include <string>
#include <limits>	// std::numeric_limits
#include <climits>	// INT_MAX, INT_MIN
#include <cmath>	// std::isnan, std::infinity, HUGE_VAL
#include <cstdlib>	// strtol, strtof, strtod
#include <iomanip>	// std::fixed, std::setprecision

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(const std::string& input_string);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);

		static bool						is_char_literal(const std::string& input_string);
		static bool						is_int(const std::string& input_string, long& value);
		static bool						is_float(const std::string& input_string, float& value);
		static bool						is_double(const std::string& input_string, double& value);

		static void	print_char(char c);
		static void	print_int(long int_val);
		static void	print_float(float float_val);
		static void	print_double(double double_val);
};

#endif // SCALARCONVERTER_H
