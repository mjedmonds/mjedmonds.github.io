---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 15, Inheritance
title: 'Inheritance'
---

## Chapter 15: Inheritance

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## Inheritance

- Inheritance allows us to create classes based on other classes
- For instance, think of all animals. We could define a hierarchy of all types of animals. Let's just consider mammals.
  - Each mammal has some common functionality, and as we get more specific in the hierarchy, the functionality becomes more and more specific.
  - For example, all mammals breathe oxygen through air. But whales have fins and rats, monkeys, and humans have limbs.
  - Every specific type of mammal (whale, rats, monkeys, humans) *inherit* the properties and functionality of a mammal.

### Base class

- The base class is the starting point for defining a set of classes.
- The most general attributes and methods are defined here
- For example, mammal could be a base class

### Derived class

- The derived class extends the base class in some way.
- For example, a whale extends the mammal base class. A monkey could also extend the mammal base class.

### Mammal hierarchy

For instance, we could have the following hierarchy:

```{.mermaid format=svg caption="Partial hierarchy of mammals"}
classDiagram
  Animal <|-- Mammal
  Mammal <|-- Whale
  Mammal <|-- Monkey
  Mammal <|-- Human
  Mammal <|-- Rat
  Whale <|-- Dolphin
  Whale <|-- Blue Whale
  Whale <|-- Killer Whale
```

- Here, Animal is the base class of the derived class Mammal.
  - Mammal is the base class of the derived classes Whale, Rat, Monkey, and Human.
  - So a derived class can serve as the base class for another derived class (similar to how a callee becomes a caller if the callee invokes another function).

## Door Example

- Let's design a set of door classes for an adventure game
- What are all the common characteristics of doors?

### Door object

- A door (as an object), it should know:
  - status (open or shut)
- A door (as an objecT), can do:
  - Initialize itself as shut
  - Open itself, if possible
  - Close itself
  - Tell whether or not it is open

### Door class

- Here's a generic base class:

```cpp
class Door {
public:
  Door();
  bool isOpen() const;
  void open();
  void close();
protected:
  bool isShut;
}
```

### `protected` qualifier

- The `protected` qualifier is a compromise between `private` and `public`
  - `protected` is `public` to the base class
  - `protected` is `public` to `friend`s of the base class
  - `protected` is `public` to the derived classes
  - `protected` is `public` to `friend`s of the derived classes
  - `protected` is `private` to other classes
- This allows base classes to:
  1. Hide functionality to users of the class (who can only access `public` members)
  2. Expose members to only to derived classes (who can access `public` and `protected` members)
  3. Hide members from both users of the class and derived classes (through `private` members of the base class)
     - Derived classes cannot access `private` members of the base class!

## Person, Student, Teacher Example

- In this example, we'll look at an example of a `Student` and `Teacher` class that are both derived from a `Person` base class (after all, students and teachers are both typically people in the real world!)
- We'll use the following hierarchy:

```{.mermaid format=svg caption="Person, Student, Teacher Hierarchy"}
classDiagram
  Person <|-- Teacher
  Person <|-- Student
```

### Example [Person.h](../examples/ch15_inheritance/A-Inheritance/Person.h)

- Our `Person` class will serve as our base class

```{include=../examples/ch15_inheritance/A-Inheritance/Person.h}
```

### Example [Person.cpp](../examples/ch15_inheritance/A-Inheritance/Person.cpp)

```{include=../examples/ch15_inheritance/A-Inheritance/Person.cpp}
```

### Example [Student.h](../examples/ch15_inheritance/A-Inheritance/Student.h)

- The `Student` class inherits from the `Person`

```{include=../examples/ch15_inheritance/A-Inheritance/Student.h}
```

### Example [Student.cpp](../examples/ch15_inheritance/A-Inheritance/Student.cpp)

- Take note: we must use an initializer list to construct the `Person` object: `: Person( name, address )` in the constructor for `Student`

```{include=../examples/ch15_inheritance/A-Inheritance/Student.cpp}
```

### Example [Teacher.h](../examples/ch15_inheritance/A-Inheritance/Teacher.h)

- The `Teacher` class also inherits from the `Person`

```{include=../examples/ch15_inheritance/A-Inheritance/Teacher.h}
```

### Example [Teacher.cpp](../examples/ch15_inheritance/A-Inheritance/Teacher.cpp)

- Take note: we must use an initializer list to construct the `Person` object: `: Person( name, address )` in the constructor for `Teacher`

```{include=../examples/ch15_inheritance/A-Inheritance/Teacher.cpp}
```

### Example [Main.cpp](../examples/ch15_inheritance/A-Inheritance/Main.cpp)

```{include=../examples/ch15_inheritance/A-Inheritance/Main.cpp}
```

## Inheritance Syntax

- To inherit from another class, we use the following syntax when defining the class:

```cpp
class DerivedClass : public BaseClass
{
  // class definition
};
```

- The "syntactic sugar" we added here is the `: public BaseClass`. This is informing the compiler that `DerivedClass` is inheriting from `BaseClass` with an "access mode" of public.

## Access mode

- The access mode determines how users of the class can interact with the `BaseClass` when instantiating a `DerivedClass`
- For this, let's consider the following implementations of `BaseClass` and `DerivedClass`

### `BaseClass`

- `BaseClass` is just a dummy class in this example - we'll get to real world examples in a moment

```cpp
class BaseClass
{
public:
  int x;
  BaseClass(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
protected:
  int y;
private:
  int z;
}
```

### `DerivedClass`

The access modes are:

- `public`: public members of the base class will become public members of the derived class and protected members of the base class will become protected in the derived class
  - In our example above, `BaseClass`'s `x` member will be treated as `public` in `DerivedClass`, `y` will be treated as `protected` in `DerivedClass`

```cpp
class DerivedClass : public BaseClass
{
  // x is public
  // y is protected
  // z is not accessible from DerivedClass
public:
  DerivedClass();
}
```

- `protected`: Both the public and protected members of `BaseClass` become protected in `DerivedClass`
  - If we changed our declaration of `DerivedClass` to be: `class DerivedClass : protected BaseClass` in our example above, `BaseClass`'s `x` and `y` will be treated as `protected` members of `DerivedClass`

```cpp
class DerivedClass : protected BaseClass
{
  // x is protected
  // y is protected
  // z is not accessible from DerivedClass
public:
  DerivedClass();
}
```

- `private`: Both the public and protected members of the `BaseClass` become private in `DerivedClass`
  - If we changed our declaration of `DerivedClass` to be: `class DerivedClass : private BaseClass` in our example above, `BaseClass`'s `x` and `y` will be treated as `private` members of `DerivedClass`

```cpp
class DerivedClass : private BaseClass
{
  // x is private
  // y is private
  // z is not accessible from DerivedClass
public:
  DerivedClass();
}
```

## Initializing BaseClasses

- We must always initialize the base class using an initializer list.
  - This is because the base class must be constructed *before* the derived class. By using an initializer list, we construct the `BaseClass` before the `DerivedClass` is completely constructed
- For instance, we could write:

```cpp
DerivedClass::DerivedClass() : BaseClass(1,2,3) {
  // rest of constructor goes here
  // we cannot initialize/assign BaseClass here. It must be initialized in the initializer list
}
```


## Door Example - Lockable Door

- Let's look at another door example. This time, we'll make a new `LockableDoor` class that derives from the base `Door` class

```cpp
class LockableDoor : public Door {
public:
  LockableDoor();
  bool isLocked() const;
  void open();
  void lock();  void unlock();
protected:
  bool thelock;
}
```

- Notice, we did NOT need to define the functions defined in `Door`. That's the point of inheritance; we get the functionality of `Door` inside of `LockableDoor` and only need to add the **new** functionality we want the `LockableDoor` to have
  - This is very useful when you start writing larger pieces of software
- The `LockableDoor` object has the following member attributes (data) and member functions:

| Member attributes | Member methods |
|-------------------|----------------|
| isShut            | isLocked()     |
| theLock           | open()         |
|                   | lock()         |
|                   | unlock()       |
|                   | isOpen()       |
|                   | close()        |

- Notice that `LockableDoor` did not define `isShut`, `open()`, `isOpen()`, or `close()`. These are all part of the base class `Door`, but they are available in `LockableDoor`

## Inheritance behavior

- By default, all member methods and member data are inherited down to derived classes
  - This happens without mentioning these methods and attributes in the derived class definition
- Any member method or member attribute can be redefined in the derived class
  - This hides access to the base class versions - the base class still retains its copies of redefined member attributes and member methods
- For instance, we may wish to redefine the `open()` functionality of `DerivedClass` to take into account whether or not the door is locked:

```cpp
void LockableDoor::open( )
{
  if (!isLocked()) {
    Door::open();
  }
}
```

- We can write this method *without* defining it again in `LockableDoor`'s class definition.
- We can use the scope operator `::` to specify which version of a function to call (note: we had to use `Door::open()` above. Had we just written `open()`, we would have started a recursive infinite loop!)

## Using the door examples

- We can now use our doors for different circumstances

```cpp
Door hallDoor;
LockableDoor frontDoor;

hallDoor.open();
frontDoor.lock();
frontDoor.open();
if (!frontDoor.isOpen())
   frontDoor.unlock();
```

## Derived classes can become base classes

```{.mermaid format=svg caption="Partial hierarchy of mammals"}
classDiagram
  Door <|-- LockableDoor
  LockableDoor <|-- CombinationLockDoor
  LockableDoor <|-- PasswordLockDoor
```

## `CombinationLockDoor`

```cpp
class CombinationLockDoor : public LockableDoor {
public:
  CombinationLockDoor( int combo = 0);
  void unlock( int combo );
protected:
  int thecombination;
}
```

- The `CombinationLockDoor` object has the following member attributes (data) and member functions:

| Member attributes | Member methods |
|-------------------|----------------|
| isShut            | isLocked()     |
| theLock           | open()         |
| thecombination    | lock()         |
|                   | unlock(int)    |
|                   | isOpen()       |
|                   | close()        |

- You can see how easily we can extend functionality to different cases!

## Person, Student, Teacher Example - with Pointers

- This example will show how we can use pointers with inheritance, how `protected` members are accessible to derived classes, and how redefined members hide access to the parent class versions

### Example [PersonPtr.h](../examples/ch15_inheritance/C-PointerInheritance/Person.h)

- Our `Person` class will serve as our base class

```{include=../examples/ch15_inheritance/C-PointerInheritance/Person.h}
```

### Example [PersonPtr.cpp](../examples/ch15_inheritance/C-PointerInheritance/Person.cpp)

```{include=../examples/ch15_inheritance/C-PointerInheritance/Person.cpp}
```

### Example [StudentPtr.h](../examples/ch15_inheritance/C-PointerInheritance/Student.h)

- The `Student` class inherits from the `Person`

```{include=../examples/ch15_inheritance/C-PointerInheritance/Student.h}
```

### Example [StudentPtr.cpp](../examples/ch15_inheritance/C-PointerInheritance/Student.cpp)

- Take note: we must use an initializer list to construct the `Person` object: `: Person( name, address )` in the constructor for `Student`

```{include=../examples/ch15_inheritance/C-PointerInheritance/Student.cpp}
```

### Example [TeacherPtr.h](../examples/ch15_inheritance/C-PointerInheritance/Teacher.h)

- The `Teacher` class also inherits from the `Person`

```{include=../examples/ch15_inheritance/C-PointerInheritance/Teacher.h}
```

### Example [TeacherPtr.cpp](../examples/ch15_inheritance/C-PointerInheritance/Teacher.cpp)

- Take note: we must use an initializer list to construct the `Person` object: `: Person( name, address )` in the constructor for `Teacher`

```{include=../examples/ch15_inheritance/C-PointerInheritance/Teacher.cpp}
```

### Example [MainPtr.cpp](../examples/ch15_inheritance/C-PointerInheritance/Main.cpp)

```{include=../examples/ch15_inheritance/C-PointerInheritance/Main.cpp}
```

## Relationships between Objects

- **IS-A**
  - One class "is a kind of" another class
  - Base class is a general class
  - Derived class is a specialization of the general concept
- **PART-OF**
  - One class "is a part of" another class
  - often used to represent compound objects

```{.mermaid format=svg caption="Difference between IS-A and PART-OF relationship"}}
graph BT
  Mac -->|IS A| Computer
  Monitor -->|PART OF| Computer
```

- Here is an example of the difference between IS-A and PART-OF.
  - Our Mac is-a computer, and the monitor is part-of of a computer

```cpp
class Monitor {

};

class Computer {
private:
  Monitor theMonitor; // a monitor is part-of a computer
};

// a mac is-a computer
class Mac : public Computer {

};
```

## `PasswordLockDoor`

- Password lock doors are doors that require a password to open or close
- Let's represent the password as a `string`
- The password is "part-of" a `PasswordLockDoor`

```cpp
class PasswordLockDoor : public LockableDoor {
public:
  PasswordLockDoor(const char c[]="");
  void unlock( const char c[]="");
protected:
  string thepassword;
}
```

- The `PasswordLockDoor` object has the following member attributes (data) and member functions:

| Member attributes | Member methods |
|-------------------|----------------|
| isShut            | isLocked()     |
| theLock           | open()         |
| thepassword       | lock()         |
|                   | unlock(char[]) |
|                   | isOpen()       |
|                   | close()        |

## Pointers to base classes

- Pointers can be made to point to derived classes
- Consider the following:

```cpp
typedef Door* DoorPtr;
DoorPtr p = new Door(); // dynamically allocating a door
p->open();  // calls Door::open
...
p = new LockableDoor();
p->open();  // which open??
```

## `virtual` functions

- Late binding allows the selection of which implementation of a member function to execute to be determined at runtime
- C++ performs late binding via `virtual` functions
- Consider this generic base class

```cpp
class Door {
public:
  Door();
  bool isOpen() const;
  virtual void open();
  void close();
protected:
  bool isShut;
}
```

## Auto example

- This example shows how `virtual` functions work. The key thing to note here is the definition of `Auto` functions as virtual in `Auto.h` and the use of `ptrAuto` in `Main.cpp`.

### Example [Auto.h](../examples/ch15_inheritance/B-Virtual-Functions/Auto.h)

- Our `Auto` class will serve as our base class

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Auto.h}
```

### Example [Auto.cpp](../examples/ch15_inheritance/B-Virtual-Functions/Auto.cpp)

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Auto.cpp}
```

### Example [Honda.h](../examples/ch15_inheritance/B-Virtual-Functions/Honda.h)

- The `Honda` class inherits from the `Auto`

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Honda.h}
```

### Example [Honda.cpp](../examples/ch15_inheritance/B-Virtual-Functions/Honda.cpp)

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Honda.cpp}
```

### Example [Settings.h](../examples/ch15_inheritance/B-Virtual-Functions/Settings.h)

- Use this file to control whether or not `Auto` has virtual functions or not.
- To prevent `Auto` from using `virtual` functions, just comment out the `#define` in this file

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Settings.h}
```

### Example [Main.cpp](../examples/ch15_inheritance/B-Virtual-Functions/Main.cpp)

- Take note of the final `PTRAUTO POINTING AT HONDA` portion
- We have an `Auto` pointer (`ptrAuto`) pointing to a `Honda` derived class, and due to the use of `virtual` functions, the `Auto` pointer calls the `Honda` versions of the functions
  - One would think, given `ptrAuto` is a pointer to the base class `Auto`, that these calls would call the `Auto` versions of the functions. But because they are virtual functions in `Auto`, the derived class's versions are called.
- This is late binding at runtime!

```{include=../examples/ch15_inheritance/B-Virtual-Functions/Main.cpp}
```
