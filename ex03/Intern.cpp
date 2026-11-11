#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
    f[0] = &makeShrubbery;
    f[1] = &makeRobotomy;
    f[2] = &makePresidentialPardon;
    names[0] = "shrubbery creation";
    names[1] = "robotomy request";
    names[2] = "presidential pardon";
}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            f[i] = other.f[i];
            names[i] = other.names[i];
        }
    }
    return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::makeShrubbery(const std::string &target)
{
    AForm *form = new ShrubberyCreationForm(target);
    return (form);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
    AForm *form = new RobotomyRequestForm(target);
    return (form);
}

AForm *Intern::makePresidentialPardon(const std::string &target)
{
    AForm *form = new PresidentialPardonForm(target);
    return (form);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << names[i] << " form." << std::endl;
            return (f[i](target));
        }
    }
    std::cout << "404: Form not found." << std::endl;
    return (NULL);
}