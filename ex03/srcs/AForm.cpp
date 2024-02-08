#include "AForm.hpp"

AForm::AForm(void) : _name("default_name"), _sign(false), _grade_sign(75), _grade_exec(75)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy_src) : _grade_sign(copy_src._grade_sign), _grade_exec(copy_src._grade_exec)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy_src;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_sign = rhs._sign;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string &name, int grade_dign, int grade_exec) : _name(name), 
										_sign(false), _grade_sign(grade_dign), _grade_exec(grade_exec)
{
	std::cout << "AForm string_name constructor called" << std::endl;
	if (this->_grade_sign < 1 || this->_grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw AForm::GradeTooLowException();
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSign(void) const
{
	return (this->_sign);
}

int	AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_grade_exec);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_sign == true)
		return ;
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw AForm::GradeTooLowException();
	this->_sign = true;
}

void	AForm::checkExecutable(Bureaucrat const & executor) const
{
	if (this->_sign == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, AForm &Aform)
{
	os << "AForm name: " << Aform.getName() << std::endl;
	os << "Signed: " << Aform.getSign() << std::endl;
	os << "Required grade for sign: " << Aform.getGradeSign() << std::endl;
	os << "Required grade for execution: " << Aform.getGradeExec() << std::endl;
	return (os);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed!");
}
