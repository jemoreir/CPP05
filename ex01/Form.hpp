#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string Name;
    const int GradeToSign;
    const int GradeToExecute;
    bool isSigned;
public:
    Form();
    Form(const std::string& name, const int gradeToS, const int gradeToE);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& other);

#endif