#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
  private:
    const std::string name;
    bool              is_signed;
    const int         sign_grade;
    const int         excute_grade;

  public:
    AForm();
    AForm(std::string name, bool is_signed, int sign_grade, int excute_grade);
    AForm(const AForm& a);
    virtual ~AForm();
    AForm& operator=(const AForm& a);

    std::string get_name() const;
    bool        get_is_signed() const;
    int         get_sign_grade() const;
    int         get_excute_grade() const;

    void         beSigned(Bureaucrat const& A);
    virtual void execute(Bureaucrat const& executor) const = 0;

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

    class FileOpenError : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
