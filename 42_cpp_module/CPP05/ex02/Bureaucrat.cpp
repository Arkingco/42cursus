#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat Constructor Call" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat Constructor Call" << std::endl;
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Bureaucrat Constructor Call" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[" << name << "]"
              << "Bureaucrat Destructor Call" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return *this;
    grade = other.grade;
    std::cout << "Bureaucrat Assignment Operator Call" << std::endl;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::increment()
{
    if (grade - 1 < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    grade = grade - 1;
    who_am_i();
}

void Bureaucrat::decrement()
{
    if (grade + 1 > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    grade = grade + 1;
    who_am_i();
}

void Bureaucrat::who_am_i()
{
    std::cout << name << ", bureaucrat grade " << grade << "." << std::endl;
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed  " << form << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn’t sign " << form << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException !!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException !!!";
}
