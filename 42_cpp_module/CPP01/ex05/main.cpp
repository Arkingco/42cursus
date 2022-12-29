#include "Harl.hpp"

int main()
{
    Harl        harl;
    std::string level;

    std::cout << "choose compain!! ==> DEBUG  \n. \n. \n. \n return anser!!" << std::endl;
    harl.complain("DEBUG");
    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    std::cout << "choose compain!! ==> INFO\n. \n. \n. \n return anser!!" << std::endl;
    harl.complain("INFO");
    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    std::cout << "choose compain!! ==> WARNING\n. \n. \n. \n return anser!!" << std::endl;
    harl.complain("WARNING");
    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    std::cout << "choose compain!! ==> ERROR\n. \n. \n. \n return anser!!" << std::endl;
    harl.complain("ERROR");
}
