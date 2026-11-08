#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string Name;
    const int GradeToSign;
    const int GradeToExecute;
    bool isSigned;
protected:
    void checkExecution(const Bureaucrat& other) const;
public:
    AForm();
    AForm(const std::string& name, const int gradeToS, const int gradeToE);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

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

class FormNotSigned : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Form not signed.");
	}
};
};

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif