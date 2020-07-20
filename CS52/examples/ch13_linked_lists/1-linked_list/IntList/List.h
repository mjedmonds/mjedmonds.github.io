#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <exception>
#include "ListNode.h"

namespace cs52 {

class List {
public:
  List();
  ~List();
  int size() const;
  void makeEmpty();
  bool isEmpty( ) const;
  void push_front( const int& data );
  void push_back( const int& data );
  void remove( const int& data );

  // use these two lines if running under linux
  // friend std::ostream& operator <<() ( std::ostream& outs, const List& l );
  // friend std::ostream& operator <<() ( std::ostream& outs, const List* l );
  // use these two lines if running under windows
  friend std::ostream& operator << ( std::ostream& outs, const List& l );
  friend std::ostream& operator << ( std::ostream& outs, const List* l );
private:
  ListNodePtr head, tail;
  int listSize;

  std::ostream& printList( std::ostream& outs ) const;
  ListNodePtr findTarget(const int& data);
  ListNodePtr findTargetPrev(const int& data);
  void removeNode(ListNodePtr before_del);

};

}
#endif