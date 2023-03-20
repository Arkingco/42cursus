#include "RPN.hpp"

int calc_input(int a, int b, int sign)
{
	if (sign == '+')
		return a + b;
	else if (sign == '-')
		return a - b;
	else if (sign == '*')
		return a * b;
	else
		return a / b;
}

int check_number(char a)
{
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

int check_sign(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return 1;
	return 0;
}

int check_vaild_input(char a)
{
	if (check_number(a) || check_sign(a))
		return 0;
	return 1;
}

int main(int argc, char **argv) {
	
	if (argc != 2)
	{
		std::cout << "Error: not enuogh input." << std::endl;
		return (1);
	}

	std::stack<int> input_stack;
	std::string input_argv = argv[1];
	int result = 0;
	for (int i=0; input_argv[i] != '\0'; ++i)
	{
		char input = input_argv[i];
		if (input == ' ')
			continue;
		if(check_vaild_input(input))
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		input_stack.push(input);
		if (input_stack.size() == 3)
		{
			int a, b, sign;

			sign = input_stack.top();
			input_stack.pop();

			b = input_stack.top();
			input_stack.pop();
			b = b - '0';

			a = i < 5 ? input_stack.top() - '0' : result;
			input_stack.pop();

			result = calc_input(a, b, sign);
			input_stack.push(result);
		}
	}
	std::cout << result << std::endl;
}