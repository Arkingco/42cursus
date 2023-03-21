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

void print_error_exit(std::string msg)
{
	std::cout << msg << std::endl;
	exit(1);
}

int main(int argc, char **argv) {
	
	if (argc != 2)
		print_error_exit("not enough value");

	std::stack<int> input_stack;
	std::string input_argv = argv[1];
	for (int i=0; input_argv[i] != '\0'; ++i)
	{
		char input = input_argv[i];
		if (input == ' ')
			continue;
		if(check_vaild_input(input))
			print_error_exit("Error");
		if (check_sign(input))
		{
			int a, b;
			if (input_stack.size() < 2)
				print_error_exit("Error");
			a = input_stack.top(); input_stack.pop();
			b = input_stack.top(); input_stack.pop();
			input_stack.push(calc_input(b, a, input));
		}
		else
			input_stack.push(input - '0');
	}
	if(input_stack.size() != 1)
		print_error_exit("Error");
	std::cout << input_stack.top() << std::endl;
}