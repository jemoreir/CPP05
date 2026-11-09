#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    Target = "Jhon Doe";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    Target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    Target = other.Target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        Target = other.Target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    AForm::checkExecution(executor);
    int b = rand();
    std::cout << "Bi...Bo...Fuuuuuuu...Taq..taq" << std::endl;
    if (b % 2 == 0)
        std::cout << Target << " has been robotomized." << std::endl;
    else
        std::cout << "Robotomy has failed." << std::endl;
}