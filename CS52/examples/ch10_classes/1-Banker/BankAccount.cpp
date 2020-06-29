//--------------------------------------------------------------------
// IMPLEMENTATION FILE: BankAccount.cpp
//
// Implements 1. class BankAccount member functions
//
//--------------------------------------------------------------------
#include "BankAccount.h"  // allows for separate compilation if you want
#include <iostream>    // for ostream << and istream >>
#include <string>      // for class string
using namespace std;

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

