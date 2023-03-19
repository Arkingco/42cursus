#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span& other)
{
    elements.assign(other.elements.begin(), other.elements.end());
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return *this;
    elements.assign(other.elements.begin(), other.elements.end());
    return *this;
}

void Span::addNumber(int num)
{
    if (elements.size() >= N)
        throw TooManyElement();
    elements.push_back(num);
    std::cout << "add vector num : " << num << std::endl;
}

int Span::shortestSpan()
{
    if (elements.size() == 0 || elements.size() == 1)
        throw NotEoughElement();
    int sortTest = std::numeric_limits<int>::max();
    std::sort(elements.begin(), elements.end());
    for (size_t i=0; i<elements.size() - 1; ++i)
    {
        int diff = elements[i + 1] - elements[i];
        if (sortTest > diff)
            sortTest = diff;
    }
    return sortTest;
}

int Span::longestSpan()
{
    if (elements.size() == 0 || elements.size() == 1)
            throw NotEoughElement();
    std::sort(elements.begin(), elements.end());
    return (elements[elements.size() - 1] - elements[0]);
}

void Span::addManyNumber()
{
    for (unsigned int i=0; i<N; ++i){
        elements.push_back(rand() % 21474783647);
    }
}

const char * TooManyElement::what() const throw(){
    return "TooManyElement !!";
}

const char * NotEoughElement::what() const throw(){
    return "NotEoughElement !!";
}