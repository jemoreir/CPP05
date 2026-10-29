#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : Name("Jhon Doe"), Grade(150)
{
    
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : Name(name), Grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name(other.getName()), Grade(other.getGrade())
{
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        Grade = other.Grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName(void) const
{
    return (Name);
}

int Bureaucrat::getGrade(void) const
{
    return (Grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return (out);
}

void Bureaucrat::incrementGrade()
{
    if (Grade == 1)
        throw GradeTooHighException();
    else
        Grade--;
}

void Bureaucrat::decrementGrade()
{
    if (Grade == 150)
        throw GradeTooLowException();
    else
        Grade++;
}

void Bureaucrat::signForm(Form& other)
{
    try
    {
        other.beSigned(*this);
        std::cout << Name << " signed " << other.getName() << std::endl;
    }
    catch (const std::exception& e)
    {    
        std::cout << Name << " couldn't sign " << other.getName() << " because " << e.what() << std::endl;
    }
}