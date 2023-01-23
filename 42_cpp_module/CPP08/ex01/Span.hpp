#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
  private:
    unsigned int N;
    std::vector<int> elements;
    Span();

  public:
    Span(unsigned int N);
    Span(const Span& a);
    ~Span();
    Span& operator=(const Span& a);
    
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    void printVector();
    void addManyNumber();
};

class TooManyElement : public std::exception
{
	virtual const char * what() const throw();
};

class NotEoughElement : public std::exception
{
	virtual const char * what() const throw();
};

#endif
