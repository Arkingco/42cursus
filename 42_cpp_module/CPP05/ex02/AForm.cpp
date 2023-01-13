#include "AForm.hpp"

AForm::AForm() : name("Default_AForm"), is_signed(false), sign_grade(150), excute_grade(150)
{
    std::cout << "AForm Constructor Call" << std::endl;
}

AForm::AForm(std::string name, bool is_signed, int sign_grade, int excute_grade)
    : name(name), is_signed(is_signed), sign_grade(sign_grade), excute_grade(excute_grade)
{
    std::cout << "AForm Constructor Call" << std::endl;
    if (sign_grade < HIGHEST_GRADE || excute_grade < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    if (sign_grade > LOWEST_GRADE || excute_grade > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), excute_grade(other.excute_grade)
{
    std::cout << "AForm Constructor Call" << std::endl;
}

AForm::~AForm()
{
    std::cout << "[" << name << "]"
              << "AForm Destructor Call" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this == &other)
        return *this;
    std::cout << "AForm Assignment Operator Call" << std::endl;
    return *this;
}

std::string AForm::get_name() const
{
    return name;
}

bool AForm::get_is_signed() const
{
    return is_signed;
}

int AForm::get_sign_grade() const
{
    return sign_grade;
}

int AForm::get_excute_grade() const
{
    return excute_grade;
}

void AForm::beSigned(Bureaucrat const& A)
{
    if (is_signed)
    {
        std::cout << "Already Signed" << std::endl;
        return;
    }
    if (A.getGrade() > sign_grade)
    {
        A.signForm(false, *this);
        throw AForm::GradeTooLowException();
    }
    is_signed = true;
    A.signForm(true, *this);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.get_name() << "\nis_signed : " << obj.get_is_signed() << "\nsign_grade : " << obj.get_sign_grade()
       << "\nexcute_grade : " << obj.get_excute_grade() << std::endl;
    return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException !!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException !!!";
}

const char* AForm::FileOpenError::what() const throw()
{
    return "FileOpenError !!!";
}
