#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string Name;
	int Grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void incrementGrade();
	void decrementGrade();
	std::string getName(void) const;
	int getGrade(void) const;
	void signForm(Form& other);

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