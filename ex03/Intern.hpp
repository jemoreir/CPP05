#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
private:
    AForm* (*f[3])(const std::string&);
    std::string names[3];
    static AForm *makeShrubbery(const std::string& target);
    static AForm *makeRobotomy(const std::string& target);
    static AForm *makePresidentialPardon(const std::string& target);
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm *makeForm(std::string form, std::string target);
};

#endif