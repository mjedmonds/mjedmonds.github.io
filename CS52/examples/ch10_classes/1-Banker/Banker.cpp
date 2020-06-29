// This program demonstrates how to make use of existing objects.
// This program uses a bankAccount class with the interface described
// in class.

#include <iostream>                // for std::cout
#include <string>			     // for string class
#include "BankAccount.h"              // for bankAccount class
using namespace std;               // supports cout

int main( )
{
  string name;
  double openingbalance;

  cout.setf( ios::fixed );
  cout.setf( ios::showpoint );
  cout.precision( 2 );

  cout << endl << endl << "\t\tWelcome to the Bank of SMC!" << endl;
  cout << "Please enter your name and opening bank balance: ";
  cin  >> name >> openingbalance;

  BankAccount account;
  account.setName( name );
  account.deposit( openingbalance );

  cout << "Thank you for banking with the Bank of SMC!" << endl;
  cout << account.name() << " has a balance of $" << account.balance();
  cout << endl << endl;

  return 0;
}

