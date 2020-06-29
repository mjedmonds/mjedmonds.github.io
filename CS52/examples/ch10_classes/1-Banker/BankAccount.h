//------------------------------------------------------------------
// INTERFACE FILE: BankAccount.h
//
// Defines class BankAccount
//
//-------------------------------------------------------------------

#ifndef BANKACCOUNT_H   // Avoid redeclaring class BankAccount.
#define BANKACCOUNT_H   // This code is compiled only once
#include <string>    // for class string
using namespace std;

//BankAccount class definition
class BankAccount {
public:  // class member functions

	//--constructors
	BankAccount();

	// constructs a bank account with initName as the name and initBalance as the balance
	BankAccount(string initName, double initBalance);

	//--modifiers

	void deposit(double depositAmount);

	void withdraw(double withdrawalAmount);

	//--accessors

	double balance() const;

	string name() const;

	void setName( string initName );

private:
	string my_name;    // Uniquely identify an object
	double my_balance; // Store the current balance (non-persistent)
};  // NOTICE THE SEMICOLON AFTER THE CLOSING CURLY BRACE

#endif   // ifndef BANKACCOUNT_H
