---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 5, Functions for All Subtasks
title: 'Functions for all subtasks'
---

## Chapter 5: Functions for all subtasks

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## Call-by-reference parameters

- So far, when we've passed arguments to a function, those arguments were copied inside of the scope of the function, meaning any modification inside of the function will not affect the caller's variables.
- To illustrate this, consider the following:

```c++
#include <iostream>

using namespace std;

int dummy_func(int param){
  // this modification doesn't affect the variable that was passed into the function
  param++;
  return param;
}

int main(){
  int a = 5;
  int b = dummy_func(a); // a is copied to dummy_func
  // since a was copied (and then the copied value was modified in dummy_func, then returned), the value of a in main does not change
  cout << "a: " << a << ", b: " << b << endl;
}
```

- For call-by-reference, the basic idea is instead of copying arguments to a function, use the same underlying memory location to pass values into a function (i.e. instead of duplicating the caller's box when calling a function, use the same box).
  - Call-by-reference is also called "pass-by-reference"
- Call-by-reference prevents the value from being copied and instead tells the function to directly modify the variable stored in the caller's scope
  - This is clearly useful!
  - So far, we've only been able to return a single data type, but if we can modify parameters in the caller's scope, we have a way to "return" multiple values by telling the parameters "not to copy" into the function's scope.
- To pass a variable by reference, we modify its type to include a `&` to indicate we wish to use a reference to the type:

```c++
#include <iostream>

using namespace std;

int dummy_func(int& param){ // the int& indicates we want a reference to an int as the argument
  // this modification WILL affect param in the caller's scope
  param++;
  return param;
}

int main(){
  int a = 5;
  int b = dummy_func(a); // a is not copied to dummy_func, but instead is passed by reference
  // since a was NOT copied and instead passed by reference, the value of a in main DOES change
  cout << "a: " << a << ", b: " << b << endl;
}
```

### Call-by-reference use cases

- But when would you use this? Why would you use this? There are two main cases:

1. "Returning" multiple values from a function
     - Previously, if we wanted to return a value from a function, we could return at most one value of the type specified by the `rtype` in the function signature
     - Pass-by-reference allows us to "return" values. For instance, `dummy_func` could be made a `void function`. We can then extend this to "return" multiple things from a function, by passing every "return" variable by reference:

```c++
void dummy_func(int& param){ // the int& indicates we want a reference to an int as the argument
  // this modification WILL affect param in the caller's scope
  param++;
  // we don't really need to return in this case, as param has already been modified in the caller's scope
}
```

2. Memory efficiency
     - Since there is no copy that occurs when we pass-by-reference, we can save time by preventing the computer from copying a large amount a data from the caller to callee (this will be relevant later once we learn about classes and structs)
     - To do this, you would typically pass by *constant* reference, so the callee cannot modify the data. For the function signature of `dummy_func` above could be: `int dummy_func(const int& param)` (note the `param++` line would then fail to compile, as we aren't allowed to modify a constant `int`)

### reference.cpp

- This program showcases uses cases of pass-by-reference

```cpp
// This program demonstrates how you can use reference parameters

#include <iostream>          // for std::cout and std::cin
using namespace std;         // supports cout

void get_values( int& input1, int& input2 );
void swap_values( int& var1, int& var2 );
void show_values( int value1, int value2 );

int main( )
{
  int first = 0, second = 0;

  get_values( first, second );
  show_values( first, second );
  swap_values( first, second );
  show_values( first, second );
  return 0;
}

// this effectively implements a "multiple return" as our two parameters are modified by the function
void get_values( int& input1, int& input2 )
{
  cout << "Please enter two values: ";
  cin  >> input1 >> input2;
}

// this also implments a "multiple return"
void swap_values( int& var1, int& var2 )
{
  int temp = var2;
  var2 = var1;
  var1 = temp;
}

void show_values( int value1, int value2 )
{
  cout << "value1 = " << value1 << " and value2 = " << value2 << endl;
}
```

## Debugging & Testing

- It is very difficult to write correctly the first time. Even for the most experienced programmers
- Writing *tests* and *debugging* your code is a great way to ensure you find problems with your code *before* it causes a problem for your employer, client, or customer.
- In fact, this is the basis of the automated grading system used in this course.
  - When you submit your code, a series of tests are launched to check the output of your code against known correct values
  - Getting in the habit of writing test cases for your code is a very good idea and will make life less painful later on

### Debugging Techniques

- Debugging is a bit of an art. One thing to keep in mind is to keep an open mind. It's extremely common to be quite certain you know the error is in one part of the code, when it's actually in another.
  - Implementing sanity checks as you code can help alleviate this; if you KNOW your program works up to point, you have a much better idea where the problem is. You need to have actually written code to verify that the program works up to a certain point; don't just think it works up to that point. Prove it with a check.
- You can use the debugger in Visual Studio or XCode (or any IDE) to help step through and inspect variable values as your program executes.
  - [Visual studio debugging guide](https://docs.microsoft.com/en-us/visualstudio/debugger/debugger-feature-tour?view=vs-2019)
  - [XCode debugging guide](https://developer.apple.com/library/archive/documentation/ToolsLanguages/Conceptual/Xcode_Overview/UsingtheDebugger.html)
  - All debuggers rely on a few concepts. They control where to stop executing and pause using *breakpoints*. Once the program is paused at a breakpoint, you can:
    - *continue* (continue running the program until the next breakpoint is hit or the program terminates)
    - *step over* (go to the next line of code, jumping over any function calls)
    - *step in* (if the current line is a function call, go inside of the function and pause)
    - *step out* (execute the current function to completion and pause at the next line of the caller's function)
    - If the current line is not a function call, *step over* and *step in* are equivalent
- The `assert` statement is extremely helpful to writing tests
  - Assert statements can be used to check an expected *pre-condition* or *post-condition* of a function
  - A *pre-condition* of a function is a condition that the function expects to be met before the function can correctly execute. For instance, a pre-condition may be that one of the arguments is greater than 0
  - A *post-condition* of a function is a condition that should be true after the function has executed. For instance, a post-condition may be the the return value is greater than an input argument
  - Include the `<cassert>` library to use the `assert` macro
  - As an example of how to use an assert, consider the following test for our original `dummy_func`:

```c++
#include <iostream>
#include <cassert>

using namespace std;

int dummy_func(int param){
  param++;
  return param;
}

int main(){
  int a = 5;
  int b = dummy_func(a);
  assert(b == 6); // b should be incremented
  assert(a == 5); // a should not have been modified
  cout << "a: " << a << ", b: " << b << endl;
}
```

## Exercises

1. Write a function to swap the values stored in two variables

```c++
// function definition to swap the values.
void swap(int &x, int &y) {
  int temp;
  temp = x; /* save the value at address x */
  x = y;    /* put y into x */
  y = temp; /* put x into y */
  return;
}
```

2. Write a test case to verify that the `swap` function works correctly

```c++
#include <iostream>
#include <cassert>

using namespace std;

// function definition to swap the values.
void swap(int &x, int &y) {
  int temp;
  temp = x; /* save the value at address x */
  x = y;    /* put y into x */
  y = temp; /* put x into y */
  return;
}

int main(){
  int test1 = 2, test2 = 7;
  swap(test1, test2);
  assert(test1 == 7); // test1 should be swapped with original value of test2
  assert(test2 == 2); // test2 should be swapped with original value of test1
}
```
