#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : Name("White Paper"), GradeToSign(150), GradeToExecute(150)
{
    isSigned = false;
}

Form::Form(const std::string& name, const int gradeToS, const int gradeToE) : Name(name), GradeToSign(gradeToS), GradeToExecute(gradeToE)
{
    isSigned = false;
    if (gradeToE > 150 || gradeToS > 150)
        throw GradeTooLowException();
    if (gradeToE < 1 || gradeToS < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) : Name(other.Name), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute)
{
    isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form()
{

}

std::string Form::getName(void) const
{
    return (this->Name);
}

bool Form::getIsSigned(void) const
{
    return (this->isSigned);
}

int Form::getGradeToExecute(void) const
{
    return (this->GradeToExecute);
}

int Form::getGradeToSign(void) const
{
    return (this->GradeToSign);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->GradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
    out << "Form: " << other.getName() << "\nGrade To Sign: " << other.getGradeToSign() << "\nGrade To Execute: " << other.getGradeToExecute() << "\nSigned: ";
    if (other.getIsSigned())
        out << "True";
    else
        out << "False";
    return (out);
}