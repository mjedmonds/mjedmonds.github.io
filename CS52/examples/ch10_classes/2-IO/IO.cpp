// This program demonstrates how to make use of existing objects.
// This program repeats the dialog of the Banker.cpp example, but
// reads input and writes output to files using stream classes.

#include <iostream>          // for std::cout
#include <fstream>		     // for ifstream and ofstream
#include <string>			 // for string class
#include <cstdlib>		     // for exit()
#include "baccount.h"        // for bankAccount class
using namespace std;         // supports cout

int main( )
{
  string name;
  double openingbalance;
  
  // Create input and output streams
  ifstream in_stream;
  ofstream out_stream;
  
  out_stream.setf( ios::fixed ); 
  out_stream.setf( ios::showpoint );
  out_stream.precision( 2 );

  in_stream.open( "indata.dat" );
  if (in_stream.fail()) {
     cout << "Error opening indata.dat" << endl;
     exit( 1 );
  }
 
  out_stream.open( "outdata.dat" );
  if (out_stream.fail()) {
     cout << "Error opening outdata.dat" << endl;
     exit( 1 );
  }
 
  out_stream << endl << endl << "\t\tWelcome to Howie's Bank!" << endl;
  out_stream << "Your Wish Is My Command!" << endl;
  out_stream << "Please enter your name and opening bank balance: ";
  in_stream  >> name >> openingbalance;
 
  bankAccount account;
  account.setName( name );
  account.deposit( openingbalance );
 
  out_stream << "Thank You For Banking With Howie's Bank!" << endl;
  out_stream << account.name() << " has a balance of $" << account.balance();
  out_stream << endl << endl;
 
  in_stream.close();
  out_stream.close();
 
  return 0;
}
 
