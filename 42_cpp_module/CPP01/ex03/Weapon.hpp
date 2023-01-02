#ifndef WEAPON
#define WEAPON

#include <iostream>

class Weapon
{
  private:
    std::string type;

  public:
    Weapon(std::string type);
    std::string getType();
    void        setType(std::string type);
};

#endif
