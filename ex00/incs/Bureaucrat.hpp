#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy_src);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat(void);

		// Bureaucrat(std::string name, int grade);
		Bureaucrat(const std::string &name, int grade);

		// std::string	getName(void) const;
		const std::string	&getName(void) const;
		int								getGrade(void) const;
		void							increaseGrade(void);
		void							decreaseGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:
		const std::string	_name;
		int								_grade;
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif
