#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : Name("White Paper"), GradeToSign(150), GradeToExecute(150)
{
    isSigned = false;
}

AForm::AForm(const std::string& name, const int gradeToS, const int gradeToE) : Name(name), GradeToSign(gradeToS), GradeToExecute(gradeToE)
{
    isSigned = false;
    if (gradeToE > 150 || gradeToS > 150)
        throw GradeTooLowException();
    if (gradeToE < 1 || gradeToS < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : Name(other.Name), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute)
{
    isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName(void) const
{
    return (this->Name);
}

bool AForm::getIsSigned(void) const
{
    return (this->isSigned);
}

int AForm::getGradeToExecute(void) const
{
    return (this->GradeToExecute);
}

int AForm::getGradeToSign(void) const
{
    return (this->GradeToSign);
}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() <= this->GradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
    out << "AForm: " << other.getName() << "\nGrade To Sign: " << other.getGradeToSign() << "\nGrade To Execute: " << other.getGradeToExecute() << "\nSigned: ";
    if (other.getIsSigned())
        out << "True";
    else
        out << "False";
    return (out);
}