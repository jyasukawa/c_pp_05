#ifndef	INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy_src);
		Intern &operator=(const Intern &rhs);
		~Intern(void);

		AForm *makeForm(std::string formName, std::string target);
};

#endif