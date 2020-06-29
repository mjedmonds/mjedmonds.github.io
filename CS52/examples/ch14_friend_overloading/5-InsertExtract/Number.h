 #ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstdlib>

namespace cs52 {

class Number {
public:
	Number();
	Number( int initValue );

	void setValue( int v );
	int  getValue() const;
	// instead of using cout, accept an ostream
	void printRomanNumeral( ostream& outs ) const;

	friend Number operator + ( const Number& left, const Number& right );
	friend Number operator - ( const Number& left, const Number& right );
	friend bool   operator ==( const Number& left, const Number& right );
	friend Number operator / ( const Number& left, const Number& right );
	friend Number operator * ( const Number& left, const Number& right );

	friend std::ostream& operator <<( std::ostream& outs, const Number& n );
	friend std::istream& operator >>( std::istream& ins, Number& n );

private:
	int value;
};

}

#endif
