#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy_src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy_src;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm *newPPForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *newRRForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *newSCForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string	form_list[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	total = sizeof(form_list) / sizeof(form_list[0]);
	AForm* (*func[])(const std::string&) = {&newPPForm, &newRRForm, &newSCForm};
	int i = 0;
	while (i < total && formName != form_list[i])//total = 3
		i++;
	if (i < total)
	{
		std::cout << "Intern creates " << form_list[i] << std::endl;
		return((*func[i])(target));
	}
	else
	{
		std::cout << "Error: Invalid form!" << std::endl;
		return (NULL);
	}
}
