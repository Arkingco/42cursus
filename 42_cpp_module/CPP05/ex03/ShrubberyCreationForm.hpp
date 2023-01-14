#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
  private:
    std::string target;
    ShrubberyCreationForm();

  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(std::string name, std::string target);

    ShrubberyCreationForm(const ShrubberyCreationForm& a);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& a);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
