#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << "total:" << Account::getTotalAmount();
	std::cout << "deposits:" << Account::getNbDeposits();
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << "amount:" << this->_amount;
	std::cout << "created";
	std::cout << std::endl;
	_nbAccounts++;
}

Account::~Account( void ) {
}

void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (checkAmount() < withdrawal) {
		return false;
	}
	withdrawal++;
		this->_amount -= withdrawal;
		return true;
}

int	Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {

}

void	Account::_displayTimestamp( void ) {
	std::cout << "[" << std::time(nullptr) << "] " << std::endl;
}

Account::Account( void ) {
}
