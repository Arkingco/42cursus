#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Call" << std::endl;
    for (int i=0; i<100; ++i)
        ideas[i] = "HI i am brain " + i;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Constructor Call" << std::endl;
    for (int i=0; i<100; ++i)
        ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Call" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this == &other)
        return *this;
    std::cout << "Brain Assignment Operator Call" << std::endl;
    for (int i=0; i<100; ++i)
        ideas[i] = other.ideas[i];
    return *this;
}
