#include <iostream>

int main()
{
    std::string brain("HI THIS IS BRAIN");

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "stringPTR address : " << stringPTR << std::endl;
    std::cout << "stringREF address : " << &stringREF << std::endl;

    std::cout << "stringPTR value : " << *stringPTR << std::endl;
    std::cout << "stringREF value : " << stringREF << std::endl;
}
    