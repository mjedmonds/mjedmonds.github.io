---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 10, Defining Classes
title: 'Defining Classes'
---

## Chapter 10: Defining Classes

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## Object-oriented Programming

- Up to this point, most of what we've learned also applies to C
- Object-oriented programming concept: group data and operations together logically and allow hierarchies of relationships
- Operations (methods): steer, accelerate, decelerate, fill up with gas, etc
- Data (attributes): speed, heading, gas tank status, odometer, etc.
- You don't have to know how the car precisely works to use one. You simply know that the pedal accelerates the car, brake decelerates, etc
- This is known as *information hiding*
- Another engineer has designed how the care operates, you just use the public (available) operations
  - But there are many more operations happening inside the car than you are aware
- We refer to the design of the car as the *class* (think of this like a blueprint)
- Once you have the design for a car, you can reuse it
  - Each "usage" is an *instantiation* of a car
- Similarly, once you have a design of a car, you can extend it to add new features
  - E.g. add upgrades, wings, etc
  - This is known as inheritance
- From the object-oriented programming view, programs are viewed as a collection of collaborating objects
  - This models the real world
  - Program structure is implemented via *classes* and *objects*

## Objects

- Consider the car as an object. It may have the following structure:

| Properties     | Functionality       |
|----------------|---------------------|
| Make:  Honda   | play_music          |
| Model: Prelude | toggle_left_blinker |
| Gas tank: Full | honk                |

- An object has:
  1. State described via *attributes* (also known as *properties*)
  2. Behavior described via *methods*
  3. Identity described via *instances*
- Objects are instantiations of a specific blueprint (called classes in C++)
  - Each instantiation may have different values for their properties, even though they came from the same blueprint
  - For instance, different instances of a car may have different levels of gas in their tanks

## Classes

- Classes are like blueprints for objects
- We instantiate an *object* using the class's blueprint
  - Instances must be *declared* before they can be used, just like every other variable.
- Let's look at an example. Suppose we have the following `BankAccount` class design (this isn't C++ code yet):

```{.mermaid format=svg caption="Box diagram for BankAccount class"}
classDiagram
  class BankAccount{
    -string my_name
    -double my_balance
    +withdraw(double) void
    +deposit(double) void
    +balance() double
    +name() string
    +setName(string) void
  }
```

- This diagram is called a **class block diagram**
  - The top panel indicates the class name, the middle pane indicates the member variables, and the bottom pane indicates the member methods
  - A `-` indicates a private member and a `+` indicates a public member (more on this in a bit)
  - For member methods (functions) they have the following form: `methodName(arg_types) : return_type`. This is a bit different than how we write functions in C++, but this diagram format is the industry-standard in computer science and software engineering

- We can instantiate this class the way we do every other variable:

```c++
BankAccount my_bank;
```

- Since the `balance()` method returns a double, we can do the same thing that we've been doing with every other function:

```c++
BankAccount my_bank;
double balance = my_bank.balance();
```

- Notice that we use the `.` operation to access the `my_bank` instance's `balance()` function.

## Bank example

- The following example shows how to create and use a simple bank account class

### Example [Banker.cpp](../examples/ch10_classes/1-Banker/Banker.cpp)

```{include=../examples/ch10_classes/1-Banker/Banker.cpp}
```

### Example [BankAccount.h](../examples/ch10_classes/1-Banker/BankAccount.h)

```{include=../examples/ch10_classes/1-Banker/BankAccount.h}
```

### Example [BankAccount.cpp](../examples/ch10_classes/1-Banker/BankAccount.cpp)

```{include=../examples/ch10_classes/1-Banker/BankAccount.cpp}
```

- One important thing to note: there's a semicolon placed after you declare a class (i.e. after the closing curly brace)
- Another important thing to note: in the implementation, we had to write `BankAccount::` before all of our method definitions.
  - This is to tell the compiler that this function is part of the `BankAccount` class, and gives the function *scope* inside the class. This allows it to access member variables and use other class methods.
- Also note that our header file `BankAccount.h` and our implementation file `BankAccount.cpp` have the same name except for the file extension. Follow this convention!
- We can instantiate multiple bank accounts, each with their own balance:

```c++
BankAccount bank1("bank1", 1000);
BankAccount bank2("bank2", 345);
double bank1_balance = bank1.balance();
double bank2_balance = bank2.balance();
```

- `bank1_balance` will be 1000 and `bank2_balance` will be 345.
- This shows the power of classes - we have one blueprint, `BankAccount` and can instantiate multiple instances of that class.
  - Each class has it's own copy of member variables (e.g. `bank1` and `bank2` have different values for the member variable `my_balance`)

## `private` vs. `public`

- In our `BankAccount.h` above, you may have noticed that we had one section under `public:` and another section under `private:`
  - This indicates whether or not this member variable or method is available for internal use (`private`) or internal or external use (`public`).
- `public` members can be accessed by the class itself or by anyone using the class. That's why we were able to call `bank1.balance()`; `balance()` is listed as a public method
- `private` members can only be access by the class itself. That means if we tried to directly access the member variable `my_balance`, we'd get an error. The function `balance()` is allowed to access `my_balance` because it is a method inside the class.
  - If you don't believe me, try to access `account.my_balance` directly in `Banker.cpp`. Compile and you'll get an error.
- This functionality is important because it allows the class designer to specify what a user can access in a class
  - For instance, if you were designing a class to model a car, you probably don't want to allow an ordinary user direct access to the transmission or internal engine components
- Some additional notes regarding `public` vs. `private`:
  - You can list them multiple times in one class header file
  - If you don't specify either, classes will default to `private`
  - Usually advisable to only have one block of `public` and one block of `public` per header
  - Every class method has access to `private` members, regardless of whether or not they are `public` or `private` (e.g. a `public` method can call a `private` method and access `private` member variables)

## When should you use `private`?

- Class member variables should be declared `private` as a general rule
- Class helper functions should also be declared `private`
  - For instance, suppose you were building a class for an automatic car
  - You wouldn't want to make the `shiftGears()` function be `public`, as in an automatic car, the user should not be able to call `shiftGears()` directly, but the car still needs to shift gears, so this should be a `private` method.
- The only things that should be declared `public` are functions you want the end-user to be do

### Setters (mutators) and getters (accessors)

- Because we typically make class member variables `private`, we may need a way to allow the user to read or modify a member variable.
- A "getter" (also called an accessor) method will *get* the value of a member variable.
  - For instance, `balance()` and `name()` in the `BankAccount` class are both getter methods.
- A "setter" (also called a mutator) method will modify the value of a member variable.
  - For instance, `setName(string)` in the `BankAccount` class is a setter method.
- Why use setters and getters?
  - The main motivation for using getters is to hide the member address of a specific variable. This is for security.
    - Notice `balance()` returns a copy of `my_balance`. This prevents the user from knowing the exact memory address of `my_balance`
  - The main motivation for using setters is to allow the user to modify the variable *without* giving direct access to the member variable.
    - Setters can also implement additional functionality to check where or not the new value is valid. For instance, your data may have some constraints, like a telephone number that is expected to follow a certain form. By using a setter function, you can check and verify the input *before* assigning it to a member variable.

## Why use classes?

- Consider the `BankAccount` example again.
  - A user doesn't need to know exactly how the `BankAccount` class works internally; a user only needs to know how to use the class.
- This is called *information hiding*, and it makes complex things much more simple
  - A good example of this is the `toggle_left_blinker()` method from the car object
    - You don't need to know anything about electronics to successfully toggle the blinker. That's wonderful for all users of the class!
- Using `private` and `public` appropriately helps enforce information hiding.

## Why separate classes into header and implementation files?

- For the same reasons as before, but just to refresh our memory...
- The implementation file may be compiled in a *library* and distributed to others. For instance, the C++ Standard Library does this. When you include standard library functionality, like with `<iostream>` the implementation file has never been on your computer. Instead, when you install a C++ compiler, it installs a precompiled version of the library on your computer.
  - However, the header file *does* exist somewhere on your machine. This is what enables you share your code with others *without* letting them see exactly how you implemented every function.
- When we give our class to others, we may want to hide exactly how we implemented each function for security or business reasons, but want to let others use the Application Programming Interface (API) we provide in header files. This is a great way to share your code with others without requiring them to compile every line of code you wrote

## Student example

- A good example of how challenging it is to write a well designed class
- But also an example of how easy it is to use a well-defined track

### Example [StudentDriver.cpp](../examples/ch10_classes/1-Student/StudentDriver.cpp)

```{include=../examples/ch10_classes/1-Student/StudentDriver.cpp}
```

### Example [Student.h](../examples/ch10_classes/1-Student/Student.h)

```{include=../examples/ch10_classes/1-Student/Student.h}
```

### Example [Student.cpp](../examples/ch10_classes/1-Student/Student.cpp)

```{include=../examples/ch10_classes/1-Student/Student.cpp}
```

## Class Constructors

- Constructors are called when instances are declared or initialized.
- They define how member variables should be initialized
- Constructors are special methods, but they can call any other method, or execute any other C++ code you need to execute when the class instance is being "constructed".
- Constructors cannot be called directly. They are only called when an instance is declared or initialized.
- Each class can define one constructor or multiple constructors. Each constructor must have a unique signature, meaning their parameter type and lengths must be unique.
  - For an example, the `BankAccount` class, there are two constructors. One, `BankAccount()` does not take any arguments, but `BankAccount(string initName, double initBalance)` takes two arguments
  - When we define multiple
  - These different constructors will be called automatically depending upon what arguments are passed. For instance:

```cpp
BankAccount my_account1; // this will call the constructor with no parameters (BankAccount())
BankAccount my_account2("mark", 1000); // this will call the constructor with parameters (BankAccount(string initName, double initBalance))
cout << my_account1.name() << endl; // this will print the value ?name?
cout << my_account2.name() << endl; // this will print mark
```

## Radio example

- Another example

### Example [RadioDriver.cpp](../examples/ch10_classes/2-Radio/RadioDriver.cpp)

```{include=../examples/ch10_classes/2-Radio/Radio.cpp}
```

### Example [Radio.h](../examples/ch10_classes/2-Radio/Radio.h)

```{include=../examples/ch10_classes/2-Radio/Radio.h}
```

### Example [Radio.cpp](../examples/ch10_classes/2-Radio/Radio.cpp)

```{include=../examples/ch10_classes/2-Radio/Radio.cpp}
```

## I/O Streams

- Let's refer back to the Chapter 6: I/O Streams notes
- One thing you may not have noticed was that `ifstream` and `ofstream` are actually classes
  - For instance, we wrote:

```cpp
ifstream in_stream;
in_stream.open("infile.dat");
```

- We've actually been using classes all along...
  - `cout` and `cin` are special instances of stream objects.
    - `>>` and `<<` are operators in C++, similar to `+` or `-`...but more on that later

## Structures

- Structures are extremely similar to classes
- In C, structures can only hold data (i.e. you cannot add methods to a structure, only member variables)
- In C++, you can add member variables to a structure, but most people use a class in this case.
  - There is another more subtle difference between classes and structures: structures declare everything as `public` by default and classes declare everything as `private` by default.
- Let's declare a structure that defines a CD account at our bank:

```cpp
struct CDAccount
{
  double balance;
  double interestRate;
  int term;  //months to maturity
};  // notice we also end the declaration of the struct with a semicolon
```

- The keyword `struct` indicates we are declaring a struct and `CDAccount` is the structure's type
- We can use this similar to how we've used classes up to this point:

```cpp
CDAccount my_account;
my_account.balance = 10;
```

- As a general rule, use structures when you DON'T need to encapsulate functionality (methods) with data (member variables), and use classes when you DO need to encapsulate functionality (methods) with data (member variables).

## Enumerations

- Mappings between labels and integers
- Enumerations are not composed of any data types only labels.
- Example enum to represent colors

```cpp
enum color
{
    red,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
};
```

- Under the hood, red will be assign the value `0`, orange `1`.
- How do you use them?

```cpp
enum color value = red;
if(value == green){
  cout << "We should never execute this statement\n";
}
```

- We can also use them in switch statements conveniently:

```cpp
#include <iostream>
#include <string>

enum color {
  red,
  orange,
  yellow,
  green,
  cyan,
  blue,
  purple,
};

int main(){
  enum color value = red;
  switch(value){
    case red:
      cout << "color is red\n";
      break;
    case orange:
      cout << "color is orange\n";
      break;
    case yellow:
      cout << "color is yellow\n";
      break;
    case green:
      cout << "color is green\n";
      break;
    case cyan:
      cout << "color is cyan\n";
      break;
    case blue:
      cout << "color is blue\n";
      break;
    case purple:
      cout << "color is purple\n";
      break;
  }
}
```

- Example usage: suppose we wanted to compare against the day of the week. We could use string comparisons for everything, but this is clunky, hard to read and string comparison is computationally expensive.
  - Because enumerations are really just labeled integers, we can make code more readable by using them!

## Student example with enumerations

- Here is an example of our Student class using enumerations for the year and grades

### Example [EnumerationDriver.cpp](../examples/ch10_classes/3-Enumeration/EnumerationDriver.cpp)

```{include=../examples/ch10_classes/3-Enumeration/EnumerationDriver.cpp}
```

### Example [Student.h](../examples/ch10_classes/3-Enumeration/Student.h)

```{include=../examples/ch10_classes/3-Enumeration/Student.h}
```

### Example [Student.cpp](../examples/ch10_classes/3-Enumeration/Student.cpp)

```{include=../examples/ch10_classes/3-Enumeration/Student.cpp}
```

## Default values

- Any function can be supplied with default values
- This allows the user to omit certain arguments and use the defaults instead
- All default arguments must be grouped at the end of a function declaration
- Here are some examples using default values; notice that once we start using a default value, all arguments proceeding the first use a default value also must use a default value

```cpp
void func(double d=0.0);
void calc(int arg1,
          int arg2,
          int arg3=0,
          int arg4=1);
```

- The following are all valid invocations of these functions:

```cpp
func();
func(12.5);
calc(12, 1);
```

## Radio example with default values

- Next, let's look at our Radio class, but rewrite it to use some default values
- Notice how we can mix default arugments with normal parameters

### Example [DefaultDriver.cpp](../examples/ch10_classes/4-DefaultDriver/DefaultDriver.cpp)

```{include=../examples/ch10_classes/4-DefaultDriver/DefaultDriver.cpp}
```

### Example [Radio.h](../examples/ch10_classes/4-DefaultDriver/Radio.h)

```{include=../examples/ch10_classes/4-DefaultDriver/Radio.h}
```

### Example [Radio.cpp](../examples/ch10_classes/4-DefaultDriver/Radio.cpp)

```{include=../examples/ch10_classes/4-DefaultDriver/Radio.cpp}
```
