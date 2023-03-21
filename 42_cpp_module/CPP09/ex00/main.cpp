#include "BitcoinExchange.hpp"


bool is_valid_date(const std::string& date_str) {
	std::istringstream iss(date_str);
	int year, month, day;
	char delimiter;
	if (!(iss >> year >> delimiter >> month >> delimiter >> day)) {
		return 0;
	}
	std::tm timeinfo = {};
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	std::mktime(&timeinfo);

  	return	timeinfo.tm_year == year - 1900 &&
			timeinfo.tm_mon == month - 1 &&
			timeinfo.tm_mday == day;
}

int check_error(std::string first, double second)
{
	if (!is_valid_date(first))
	{
		std::cout << "Error: bad input => " << first << std::endl;
		return (1);
	}
	if (second > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (1);
	}
	if (second < 0.0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	return 0;
}


void add_data(std::string file_name, char delimiter1, char delimiter2, map_pair_string_double &maps)
{
	std::ifstream file(file_name.c_str());
	std::string data_getline;
	if (file.is_open() == 0)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	getline(file, data_getline, delimiter1);
	while(getline(file, data_getline, delimiter1))
	{
		std::string key, value;
		std::istringstream data_getline_stream(data_getline);
		getline(data_getline_stream, key, delimiter2);
		getline(data_getline_stream, value, delimiter1);
		maps.insert(pair_string_double(key, value.compare("") == 0 ? -1 : strtod(value.c_str(), NULL)));
	}
}

void add_input(std::string file_name, char delimiter1, char delimiter2, char delimiter3, list_pair_string_double &deque_input)
{
	std::ifstream file(file_name.c_str());
	std::string data_getline;
	if (file.is_open() == 0)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	getline(file, data_getline, delimiter1);
	while(getline(file, data_getline, delimiter1))
	{
		std::string key, value;
		std::istringstream data_getline_stream(data_getline);
		getline(data_getline_stream, key, delimiter2);
		getline(data_getline_stream, value, delimiter3);
		getline(data_getline_stream, value, delimiter1);
		deque_input.push_back(pair_string_double(key, value.compare("") == 0 ? -1 : strtod(value.c_str(), NULL)));
	}
}

int main(int argc, char **argv) {
	
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	map_pair_string_double data;
	list_pair_string_double input;
	for (int i=1; i<argc; ++i)
		add_data(i == 1 ? "data.csv" : argv[i], '\n', ',', data);
	add_input(argv[1], '\n', ' ', '|',input);
	
	map_pair_string_double::iterator find_data;
	for (list_pair_string_double::iterator input_iter = input.begin(); input_iter != input.end(); ++input_iter)
	{
		double price, amount;
		if (check_error(input_iter->first, input_iter->second))
			continue;
		find_data = data.lower_bound(input_iter->first);
		if (find_data->first == data.begin()->first)
		{
			std::cout << "Error: bad input => " << input_iter->first << std::endl;
			continue;
		}
		if (find_data->first == input_iter->first)
			price = find_data->second;
		else
			price = (--find_data)->second;
		amount = input_iter->second;
		std::cout << input_iter->first << " => " << input_iter->second << " = " << price * amount << std::endl;
 	}
}