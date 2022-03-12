/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:51:46 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/12 13:01:23 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
  this->_accountIndex = Account::_nbAccounts;
  this->_amount = initial_deposit;
  this->_nbWithdrawals = 0;

  Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << Account::checkAmount() << ";";
  std::cout << "created" << std::endl;
};

// STATIC ATTR AND METHODS

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
  return Account::_nbAccounts;
};
int Account::getTotalAmount(void) {
  return Account::_totalAmount;
};
int Account::getNbDeposits(void) {
  return Account::_totalNbDeposits;
};
int Account::getNbWithdrawals(void) {
  return Account::_totalNbWithdrawals;
};

void Account::displayAccountsInfos(void)
{
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";";
  std::cout << "total:" << Account::getTotalAmount() << ";";
  std::cout << "deposits:" << Account::getNbDeposits() << ";";
  std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;

  return;
};

void Account::_displayTimestamp(void)
{
  time_t now = time(0);
  tm *timeInfo = localtime(&now);
  char timestamp[19];
  strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", timeInfo);

  std::cout << timestamp;

  return;
}

// CLASS MEMBER FUNCTIONS AND ATTRS

void Account::displayStatus(void) const
{
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << Account::checkAmount() << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;

  return;
};

void	Account::makeDeposit( int deposit ) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";

  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;

  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;

  return;
};

bool	Account::makeWithdrawal( int withdrawal ) {
  if (withdrawal > this->_amount) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  }

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << Account::checkAmount() << ";";
  std::cout << "withdrawal:" << withdrawal << ";";

  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;

  std::cout << "amount:" << Account::checkAmount() << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

  return true;
};

int		Account::checkAmount( void ) const {
  return this->_amount;
};

Account::~Account(void)
{
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << Account::checkAmount() << ";";
  std::cout << "closed" << std::endl;
};
