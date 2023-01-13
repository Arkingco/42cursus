#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;

    std::cout << "\n\n ---------my test1 ------------ \n " << std::endl;

    int n;
    std::cin >> n;
    Animal* animals[n];

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        if (a == 1)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << "\n" << std::endl;
    for (int i = 0; i < n; ++i)
        delete animals[i];

    std::cout << "\n\n ---------my test2 ------------ \n " << std::endl;
    Dog a;
    Dog b;
    Cat c;
    Cat d;
    std::cout << "--- Assignment -----" << std::endl;
    c = d;
    a = b;
}
