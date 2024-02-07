#ifndef	FORM_HPP
# define FORM_HPP

# include	"Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const Form &copy_src);
		Form &operator=(const Form &rhs);
		~Form(void);

		Form(const std::string &name, int grade_dign, int grade_exec);//PDFより_signは作成時はfalse

		const std::string	&getName(void) const;
		bool							getSign(void) const;
		int								getGradeSign(void) const;
		int								getGradeExec(void) const;
		void							beSigned(const Bureaucrat &bureaucrat);

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
		bool							_sign;
		const int					_grade_sign;
		const int					_grade_exec;
};

std::ostream	&operator<<(std::ostream &os, Form &Form);

#endif
