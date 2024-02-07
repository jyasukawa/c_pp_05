#include "Form.hpp"

Form::Form(void) : _name("default_name"), _sign(false), _grade_sign(75), _grade_exec(75)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &copy_src) : _grade_sign(copy_src._grade_sign), _grade_exec(copy_src._grade_exec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy_src;
}

Form	&Form::operator=(const Form &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_sign = rhs._sign;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const std::string &name, int grade_dign, int grade_exec) : _name(name), 
										_sign(false), _grade_sign(grade_dign), _grade_exec(grade_exec)
{
	std::cout << "Form string_name constructor called" << std::endl;
	if (this->_grade_sign < 1 || this->_grade_exec < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw Form::GradeTooLowException();
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSign(void) const
{
	return (this->_sign);
}

int	Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	Form::getGradeExec(void) const
{
	return (this->_grade_exec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_sign == true)
		return ;
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	this->_sign = true;
}

std::ostream	&operator<<(std::ostream &os, Form &form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Signed: " << form.getSign() << std::endl;
	os << "Required grade for sign: " << form.getGradeSign() << std::endl;
	os << "Required grade for execution: " << form.getGradeExec() << std::endl;
	return (os);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}
