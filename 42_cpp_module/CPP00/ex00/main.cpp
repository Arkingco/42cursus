#include <iostream>
#include "Animal.hpp"
// namespace + reference 사용법 
void namespace_referen()
{
	std::string name;
	std::string& name_reference = name;

	std::cin >> name;

	std::cout << "real name = " << name << std::endl;
	std::cout << "name reference = " << name_reference << std::endl;
	std::cout << &name << " " << &name_reference << std::endl;

	std::cout << "Hello, World" << std::endl;
}

void new_delete()
{
	int arr_size;
	int *arr;
	
	std::cout << "arr_size : ";
	std::cin >> arr_size;
	arr = new int[arr_size];
	for (int i = 0; i < arr_size; ++i)
		std::cin >> arr[i];
	for (int i = 0; i < arr_size; ++i)
		std::cout << i << "th element of list : " << arr[i] << std::endl;
	delete[] arr;
	return ;
}

void animal_class()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
}

int main()
{

	// namespace_referen();
	// new_delete();
	animal_class();
	return (0);
}
