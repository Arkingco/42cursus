#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
  protected:
    std::string ideas[100];
  
  public:
    Brain();
    Brain(const Brain& a);
    virtual ~Brain();
    Brain& operator=(const Brain& a);
};

#endif
