#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : price(0), amount(0)
{

}

BitcoinExchange::BitcoinExchange(double date, double amount) : price(date), amount(amount) {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	price = other.price;
	amount = other.amount;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

double BitcoinExchange::get_price()
{
	return price * amount;
}