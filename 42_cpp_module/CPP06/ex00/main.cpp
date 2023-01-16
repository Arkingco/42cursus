#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "plz input vaild case" << std::endl;
        return 0;
    }
    Convert convert = Convert(argv[1]);
}
