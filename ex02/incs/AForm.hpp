#ifndef	A_AFORM_HPP
# define A_AFORM_HPP

# include	"Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const AForm &copy_src);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm(void);

		AForm(const std::string &name, int grade_dign, int grade_exec);//PDFより_signは作成時はfalse

		const std::string	&getName(void) const;
		bool							getSign(void) const;
		int								getGradeSign(void) const;
		int								getGradeExec(void) const;
		void							beSigned(const Bureaucrat &bureaucrat);
		virtual void			execute(Bureaucrat const & executor) const = 0;
		void							checkExecutable(Bureaucrat const & executor) const;

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

		class NotSignedException : public std::exception
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

std::ostream	&operator<<(std::ostream &os, AForm &AForm);

#endif
