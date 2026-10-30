#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Jean", 20);
        AForm b("B28", 50, 50);
        std::cout << b << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}