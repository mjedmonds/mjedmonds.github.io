#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

namespace cs52 {

class ListNode; // forward declaration of ListNode class so we can typedef without a compile error
typedef ListNode* ListNodePtr;

class ListNode {
public:
  ListNode( const int& data_ = 0, ListNodePtr nextNode = nullptr );

  const int getData() const;
  void setNext( ListNodePtr nextNode );
  ListNodePtr getNext() const;

private:
  int data;
  ListNodePtr next;
};

}
#endif
