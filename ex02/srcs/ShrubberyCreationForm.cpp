#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default_name", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy_src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy_src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->AForm::checkExecutable(executor);
	std::ofstream	of;
	of.open((this->_target + "_shrubbery").c_str());
	if (of.is_open())
	{
		of << "* * *" << std::endl;
		of << "| | |" << std::endl;
	}
	else
		std::cout << "Error: failed to open file." << std::endl;
	of.close();
}
