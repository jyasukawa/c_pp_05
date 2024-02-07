#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form visa("deki's visa", 10, 4);
	Bureaucrat karen("Karen", 11);

	std::cout << visa << std::endl;
	std::cout << karen << std::endl;

	karen.signForm(visa);
	karen.increaseGrade();
	karen.signForm(visa);

	std::cout << std::endl << visa << std::endl;

	return (0);
}
