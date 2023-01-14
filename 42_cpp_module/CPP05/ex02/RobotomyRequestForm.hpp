#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class RobotomyRequestForm : public AForm
{
  private:
    std::string target;
    RobotomyRequestForm();

  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& a);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& a);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
