#include"Deposit.h"
#include<iostream>
#include<iomanip>
#include<math.h>

Deposit::Deposit(int userAccountNumber, vector< Account > &atmAccounts) : accounts(atmAccounts) // 初始化類別成員
{
	accountNumber = userAccountNumber;
//	accounts = atmAccounts;// 不可這樣寫，參考值需要在被宣告時就確定指向，在constructor時，無法改變目標 !!!
}

void Deposit::execute() // perform the deposit transaction
{
	cout << endl;
	bool CorrectInput = false;
	while (!CorrectInput)
	{
		cout << "Please enter a deposit amount in CENTS(or 0 to cancel) : ";
		cin >> amount;
		if (amount < 0 || fmod(amount, 1)!= 0.0)
			cout << "\nYou did not enter a valid selection. Try again." << endl << endl;
		else
			CorrectInput = true;
	}
	
	if (amount != 0)
	{
		cout << endl;
		cout << "Please insert a deposit envelope containing $" << fixed << setprecision(2) << promptForDepositAmount() << " in the deposit slot." << endl;

		getAccount(accountNumber, accounts)->credit(promptForDepositAmount());

		cout << endl;
		cout << "Your envelope has been received." << endl
			<< "NOTE : The money deposited will not be available until we verify the amount of any enclosed cash, and any enclosed checks clear." << endl;
	}
	cout << endl;
}
				
Account * Deposit::getAccount(int accountNumber, vector< Account > &accounts)// get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		// return current account if match found
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	} // end for

	return NULL; // if no matching account was found, return NULL
}

double Deposit::promptForDepositAmount() const // prompt user to enter a deposit amount in cents
{
	return amount / 100;
}