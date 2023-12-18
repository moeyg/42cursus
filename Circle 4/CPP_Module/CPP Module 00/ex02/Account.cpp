#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

Account::Account()
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created" << std::endl;

	_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:" << deposit << ';';

	_amount += deposit;
	_totalAmount += deposit;

	std::cout << "amount:" << _amount << ';';
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';

	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	std::cout << "withdrawal:" << withdrawal << ';';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ';';
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount() const { return _amount; }

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    std::cout << '[';
    std::cout << 1900 + localTime->tm_year;
    std::cout << (localTime->tm_mon + 1 < 10 ? '0' : "") << localTime->tm_mon + 1;
    std::cout << (localTime->tm_mday < 10 ? '0' : "") << localTime->tm_mday;
    std::cout << '_';
    std::cout << (localTime->tm_hour < 10 ? '0' : "") << localTime->tm_hour;
    std::cout << (localTime->tm_min < 10 ? '0' : "") << localTime->tm_min;
    std::cout << (localTime->tm_sec < 10 ? '0' : "") << localTime->tm_sec;
    std::cout << "] ";
}
