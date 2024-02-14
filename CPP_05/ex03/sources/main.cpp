#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main (void)
{
	try {
		Intern someRandomIntern;
		AForm* rrf[3];
		rrf[0] = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf[1] = someRandomIntern.makeForm("presidential pardon", "Bender");
		rrf[2] = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Bureaucrat bender("Bender", 1);
		rrf[0]->beSigned(bender);
		rrf[0]->execute(bender);
		rrf[1]->beSigned(bender);
		rrf[1]->execute(bender);
		rrf[2]->beSigned(bender);
		rrf[2]->execute(bender);
		delete rrf[0];
		delete rrf[1];
		delete rrf[2];
		rrf[2] = someRandomIntern.makeForm("abc", "Bender");
		delete rrf[2];
	}
	catch (std::exception & e)
	{	std::cout << e.what() << std::endl; }
	return 0;
}