#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>

class Zombie
{
  private:
    std::string name;

  public:
    Zombie(std::string name);
    Zombie();
    ~Zombie();

    void    announce(void);
    void    randomChump(std::string name);
    void    set_name(std::string name);
    Zombie* newZombie(std::string name);
    Zombie* zombieHorde(int N, std::string name);
};

#endif
