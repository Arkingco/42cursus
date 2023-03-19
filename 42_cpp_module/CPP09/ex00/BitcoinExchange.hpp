#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

#define DATA_NAME "data.csv"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>

typedef std::pair<std::string, double> data_type;
class BitcoinExchange
{
  private:
    double      price;
    double      amount;

  public:
    BitcoinExchange();
    BitcoinExchange(double price, double amount);
    BitcoinExchange(const BitcoinExchange& a);

    double get_price();

    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& a);

};

#endif