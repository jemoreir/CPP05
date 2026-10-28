#include "Form.hpp"

Form::Form() : Name("Jhon Doe"), GradeToSign(150), GradeToExecute(150)
{
    isSigned = false;
}

Form::Form(const Form& other) : Name(other.Name), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute)
{
    isSigned = other.isSigned;
}