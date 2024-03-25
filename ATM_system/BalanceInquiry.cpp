#include"BalanceInquiry.h"
#include<iostream>
#include<iomanip>

BalanceInquiry::BalanceInquiry(int userAccountNumber, vector< Account > &atmAccounts) // constructor
	:accountNumber(userAccountNumber), accounts(atmAccounts)
{
}

void BalanceInquiry::execute() // perform the balance inquiry transaction
{
	cout << fixed << setprecision(2) << endl;
	cout << "Balance Information :" << endl;
	cout << " - Available balance : $" << getAccount(accountNumber, accounts)->getAvailableBalance() << endl;
	cout << " - Total balance :     $" << getAccount(accountNumber, accounts)->getTotalBalance() << endl;
	cout << endl;
}

Account * BalanceInquiry::getAccount(int accountNumber, vector< Account > &accounts)// get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		// return current account if match found
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	} // end for

	return NULL; // if no matching account was found, return NULL
}