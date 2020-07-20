#include "List.h"
#include "ListNode.h"

namespace cs52 {

List::List() {
  head = nullptr;
  tail = nullptr;
  listSize = 0;
}

List::~List() {
  // when destructing the object, we empty the object!
  makeEmpty();
}

bool List::isEmpty() const {
  return( head == nullptr );
}

void List::makeEmpty() {
  while (head != nullptr) {
    remove( head->getData() );
  }
  head = tail = nullptr;
}

int List::size() const {
  return( listSize );
}

void List::push_front( const int& data ) {
  // place data into a ListNode at the front of the list
  ListNode* newnode = new ListNode( data );
  // if this is the first insert, tail needs to be updated as well
  if (head == nullptr && tail == nullptr) {
    head = tail = newnode;
  } else {
    // set the new node's next to point to the current head
    newnode->setNext( head );
    // update the head to be the newnode
    head = newnode;
  }
  listSize++;
}

void List::push_back( const int& data ) {
  // place data into a ListNode at the back of the list
  ListNode* newnode = new ListNode( data );
  // if this is the first insert, head needs to be updated as well
  if (head == nullptr && tail == nullptr) {
    head = tail = newnode;
  } else {
    // set the current tail's next to be the new node
    tail->setNext( newnode );
    // set the tail to be the new node
    tail = newnode;
  }
  listSize++;
}

void List::remove( const int& data ) {
  // special case when data is at head
  if(head != nullptr && head->getData() == data){
    ListNodePtr temp = head->getNext();
    // only one value in list, both head and help are going to be nullptr
    if (temp == nullptr){
      tail = nullptr;
    }
    delete(head);
    head = temp;
  } else {
    ListNodePtr previous = findTargetPrev(data);
    if (previous == nullptr){
      throw std::logic_error("data to remove not found in list");
    }
    ListNodePtr current = previous->getNext();
    // update the link from previous' next to current's next
    previous->setNext( current->getNext() );
    // may need to update tail
    if (current == tail){
      tail = previous;
    }
    delete( current );
  }
  listSize--;
}

std::ostream& operator << ( std::ostream& outs, const List& l) {
  return( l.printList( outs ) );
}

std::ostream& operator << ( std::ostream& outs, const List* l) {
  return( l->printList( outs ) );
}

std::ostream& List::printList( std::ostream& outs ) const {
  if (isEmpty())
    outs << "Empty List" << std::endl;
  else {
    outs << "List has " << size() << " elements: " << std::endl;
    ListNode* current = head;
    while (current != NULL) {
      outs << current->getData() << " -> ";
      current = current->getNext();
    }
    outs << " NULL";
    outs << std::endl;
  }
  return( outs );
}

ListNodePtr List::findTarget(const int& target_data){
  // special case when data is at head
  if(head && head->getData() == target_data){
    return head;
  }
  ListNodePtr p = findTargetPrev(target_data);
  // if p wasn't nullptr
  if (p != nullptr)
  {
    return p->getNext();
  }
  return p;
}

ListNodePtr List::findTargetPrev(const int& target_data){
  // special cases when we cannot have a previous - empty or only one value in list
  if (head == nullptr || head->getNext() == nullptr) {
    return nullptr;
  }
  ListNodePtr p = head;
  ListNodePtr cur = p->getNext();
  while (cur != nullptr && cur->getData() != target_data) {
    std::cout << p->getData() << " " << cur->getData() << std::endl;
    p = p->getNext();
    cur = cur->getNext();
  }
  // need a special case for if we didn't find the value - we should return nullptr but p is actually tail
  if (p->getNext() == nullptr){
    return nullptr;
  }
  return p;
}

// removes the node at prev_node->next()
void List::removeNode(ListNodePtr prev_node){
  ListNodePtr node_to_delete = prev_node->getNext();
  prev_node->setNext( node_to_delete->getNext() );
  delete( node_to_delete );
}


}
