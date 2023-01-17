#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
  private:
    const std::string name;
    bool              is_signed;
    const int         sign_grade;
    const int         excute_grade;

  public:
    Form();
    Form(std::string name, bool is_signed, int sign_grade, int excute_grade);
    Form(const Form& a);
    ~Form();
    Form& operator=(const Form& a);

    std::string get_name() const;
    bool        get_is_signed() const;
    int         get_sign_grade() const;
    int         get_excute_grade() const;

    void beSigned(Bureaucrat& A);

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

    class AlreadySigned : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
