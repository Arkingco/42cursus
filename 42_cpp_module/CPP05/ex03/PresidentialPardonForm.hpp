#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm : public AForm
{
  private:
    std::string target;
    PresidentialPardonForm();

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(std::string name, std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& a);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& a);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
