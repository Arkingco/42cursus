#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

#include <map>
#include <list>
#include <ctime>
#include <fstream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <iostream>

typedef std::map<std::string, double> map_pair_string_double;
typedef std::pair<std::string, double> pair_string_double;
typedef std::list<pair_string_double > list_pair_string_double;

class BitcoinExchange
{
  private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& a);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& a);

  public:

};

#endif