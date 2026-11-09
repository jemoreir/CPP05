#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    Target = "Empty Place";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    Target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    Target = other.Target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        Target = other.Target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::checkExecution(executor);
    std::ofstream file((Target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("File can't be open!");
    else
    {
        file << "   *\n"
                "  / \\\n"
                " /   \\\n"
                "/ | | \\\n"
                "  | |\n";
    }
}