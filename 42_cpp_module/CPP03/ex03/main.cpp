#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    std::cout << " 무 조 건 werror 추가해서 컴파일 해야함 !!! " << std::endl;
    ClapTrap Kim("Kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    FragTrap Frag_Kim("Frag_Kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    ScavTrap Scav_kim("Scav_kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    DiamondTrap Dia_kim("Dia_kim");
    std::cout << "---------------------------------\n\n" << std::endl;

    Kim.print_status();
    Frag_Kim.print_status();
    Scav_kim.print_status();
    Dia_kim.print_status();


}
