#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
  private:
    const std::string name;
    int               grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& a);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& a);

    std::string getName() const;
    int         getGrade() const;
    void        increment(int increment_grade);
    void        decrement(int decrement_grade);
    void        who_am_i();

    void signForm(AForm& form) const;
    void executeForm(AForm const& form);

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
