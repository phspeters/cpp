#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Bureaucrat", 1);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	try
	{
		Bureaucrat	b("Bureaucrat", 150);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	try
	{
		Bureaucrat	c("Bureaucrat", 0);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	try
	{
		Bureaucrat	d("Bureaucrat", 151);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
}
