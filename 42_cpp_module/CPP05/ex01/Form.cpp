#include "Form.hpp"

Form::Form() : name("Default_Form"), is_signed(false), sign_grade(150), excute_grade(150)
{
    std::cout << "Form Constructor Call" << std::endl;
}

Form::Form(std::string name, bool is_signed, int sign_grade, int excute_grade)
    : name(name), is_signed(is_signed), sign_grade(sign_grade), excute_grade(excute_grade)
{
    std::cout << "Form Constructor Call" << std::endl;
    if (sign_grade < HIGHEST_GRADE || excute_grade < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    if (sign_grade > LOWEST_GRADE || excute_grade > LOWEST_GRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), excute_grade(other.excute_grade)
{
    std::cout << "Form Constructor Call" << std::endl;
}

Form::~Form()
{
    std::cout << "[" << name << "]"
              << "Form Destructor Call" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return *this;
    std::cout << "Form Assignment Operator Call" << std::endl;
    return *this;
}

std::string Form::get_name() const
{
    return name;
}

bool Form::get_is_signed() const
{
    return is_signed;
}

int Form::get_sign_grade() const
{
    return sign_grade;
}

int Form::get_excute_grade() const
{
    return excute_grade;
}

void Form::beSigned(Bureaucrat& A)
{
    if (is_signed)
        throw Form::AlreadySigned();
    if (A.getGrade() > sign_grade)
        throw Form::GradeTooLowException();
    is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.get_name() << "\nis_signed : " << obj.get_is_signed() << "\nsign_grade : " << obj.get_sign_grade()
       << "\nexcute_grade : " << obj.get_excute_grade() << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException !!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException !!!";
}
const char* Form::AlreadySigned::what() const throw()
{
    return "AlreadySigned !!!";
}
