#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &copy_src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const std::string &target);

		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
};

#endif
