#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Corrector", 1);
	Bureaucrat	me("Me", 140);

	corr.executeForm(*shrub);
	std::cout << std::endl;
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("Corrector");
	Bureaucrat	me2("Me", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*presidential = new PresidentialPardonForm("Corrector");
	Bureaucrat	me3("Me", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.increaseGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}




int	main(void)
{
	srand(time(NULL));

	outputTitle("Shrubbery Creation");
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Lucie", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;


	outputTitle("Robotomy Request");
	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Lucie", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;


	outputTitle("Presidential Pardon");
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Lucie", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.increaseTheRank();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}



void bureaucratTest(){
	std::cout << std::endl << "💼💼💼💼BUREAUCRAT START💼💼💼💼" << std::endl;
	std::cout << "Stack allocation start" << std::endl;
	try{
		Bureaucrat hermes("Hermes",33);
		Bureaucrat fry("Fry",150);
		Bureaucrat professor("Professor",1);
		std::cout << hermes << std::endl;
		std::cout << fry << std::endl;
		std::cout << professor << std::endl;
		Bureaucrat bender("Bender",0);
		std::cout << bender << std::endl;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Stack allocation end" << std::endl << std::endl;
	std::cout << "Heap allocation start" << std::endl;
	try{
		Bureaucrat* hermes = new Bureaucrat("Hermes",33);
		Bureaucrat* fry = new Bureaucrat("Fry",150);
		Bureaucrat* professor = new Bureaucrat("Professor",1);
		std::cout << *hermes << std::endl;
		std::cout << *fry << std::endl;
		std::cout << *professor << std::endl;
		delete hermes;
		delete fry;
		delete professor;
		Bureaucrat* bender = new Bureaucrat("Bender",151);
		delete bender;
		std::cout << *bender << std::endl;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Heap allocation end" << std::endl << std::endl;
	std::cout << std::endl << "💼💼💼💼BUREAUCRAT END💼💼💼💼" << std::endl;
};
void shrubberyTest(){
	std::cout << std::endl << "🌳🌳🌳🌳SHRUBBERY START🌳🌳🌳🌳" << std::endl << std::endl;
	{
		ShrubberyCreationForm form("Homer's house");
		Bureaucrat hermes("Hermes",33);
		hermes.signForm(form);
		hermes.executeForm(form);
	}
	std::cout << std::endl << "🌳🌳🌳🌳SHRUBBERY END🌳🌳🌳🌳🌳" << std::endl;
};
void robotomyTeste(){
	std::cout << std::endl << "🤖🤖🤖🤖ROBOTOMY START🤖🤖🤖🤖" << std::endl << std::endl;
	std::srand(time(NULL));
	{
		RobotomyRequestForm benderForm("Bender");
		RobotomyRequestForm robertoForm("Roberto");
		RobotomyRequestForm hedForm("Hedonismbot");
		Bureaucrat fry("Fry",140);
		Bureaucrat hermes("Hermes",70);
		Bureaucrat prof("Professor",1);
		fry.signForm(benderForm);
		fry.signForm(robertoForm);
		fry.signForm(hedForm);
		hermes.signForm(benderForm);
		hermes.signForm(robertoForm);
		hermes.signForm(hedForm);
		prof.signForm(benderForm);
		prof.signForm(robertoForm);
		prof.signForm(hedForm);
		fry.executeForm(benderForm);
		hermes.executeForm(benderForm);
		prof.executeForm(benderForm);
	}
		std::cout << std::endl << "🤖🤖🤖🤖ROBOTOMY END🤖🤖🤖🤖🤖" << std::endl;
};
void presidentialTest(){
	std::cout << std::endl << "🤴🤴🤴🤴PRESIDENTIAL START🤴🤴🤴🤴" << std::endl << std::endl;
	{
		PresidentialPardonForm benderForm("Bender");
		PresidentialPardonForm robertoForm("Roberto");
		PresidentialPardonForm hedForm("Hedonismbot");
		Bureaucrat fry("Fry",140);
		Bureaucrat hermes("Hermes",73);
		Bureaucrat prof("Professor",1);
		fry.signForm(benderForm);
		fry.signForm(robertoForm);
		fry.signForm(hedForm);
		hermes.signForm(benderForm);
		hermes.signForm(robertoForm);
		hermes.signForm(hedForm);
		prof.signForm(benderForm);
		prof.signForm(robertoForm);
		prof.signForm(hedForm);
		fry.executeForm(benderForm);
		hermes.executeForm(benderForm);
		prof.executeForm(benderForm);

	}
	std::cout << std::endl << "🤴🤴🤴🤴PRESIDENTIAL END🤴🤴🤴🤴🤴" << std::endl;
};
int main(void){
	bureaucratTest();
	shrubberyTest();
	robotomyTeste();
	presidentialTest();
	// formTest();
	return (0);
}


void test1()
{
    main_print_banner("TEST 1 signed no exec Shrubbery");
    {
        ShrubberyCreationForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);
        Bureaucrat b("LowBureaucrat_ToExec", 150);

        a.signForm(sr);
        b.executeForm(sr);
    }
}

void test2()
{
    main_print_banner("TEST 2 signed and exec Shrubbery");
    {
        ShrubberyCreationForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

void test3()
{
    main_print_banner("TEST 3 PresidentialPardonForm");
    {
        PresidentialPardonForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

void test4()
{
    main_print_banner("TEST 4 signed and exec Shrubbery");
    {
        RobotomyRequestForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

int main(void)
{
    void (*functions[])() = {
        test1,
        test2,
        test3,
        test4,
        // test5,
        // test6,
        // test7,
        // test8,
        // test9,
        // test10
    };

    for (int test_num = 0; test_num < (int)(sizeof(functions) / sizeof(void *)); test_num++)
    {
        try
        {
            functions[test_num]();
        }
        catch (std::exception &e)
        {
            std::cout << e.what();
        }
        main_print_banner("END TEST");
    }
}

void main_print_banner(std::string title)
{
    std::cout << std::endl;
    std::cout << std::setfill('*') << std::setw(title.size()) << "" << std::endl;
    std::cout << title << std::endl;
    std::cout << std::setfill('*') << std::setw(title.size()) << "" << std::endl;
    std::cout << std::endl;
}


int	main( void )
{
	ShrubberyCreationForm 	shrubbery("Garden");
	Bureaucrat 				bob("bob", 138);

	// test bureaucrat grade too low to execute
	try { bob.executeForm(shrubbery); }
	catch (Form::GradeTooLowException & e) { ERROR(e.what()); }

	// test bureaucrat execute form
	bob.incGrade();
	bob.executeForm(shrubbery);

	RobotomyRequestForm 	robotomy("Calvin");
	bob = Bureaucrat("bob", 46);

	try { bob.executeForm(robotomy); }
	catch (Form::GradeTooLowException & e) { ERROR(e.what()); }
	bob.incGrade();
	bob.executeForm(robotomy);

	PresidentialPardonForm 	presidential("Julian");
	bob = Bureaucrat("bob", 6);

	try { bob.executeForm(presidential); }
	catch (Form::GradeTooLowException & e) { ERROR(e.what()); }
	bob.incGrade();
	bob.executeForm(presidential);

	return 0;
}



int main(void) {
    Bureaucrat oneEmployee("One", 142);
    Bureaucrat twoEmployee("Two", 75);
    Bureaucrat threeEmployee("Three", 3);
    std::cout << "****** Three bureaucrats created : ******" << std::endl;
    std::cout << oneEmployee << std::endl;
    std::cout << twoEmployee << std::endl;
    std::cout << threeEmployee << std::endl;
    ShrubberyCreationForm shrubForm("Manager");
    RobotomyRequestForm robotForm("CEO");
    PresidentialPardonForm presidentialForm(threeEmployee.getName());
    std::cout << "****** Three forms created: ******" << std::endl;
    std::cout << shrubForm << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << presidentialForm << std::endl;
    std::cout << "****** Signing and executing Shrubbery Form: ******"
              << std::endl;
    oneEmployee.signForm(shrubForm);
    oneEmployee.executeForm(shrubForm);
    oneEmployee.increment(7);
    oneEmployee.executeForm(shrubForm);
    std::cout << "****** Signing and executing Robotomy Form: ******"
              << std::endl;
    twoEmployee.signForm(robotForm);
    twoEmployee.executeForm(robotForm);
    std::cout << "****** Signing and executing Presidential Form: ******"
              << std::endl;
    threeEmployee.signForm(presidentialForm);
    threeEmployee.executeForm(presidentialForm);
}