/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnemmass <hnemmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:54:11 by hnemmass          #+#    #+#             */
/*   Updated: 2026/10/17 20:24:14 by hnemmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

int check_char(const std::string &s)
{
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return (0);
	if (s.length() == 1 && !std::isdigit(s[0]))
		return (0);
	return (1);
}

void trim(std::string &s)
{
    int end = s.length() - 1;
    while (end >= 0 && (s[end] == ' ' || s[end] == '\t'))
        end--;
    s.resize(end + 1);
}

int check_int(const std::string &s)
{
	char *end;
	std::string ss = s;

	trim(ss);
	long n = std::strtol(ss.c_str(), &end, 10);
	if (*end == '\0' && ss.length() > 0 &&
		n >= std::numeric_limits<int>::min() && n <= std::numeric_limits<int>::max())
		return (0);
	return (1); 
}

int check_double(const std::string &s)
{
	char *end;
	std::string ss = s;

	trim(ss);
	std::strtod(ss.c_str(), &end);
	
	if (*end == '\0' && ss.length() > 0)
		return (0);
	return (1);
}

int check_float(const std::string &s)
{
	char *end;
	std::string ss = s;

	trim(ss);
	std::strtod(ss.c_str(), &end);
	
	if (ss == "f")
		return (1);
	if (ss == "nanf" || ss == "+inff" || ss == "-inff")
		return (0);
	if (*end == 'f' && *(end + 1) == '\0' 
		&& end != ss.c_str() && ss.find('.') != std::string::npos)
		return (0);
	return (1);
}

int parse_string(const std::string &s)
{
	if (check_char(s) == 0)
		return (1);
	if (check_int(s) == 0)
		return (2);
	if (check_double(s) == 0)
		return (3);
	if (check_float(s) == 0)
		return (4);
	return (0);
}

void print_char(const std::string &s)
{
	char c = (s.length() == 3) ? s[1] : s[0];

	if (std::isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_int(const std::string &s)
{
	int n = static_cast<int>(std::strtol(s.c_str(), NULL, 10));

	if (n >= 32 && n <= 126)
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else if (n >= 0 && n <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void print_double(const std::string &s)
{
	char *end;
	double d = std::strtod(s.c_str(), &end);

	if ((d >= 32 && d <= 126))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;


	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()
		|| std::isnan(d)|| std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;


	if (std::isinf(d) && d > 0)
	{
		std::cout << "float: +" << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: +" << static_cast<double>(d) << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
}

void print_float(const std::string &s)
{
	float f = std::strtof(s.c_str(), NULL);

	if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f >= 0 && f <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (f >= static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min())
		|| std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (std::isinf(f) && f > 0)
	{
		std::cout << "float: +" << f << "f" << std::endl;
		std::cout << "double: +" << static_cast<double>(f) << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::convert(const std::string &s)
{
	std::cout << std::fixed << std::setprecision(1);
	int type = parse_string(s); 
	switch (type)
	{
		case (1):
			print_char(s);
			return;
		case (2):
			print_int(s);
			return ;
		case (3):
			print_double(s);
			return ;
		case (4):
			print_float(s);
			return;
		default:
			std::cout << "please enter a valid format" << std::endl;
			return;
	}
}