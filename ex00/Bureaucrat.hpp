#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
private:
	const std::string Name;
	int Grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string getName(void) const;
	int getGrade(void) const;

class GradeTooHighException : public std::exception
{

};

class GradeTooLowException : public std::exception
{

};

};

#endif