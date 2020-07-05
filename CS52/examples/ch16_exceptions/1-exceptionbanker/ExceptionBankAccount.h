//------------------------------------------------------------------
// INTERFACE FILE: baccount.h
//
// Defines class BankAccount
//
//-------------------------------------------------------------------
// SAFEGUARDS AND INCLUDES
#ifndef BANKACCOUNT_H   // Avoid redeclaring class BankAccount.
#define BANKACCOUNT_H   // This code is compiled only once
#include <string>    // for class string

namespace cs52 {

///////////////////////////////////////////
/////// class BankAccount defintion ///////
///////////////////////////////////////////

class BankAccount {
public:  // class member functions

//--constructors
	BankAccount();

	BankAccount(std::string initName, double initBalance);
	// post: A BankAccount with two arguments when called like this:
	//       BankAccount anAcct("Hall", 100.00);

//--modifiers

	void deposit(double depositAmount);
	// post: depositAmount is credited to this object's balance

	void withdraw(double withdrawalAmount);
	// post: withdrawalAmount is debited from this object's balance

//--accessors

	double balance() const;
	// post: return this account's current balance

	std::string name() const;
    // post return the account name

	void setName( std::string initName );
	// post updates the member variable my_name

	// ADDED CODE BEGINS HERE
	friend std::ostream& operator << ( std::ostream& outs, const BankAccount& b );
	friend std::istream& operator >> ( std::istream& ins, BankAccount& b );
	friend BankAccount operator + ( const BankAccount& left, const BankAccount& right );
	friend BankAccount operator - ( const BankAccount& left, const BankAccount& right );
	friend bool operator ==( const BankAccount& left, const BankAccount& right );
	friend bool operator < ( const BankAccount& left, const BankAccount& right );
	friend bool operator > ( const BankAccount& left, const BankAccount& right );

private:
	std::string my_name;    // Uniquely identify an object
	double my_balance; // Store the current balance (non-persistent)
};

}

#endif   // ifndef BANKACCOUNT_H
