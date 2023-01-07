#include <array>
#include <iostream>

class Animal
{
  public:
    virtual void speak()
    {
        std::cout << "Animal" << std::endl;
    }
    virtual ~Animal();
};

class Cat : public Animal
{
  public:
    void speak()
    {
        std::cout << "meow~" << std::endl;
    }
};

class Dog : public Animal
{
  public:
    void speak()
    {
        std::cout << "bark!" << std::endl;
    }
};

int main()
{
    std::array<Animal*, 5> animals;

    Animal polyAnimal = Dog();
    
    // for (int i = 0; i < 5; ++i)
    // {
    //     int in = 0;
    //     std::cin >> in;
    //     if (i == in)
    //     {
    //         animals[i] = new Cat();
    //     }
    //     else
    //     {
    //         animals[i] = new Dog();
    //     }
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     animals[i]->speak();
    // }
    return (0);
}
