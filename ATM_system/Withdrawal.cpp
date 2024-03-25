#include"Withdrawal.h"
#include<iostream>

Withdrawal::Withdrawal(int userAccountNumber, vector< Account > &atmAccounts, int &atmRemainingBills)
	:accounts(atmAccounts),remainingBills(atmRemainingBills)
{
	accountNumber = userAccountNumber;
}

void Withdrawal::execute() // perform the withdrawal transaction
{
	bool CorrectInput = false; 
	while (!CorrectInput)
	{
		CorrectInput = true;
		switch (displayMenuOfAmounts())
		{
		case 1:
			amount = 20;
			break;
		case 2:
			amount = 40;
			break;
		case 3:
			amount = 60;
			break;
		case 4:
			amount = 100;
			break;
		case 5:
			amount = 200;
			break;
		case 6:
			amount = 0;
			cout << endl;
			break;
		default:
			cout << "\nYou did not enter a valid selection. Try again." << endl;
			CorrectInput = false;
			break;
		}
		if (CorrectInput)
			if (amount > getAccount(accountNumber, accounts)->getAvailableBalance())
			{
				cout << "\nInsufficient balance! Try again." << endl;
				CorrectInput = false;
			}
			else
			{
				getAccount(accountNumber, accounts)->debit(amount);
				if (amount != 0)
					cout << "\nPlease take your cash from the cash dispenser.\n" << endl;
			}
	}
}

Account * Withdrawal::getAccount(int accountNumber, vector< Account > &accounts)// get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		// return current account if match found
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	} // end for

	return NULL; // if no matching account was found, return NULL
}

// display a menu of withdrawal amounts and the option to cancel;
// return the chosen amount or 0 if the user chooses to cancel
int Withdrawal::displayMenuOfAmounts() const
{
	cout << "\nWithdrawal options :" << endl;
	cout << "1 - $20" << endl;
	cout << "2 - $40" << endl;
	cout << "3 - $60" << endl;
	cout << "4 - $100" << endl;
	cout << "5 - $200" << endl;
	cout << "6 - Cancel transaction\n" << endl;

	cout << "Choose a withdrawal option(1 - 6) : ";
	int choice;
	cin >> choice;
	return choice;
}