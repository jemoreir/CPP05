#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string Name;
    bool isSigned;
    const int GradeToSign;
    const int GradeToExecute;
public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

class GradeTooHighException : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Grade Too High.");
	}
};

class GradeTooLowException : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Grade Too Low.");
	}
};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif