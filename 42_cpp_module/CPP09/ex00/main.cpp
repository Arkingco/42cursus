#include "BitcoinExchange.hpp"

bool is_valid_date(const std::string& date_str) {
	std::istringstream iss(date_str);
	int year, month, day;
	char delimiter;
	if (!(iss >> year >> delimiter >> month >> delimiter >> day)) {
		return false;
	}
	std::tm timeinfo = {};
	timeinfo.tm_year = year - 1900; // 1900년 기준 연도로 변환
	timeinfo.tm_mon = month - 1; // 0부터 시작하는 월로 변환
	timeinfo.tm_mday = day;
	std::mktime(&timeinfo); // 입력된 시간을 초로 변환하여 구조체에 저장

  // 구조체에 저장된 값이 입력된 값과 일치하는지 확인
  return timeinfo.tm_year == year - 1900 &&
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
		std::cout << "Error: too low a number." << std::endl;
		return (1);
	}

	return 0;
}


void add_map_data(std::string file_name, char delimiter1, char delimiter2, std::map<std::string, double> &maps)
{
	std::ifstream file(file_name.c_str());
	std::string data_getline;
	if (file.is_open() == 0)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	getline(file, data_getline, delimiter1); // first line pass
	while(getline(file, data_getline, delimiter1))
	{
		std::string key, value;
		std::istringstream data_getline_stream(data_getline);
		getline(data_getline_stream, key, delimiter2);
		getline(data_getline_stream, value, delimiter1);
		maps.insert(std::pair<std::string, double>(key, value.compare("") == 0 ? -1 : (value.c_str(), NULL)));
	}
}

void add_array_data(std::string file_name, char delimiter1, char delimiter2, std::pair<std::string, double> *array)
{
	std::ifstream file(file_name.c_str());
	std::string data_getline;
	if (file.is_open() == 0)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	getline(file, data_getline, delimiter1); // first line pass
	int i = 0;
	while(getline(file, data_getline, delimiter1))
	{
		std::string key, value;
		std::istringstream data_getline_stream(data_getline);
		getline(data_getline_stream, key, delimiter2);
		getline(data_getline_stream, value, delimiter1);
		array[i].first = key;
		array[i].second = value.compare("") == 0 ? -1 : (value.c_str(), NULL);
		++i;
	}
}

int main(int argc, char **argv) {
	
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	std::map<std::string, double> data;
	std::pair<std::string, double> input[10000];
	for (int i=1; i<argc; ++i)
		add_map_data(i == 1 ? "data.csv" : argv[i], '\n', ',', data);
	add_array_data(argv[1], '\n', '|', input);
	
	for (std::map<std::string, double>::iterator input_iter = input.begin(); input_iter != input.end(); ++input_iter)
	{
		if (check_error(input_iter->first, input_iter->second))
			continue;
		for(std::map<std::string, double>::iterator data_iter = data.begin(); data_iter != data.end(); ++data_iter)
		{
			BitcoinExchange coin(data_iter->second, input_iter->second);
			if (input_iter->first < data_iter->first)
			{
				std::cout << " < here! " << std::endl;
			}
			if (input_iter->first == data_iter->first)
			{
				std::cout << " == here! " << std::endl;
			}
		}
		std::cout << input_iter->first << " => " << input_iter->second << " = " << std::endl;
 	}
}