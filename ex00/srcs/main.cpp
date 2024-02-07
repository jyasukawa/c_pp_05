#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("b", 150);

	std::cout << "--------------------------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat	c("c", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat	d("d", 0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat	f("f", 20);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		a.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		b.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	return (0);
}
