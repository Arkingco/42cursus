#include <iostream>

class Animal {
	private:
		int food;
		int weight;
	
	public:
		void set_animal(int _food, int _weight)
		{
			food = _food;
			weight = _weight;
		}
		void increase_food(int inc)
		{
			food += inc;
			weight += (inc / 3);
		}
		void view_stat()
		{
			std::cout << "이 동물의 food : " << food << std::endl;
			std::cout << "이 동물의 weight : " << weight << std::endl;
		}
};
