#include <iostream>
#include <array>

class Animal
{
  public:
    virtual void speak()
    {
      std::cout << "Animal" << std::endl;
    }
    virtual ~Animal()=default;
};

class Cat : public Animal
{
  public :
    void speak() override
    {
      std::cout << "meow~" << std::endl;
    }
};


class Dog : public Animal
{
  public :
    void speak() override
    {
      std::cout << "bark!" << std::endl;
    }
};


int main()
{
  std::array<Animal *,5> animals;

  for (auto & animal : animals)
  {
    int i = 0;
    std::cin >> i;
    if (i == 1)
    {
      animal = new Cat();
    }
    else{
      animal = new Dog();
    }
  }
  for (auto & animal : animals)
  {
    animal->speak();
  }
  return (0);
}

