#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
  protected:
    const std::string name;
  
  public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& a);
    virtual ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& a);
};

#endif
