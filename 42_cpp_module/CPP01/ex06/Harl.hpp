#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
  private:
    void debug();
    void info();
    void warning();
    void error();
    void tired();

  public:
    void filter(std::string level);
};

#endif
