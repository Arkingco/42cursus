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
	int result = 0;
	int result_flag = 0;
	for (int i=0; input_argv[i] != '\0'; ++i)
	{
		char input = input_argv[i];
		if (input == ' ')
			continue;
		if(check_vaild_input(input))
			print_error_exit("Error");
		input_stack.push(input);
		if (input_stack.size() == 3)
		{
			int a, b, sign;

			sign = input_stack.top(); input_stack.pop();
			b = input_stack.top(); input_stack.pop();
			a = result == 0 ? input_stack.top() : result; input_stack.pop();

			if (check_sign(sign) == 0 || check_number(b) == 0 || (check_number(a) == 0 && result == 0))
				print_error_exit("0");
			if (result == 0)
				a = a - '0';
			b = b - '0';

			input_stack.push('0');
			result = calc_input(a, b, sign);
			result_flag = 1;
		}
	}
	if (input_stack.size() != 1 || result_flag == 0)
		print_error_exit("Error");
	std::cout << result << std::endl;
}