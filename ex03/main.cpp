#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat Jean("Jean", 15);
        Intern Bruno;
        AForm *form = Bruno.makeForm("", "Android");
        AForm *form1 = Bruno.makeForm("shrubbery creation", "Android");
        AForm *form2 = Bruno.makeForm("robotomy request", "Android");
        AForm *form3 = Bruno.makeForm("presidential pardon", "Android");
        if (form1 && form2 && form3)
        {
            Jean.signForm(*form1);
            Jean.executeForm(*form1);
            Jean.signForm(*form2);
            Jean.executeForm(*form2);
            Jean.signForm(*form3);
            Jean.executeForm(*form3);
        }
        delete form;
        delete form1;
        delete form2;
        delete form3;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}