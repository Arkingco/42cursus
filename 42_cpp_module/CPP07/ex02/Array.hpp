#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
  private:
    T 				*value;
    unsigned int 	length;

  public:
    Array() : value(NULL), length(0)
    {
   	   std::cout << "Default constructor Call" << std::endl;
    }

    Array(unsigned int n) : value(new T[n]), length(n)
    {
   	   std::cout << "constructor Call" << std::endl;
    }

    Array(const Array& other) : value(new T[other.length]), length(other.length)
    {
		for (unsigned int i=0; i<other.length; ++i)
			value[i] = other.value[i];
		length = other.length;

		std::cout << "Copy constructor Call" << std::endl;
    }

    Array& operator=(const Array& other)
    {
		if (this == &other)
			return *this;
		if (value != NULL)
			delete[] value;
		value = new T[other.length];
		for (unsigned int i=0; i<other.length; ++i)
			value[i] = other.value[i];
		length = other.length;

		std::cout << "Array Assignment Operator Call" << std::endl;
		return *this;
    }

    T& operator[] (unsigned int idx) const
    {
		if(idx < 0 || idx >= length)
			throw OutOfBindException();
		return value[idx];
    }

	unsigned int size() const
	{
		return length;
	}

	class OutOfBindException : public std::exception
	{
		virtual const char * what() const throw(){
			return "out of bound!";
		}
	};
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj)
{
	for (unsigned int i = 0; i<obj.size(); ++i)
		os << obj[i] << " ";
	os << std::endl;
	return(os);
}

#endif