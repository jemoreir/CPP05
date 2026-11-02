#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat Jean("Jean", 100);
        ShrubberyCreationForm B28("garden");
        Jean.signForm(B28);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}