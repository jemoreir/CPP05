#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
};

#endif