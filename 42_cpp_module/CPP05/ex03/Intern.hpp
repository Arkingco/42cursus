#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
  private:
    std::string target;

  public:
    Intern();
    Intern(std::string target);
    Intern(const Intern& a);
    virtual ~Intern();
    Intern& operator=(const Intern& a);

    AForm* makeForm(std::string name, std::string target);

    class VaildClass : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

#endif