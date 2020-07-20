#ifndef HONDA_H
#define HONDA_H
#include "Settings.h"
#include "Auto.h"

namespace cs52 {

class Honda : public Auto {
public:
	Honda( );
    
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