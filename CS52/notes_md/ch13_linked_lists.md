---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 13, Linked Lists
title: 'Linked Lists'
---

## Chapter 13: Linked Lists

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## Linked lists

- A linked list is a commonly used data structure (you should take SMC's data structures course!)
- It is similar to an array, except the memory is not stored in a contiguous block

## Abstract data type

- C++ classes are Abstract Data Types (ADT)
  - Provides logical structure for information represented by the class
  - Provides operations to perform on this information

## Linked List

- A collection of linked nodes
- Each node contains
  - Some kind of common data/information
  - Address of another node
- The collection grows and shrinks over time
- Nodes are accessed sequentially

## Linked list structure

- The linked list class:
  - Logical structure:
    - Has a beginning (referred to as a "head")
    - Has an ending (referred to as a "tail")
    - May be empty
  - Operations
    - insert item
    - remove item
    - return length
    - position at head, tail, successor, predecessor

## Linked list implementation

- We could implement a linked list with an array
  - The linked list would then be fixed in size (or we would need to manage resizing, similar to `std::vector`)
- We will instead implement a linked list with pointers
  - The list can grow and shrink in size easily

## Node object

- The node object knows:
  - Its own data (information)
  - The address of the next node in the list
- The node object can:
  - Initialize itself
  - Return its information
  - Set the address of the next node
  - Give the address of the next node

## Node class

```cpp
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

```

## Linked list of `Node`s

- First, we'll declare a `typedef` of a pointer to a node: `typedef Node* NodePtr;`
- Next, we'll declare a head of the list and initialize it to `nullptr`: `NodePtr head = nullptr;`

```{.mermaid format=png caption="The start of a linked list. Head is empty and points to nullptr"}
flowchart LR
  subgraph head["ListNodePtr"]
    headPtr["head"]
  end
  headPtr --> nullptr
````

- In the following diagrams, an arrow emitting from a `NodePtr` indicates the value the `NodePtr` is pointing to, while an arrow emitting from a `Node` indicates
- From here, we can create the first node with value 3

```cpp
head = new Node(3);
```

- Now we have the following structure:

```{.mermaid format=png caption="The start of a linked list. Head is empty and points to nullptr"}
flowchart LR
  subgraph n3["ListNode"]
    n3info["data: 3"]
  end
  subgraph head["ListNodePtr"]
    headPtr["head"]
  end
  head --> n3
  n3--next-->nullptr
```

- Let's insert another node at the start of the list:

```cpp
ListNodePtr newNode = new ListNode(5);
newNode->next = head;
head = newNode;
```

```{.mermaid format=png caption="Linked list with two nodes"}
flowchart LR
  subgraph n3["ListNode"]
    n3info["data: 3"]
  end
  subgraph n5["ListNode"]
    n5info["data: 5"]
  end
  subgraph head["ListNodePtr"]
    headPtr["head"]
  end
  subgraph newNode["ListNodePtr"]
    newNodePtr["newNode"]
  end
  head --> n5
  newNode --> n5
  n5 --next--> n3
  n3 --next--> nullptr
```

- Next, let's suppose we want to insert a node between the nodes with data 5 and 3 (i.e. after the node with data = 5)

```cpp
newNode = new ListNode(4);
newNode->next = head->next;
head->next = newNode;
```

```{.mermaid format=png caption="Linked list with three nodes after inserting in middle"}
flowchart LR
  subgraph n3["Node"]
    n3info["data: 3"]
  end
  subgraph n4["Node"]
    n4info["data: 4"]
  end
  subgraph n5["Node"]
    n5info["data: 5"]
  end
  subgraph head["NodePtr"]
    headPtr["head"]
  end
  subgraph newNode["NodePtr"]
    newNodePtr["newNode"]
  end
  head --> n5
  newNode --> n4
  n5 --next--> n4
  n4 --next--> n3
  n3 --next--> nullptr
```

## Traversing the list

- To walk over all of the nodes in the list, we can do this:

```cpp
void printList(ListNodePtr head){
  ListNodePtr p = head;
  while (p != nullptr) {
    cout << p->data << endl;
    p = p->next;
  }
}
```

## Searching the list

- To search for a value in the list, we traverse the list and look for a value

```cpp
ListNodePtr findTarget( const int& target_data){
  ListNodePtr p = head;
  while (p != nullptr && p->data != target_data) {
    p = p->next;
  }
  return p;
}
```

## List object

- The LinkedList object knows:
  - Its head node
  - Its tail node
  - Its current size
- The LinkedList object can:
  - Initialize itself
  - Return whether or not it is empty
  - Make the list empty
  - Insert data in the front of the list
  - Insert data in the back of the list
  - Remove data
  - Return the pointer to a target list node

## List class

```cpp
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
private:
  ListNodePtr head, tail;
  int listSize;

  ListNodePtr findTarget(const int& data);
}
```

- Let's look at a full implementation of this class
  - Take some time to appreciate how pointers allow for sophisticated but carefully constructed data structures
  - The key issue is to hide the complexity from the users of this class

### Example [ListNode.h](../examples/ch13_linked_lists/1-linked_list/IntList/ListNode.h)

```{include=../examples/ch13_linked_lists/1-linked_list/IntList/ListNode.h}
```

### Example [ListNode.cpp](../examples/ch13_linked_lists/1-linked_list/IntList/ListNode.cpp)

```{include=../examples/ch13_linked_lists/1-linked_list/IntList/ListNode.cpp}
```

### Example [List.h](../examples/ch13_linked_lists/1-linked_list/IntList/List.h)

```{include=../examples/ch13_linked_lists/1-linked_list/IntList/List.h}
```

### Example [List.cpp](../examples/ch13_linked_lists/1-linked_list/IntList/List.cpp)

```{include=../examples/ch13_linked_lists/1-linked_list/IntList/List.cpp}
```

### Example [ListDriver.cpp](../examples/ch13_linked_lists/1-linked_list/IntList/ListDriver.cpp)

```{include=../examples/ch13_linked_lists/1-linked_list/IntList/ListDriver.cpp}
```

## Linked list pros and cons

- Pros - Easy
  - insertion
  - deletion
  - splitting
  - joining
- Cons - Hard
  - Traversal is tedious compared to arrays
  - Expensive in terms of space

## Linked lists vs. Arrays

- Arrays
  - Static in allocation size
  - Removed items leave wasted space -> O(n)
  - Insertion has more overhead -> O(n)
  - Element access -> O(1)
- Linked lists
  - Expensive to walk/iterate -> O(n)
  - Removing item -> O(1)
  - Inserting item -> O(1)
- Neither is better than the other, they are just different. Use both of them wisely and when they make sense.
