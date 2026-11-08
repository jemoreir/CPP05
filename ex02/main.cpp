#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        time_t a = time(NULL);
        srand(a);
        Bureaucrat Jean("Jean", 1);
        ShrubberyCreationForm B28("garden");
        Jean.executeForm(B28);
        Jean.signForm(B28);
        Jean.executeForm(B28);
        std::cout << "----------//----------" << std::endl;
        RobotomyRequestForm B29("Jean");
        Jean.executeForm(B29);
        Jean.signForm(B29);
        Jean.executeForm(B29);
        Jean.executeForm(B29);
        Jean.executeForm(B29);
        std::cout << "----------//----------" << std::endl;
        PresidentialPardonForm B30("Jean");
        Jean.executeForm(B30);
        Jean.signForm(B30);
        Jean.executeForm(B30);
        std::cout << "----------//----------" << std::endl;
        AForm *form = new ShrubberyCreationForm("empty place");
        Jean.executeForm(*form);
        Jean.signForm(*form);
        Jean.executeForm(*form);
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}