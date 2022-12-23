#include<iostream>

int main(int argc, char **argv)
{
	std::string input;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i=1; i<argc; ++i)
	{
		input = static_cast<std::string>(argv[i]);
		for (int j=0; j<static_cast<int>(input.size()); ++j)
			std::cout << static_cast<char>(toupper(input[j]));
	}
	std::cout << std::endl;
}
