#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// int main(void){
// 	Bureaucrat prof("Professor",1);
// 	Intern slave;

// 	try{
// 		AForm* shruberry = slave.makeForm("shruberry", "a house");
// 		AForm* robotomy = slave.makeForm("robotomy", "Bender");
// 		AForm* pardon = slave.makeForm("pardon", "Roberto");
// 		prof.signForm(*shruberry);
// 		prof.signForm(*robotomy);
// 		prof.signForm(*pardon);
// 		delete shruberry;
// 		delete robotomy;
// 		delete pardon;
// 	}catch(std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	try{
// 		AForm* shruberry = slave.makeForm("shru-berry", "a house");
// 		delete shruberry;
// 	}catch(std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }

// int	main( void )
// {
// 	Intern	someRandomIntern;
// 	AForm		*shrub;
// 	shrub	= someRandomIntern.makeForm("shrubbery creation", "home");
// 	Bureaucrat	you("You", 1);
// 	Bureaucrat	me("Me", 140);

// 	you.executeForm(*shrub);
// 	std::cout << std::endl;
// 	you.signForm(*shrub);
// 	std::cout << *shrub << std::endl;
// 	std::cout << you << std::endl;
// 	you.executeForm(*shrub);
// 	me.executeForm(*shrub);
// 	delete shrub;

// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	AForm		*robotomy;
// 	robotomy	= someRandomIntern.makeForm("robotomy request", "You");
// 	Bureaucrat	me2("Me", 1);

// 	me2.executeForm(*robotomy);
// 	me2.signForm(*robotomy);
// 	me2.executeForm(*robotomy);
// 	me2.executeForm(*robotomy);
// 	me2.executeForm(*robotomy);
// 	me2.executeForm(*robotomy);
// 	delete robotomy;
	
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	AForm		*presidential;
// 	presidential	= someRandomIntern.makeForm("presidential pardon", "You");
// 	Bureaucrat	me3("Me", 6);

// 	me3.executeForm(*presidential);
// 	me3.signForm(*presidential);
// 	me3.executeForm(*presidential);
// 	me3.increaseGrade();
// 	me3.executeForm(*presidential);
// 	delete presidential;

// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Trying to create a Form that doesn't exist. Result:" << std::endl;
// 	try
// 	{
// 		Intern	someRandomIntern2;
// 		AForm		*presidential;
// 		presidential	= someRandomIntern2.makeForm("Some thing that doesnt work", "You");
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout << e.what() << '\n';
// 	}
	

// 	return (0);
// }


// int	main( void )
// {
// 	Intern  intern;
//     Form*   form;

// 	// test form doesn't exist
// 	try { form = intern.makeForm("supply chain", "Pipe"); }
// 	catch (Form::FormDoesntExist & e) { ERROR(e.what()); }

// 	Bureaucrat	bob("bob", 138);
// 	form = intern.makeForm("shrubbery creation", "Garden");

// 	try { bob.executeForm(*form); }
// 	catch (Form::GradeTooLowException & e) { ERROR(e.what()); delete form; }
// 	bob.incGrade();
// 	bob.executeForm(*form);

// 	delete form;
// 	form = intern.makeForm("robotomy request", "Calvin");
// 	bob = Bureaucrat("bob", 46);

// 	try { bob.executeForm(*form); }
// 	catch (Form::GradeTooLowException & e) { ERROR(e.what()); delete form; }
// 	bob.incGrade();
// 	bob.executeForm(*form);

// 	delete form;
// 	form = intern.makeForm("presidential pardon", "Julian");
// 	bob = Bureaucrat("bob", 6);

// 	try { bob.executeForm(*form); }
// 	catch (Form::GradeTooLowException & e) { ERROR(e.what()); delete form; }
// 	bob.incGrade();
// 	bob.executeForm(*form);

// 	delete form;

// 	return 0;
// }

int main()
{
	Intern randomIntern;
	AForm *resForm;

	resForm = randomIntern.makeForm("shrubbery creation", "target1");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("robotomy request", "target2");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("presidential pardon", "target3");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("error", "target4");

	return 0;
}

