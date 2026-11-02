#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    Target = "white_paper";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    Target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137)
{
    Target = other.Target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        Target = other.Target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::beExecute(const Bureaucrat& bureaucrat)
{
    if (getIsSigned() == true && bureaucrat.getGrade() <= 137)
    {
        std::ofstream file(Target + "_shrubbery");
        if (!file.is_open())
            std::cerr << "Error: No permission to open file.\n";
        else
        {
            file << "    *\n"
                    "   / \\\n"
                    "  /   \\\n"
                    " / | | \\\n"
                    "   | |  \\\n";
            
        }
    }
}