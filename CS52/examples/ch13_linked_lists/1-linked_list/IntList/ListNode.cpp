#include <iostream>
#include "ListNode.h"

namespace cs52 {

ListNode::ListNode( const int& data_,
				    ListNodePtr nextNode ) : data( data_ ), next( nextNode ) {
}

const int ListNode::getData() const {
	return( data );
}

void ListNode::setNext( ListNodePtr nextNode ) {
	next = nextNode;
}

ListNodePtr ListNode::getNext() const {
	return( next );
}

}


