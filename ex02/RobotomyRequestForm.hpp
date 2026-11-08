#ifndef ROBOTOMY_REQUEST_FORMR_HPP
# define ROBOTOMY_REQUEST_FORMR_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
    std::string Target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    void execute(const Bureaucrat& executor) const;
};

#endif