#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    Target = "Jhon Doe";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    Target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    Target = other.Target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        Target = other.Target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    AForm::checkExecution(executor);
    std::cout << Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}