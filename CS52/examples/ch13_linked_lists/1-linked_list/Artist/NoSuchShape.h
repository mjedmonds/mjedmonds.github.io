#ifndef NOSUCHSHAPE_H
#define NOSUCHSHAPE_H

#include <stdexcept>

class NoSuchShape : public std::logic_error {
public:
	NoSuchShape();
};


#endif