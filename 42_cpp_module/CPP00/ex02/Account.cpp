#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    _totalAmount = _totalAmount + initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount = _amount + deposit;
    _nbDeposits = _nbDeposits + 1;
    _totalNbDeposits = _totalNbDeposits + 1;
    _totalAmount = _totalAmount + deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit
              << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = _amount;

    _displayTimestamp();
    if (_amount < withdrawal)
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
    else
    {
        _amount = _amount - withdrawal;
        _nbWithdrawals = _nbWithdrawals + 1;
        _totalNbWithdrawals = _totalNbWithdrawals + 1;
        _totalAmount = _totalAmount - withdrawal;

        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return (0);
}

int Account::checkAmount() const
{
    std::cout << "checkAmount" << std::endl;
    return (0);
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t t = time(NULL);
    std::tm*    local_time = localtime(&t);
    std::cout << "[" << local_time->tm_year + 1900 << local_time->tm_mon + 1 << local_time->tm_mday << "_"
              << local_time->tm_hour << local_time->tm_min << local_time->tm_sec << "] ";
}
