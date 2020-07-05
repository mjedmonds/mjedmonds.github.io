//--------------------------------------------------------------------
// IMPLEMENTATION FILE: baccount.cpp
//
// Implements 1. class BankAccount member functions
//
//--------------------------------------------------------------------
#include "ExceptionBankAccount.h"  // allows for separate compilation if you want
#include <iostream>    // for ostream << and istream >>
#include <string>      // for class string
#include <stdexcept>   // supports Linux exception classes

using namespace std;

namespace cs52 {

//--constructors

BankAccount::BankAccount()
{
  my_name = "?name?";
  my_balance = 0.0;
}

BankAccount::BankAccount(string initName, double initBalance)
{
  my_name = initName;
  my_balance = initBalance;
}

//--modifiers

void BankAccount::deposit(double depositAmount)
{
  my_balance = my_balance + depositAmount;
}

void BankAccount::withdraw(double withdrawalAmount)
{
  my_balance = my_balance - withdrawalAmount;
}

//--accessors

double BankAccount::balance() const
{
  return my_balance;
}

string BankAccount::name() const
{
  return my_name;
}

void BankAccount::setName( string initName )
{
  my_name = initName;
}


// NEW CODE STARTS HERE
std::ostream& operator << ( std::ostream& outs, const BankAccount& b ) {
	outs << b.my_name << " " << b.my_balance << endl;
	return( outs );
}

std::istream& operator >> ( std::istream& ins, BankAccount& b ) {
	ins >> b.my_name >> b.my_balance;
	return( ins );
}

BankAccount operator + ( const BankAccount& left, const BankAccount& right ) {
	BankAccount newB;
	if (left.my_name == right.my_name) {
		newB.deposit( left.my_balance );
		newB.deposit( right.my_balance );
	}
	else {
		cerr << "YIKES!  These two accounts can't be added together since the names differ!" << endl;
		throw logic_error( "Bad account names" );
	}
	return( newB );
}

BankAccount operator - ( const BankAccount& left, const BankAccount& right ) {
	BankAccount newB;
	if (left.my_name == right.my_name) {
		newB.deposit( left.my_balance );
		newB.withdraw( right.my_balance );
	}
	else {
		cerr << "YIKES!  These two accounts can't be subtracted together since the names differ!" << endl;
		throw logic_error( "Bad account names" );
	}
	return( newB );
}

bool operator ==( const BankAccount& left, const BankAccount& right ) {
	return( (left.my_balance == right.my_balance) && (left.my_name == right.my_name)  );
}

bool operator < ( const BankAccount& left, const BankAccount& right ) {
	return( left.my_balance < right.my_balance );
}

bool operator > ( const BankAccount& left, const BankAccount& right ) {
	return( left.my_balance > right.my_balance );
}

}