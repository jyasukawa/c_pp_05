#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default_name", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy_src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy_src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->AForm::checkExecutable(executor);
	std::cout << _target << " has been pardoned by Zafor Beeblebrox." << std::endl;
}
