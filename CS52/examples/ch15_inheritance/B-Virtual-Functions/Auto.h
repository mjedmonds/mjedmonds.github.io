#ifndef AUTO_H
#define AUTO_H
#include "Settings.h"

namespace cs52 {

class Auto {
public:
	Auto( );

#ifdef USEVIRTUALFUNCTIONS
	virtual void insertKey();
	virtual void turn();
	virtual void drive();
#else
	void insertKey();
	void turn();
	void drive();
#endif
};

}

#endif