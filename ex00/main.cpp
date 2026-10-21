#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Jean", 149);
        Bureaucrat b("Bruno", 2);
        std::cout << a << "\n" << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b = a;
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}