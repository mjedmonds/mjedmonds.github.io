---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 11, Friends, Overloading, and const
title: 'Friends, Overloading, Const'
---

## Chapter 11: Friends, Overloading, and const

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## `friend` functions

- `friend` functions are NOT member methods but have access to `private` members of that class
- `friend` functions must be named inside the class definition
- `friend` functions are always public regardless of where they are placed in the class definition
- We wary of using `friend` functions; they defeat the purpose of encapsulation, but can be necessary in some circumstances

## Number example

- Let's look at a Number class that uses a friend function to add two Numbers together
- Notice we didn't have to define the `add` function in the scope of `Number` (i.e. we didn't have to write `Number Number::add(Number left, Number right)`)
  - This is a bit unusual, but it's because `friend` functions aren't actually a member of the class

### Example [NumberDriver.cpp](../examples/ch14_friend_overloading/2-friend_functions-number/NumberDriver.cpp)

```{include=../examples/ch14_friend_overloading/2-friend_functions-number/NumberDriver.cpp}
```

### Example [Number.h](../examples/ch14_friend_overloading/2-friend_functions-number/Number.h)

```{include=../examples/ch14_friend_overloading/2-friend_functions-number/Number.h}
```

### Example [Number.cpp](../examples/ch14_friend_overloading/2-friend_functions-number/Number.cpp)

```{include=../examples/ch14_friend_overloading/2-friend_functions-number/Number.cpp}
```

## const revisited

- Remember our qualifier `const`. It makes the type unmodifiable, meaning the value is not allowed to be changed.
  - If we wrote `const int a = 5;` it means the integer `a` is initialized to 5 and cannot be changed to a value other than 5
- For a quick example:

```cpp
const int DAYS_IN_WEEK = 7;

for (int i = 0; i < DAYS_IN_WEEK; i++) {
    read_textbook_chapter();
    study();
}
```

- `const` can also be applied to function parameters (as was briefly mentioned with the notes on pass-by-reference)
  - `const` is unnecessary with call-by-value parameters
  - `const` can be applied to call-by-reference parameters
    - We should prefer to use call-by-reference when we are passing objects (from either structs or classes)
    - If no changes are made to the object, we can pass by constant reference (e.g. `const MyClass& my_object`)
- `const` can also be applied to member functions. This means the function is not allowed to modify the object; i.e. the function is not allowed to modify an member variables.

## `const` Number example

- Notice our `printRomanNumeral()` method is a `const` method (not allowed to modify member variables of the object)
- Notice we passed `left` and `right` by constant reference to the `add()` `friend` function

### Example [ConstDriver.cpp](../examples/ch14_friend_overloading/3-ConstDriver/ConstDriver.cpp)

```{include=../examples/ch14_friend_overloading/3-ConstDriver/ConstDriver.cpp}
```

### Example [Number.h](../examples/ch14_friend_overloading/3-ConstDriver/Number.h)

```{include=../examples/ch14_friend_overloading/3-ConstDriver/Number.h}
```

### Example [Number.cpp](../examples/ch14_friend_overloading/3-ConstDriver/Number.cpp)

```{include=../examples/ch14_friend_overloading/3-ConstDriver/Number.cpp}
```

# Overloading operators

```cpp
Number four = Number(4);
Number five = Number(5);

// Wouldn't it be wonderful if we could do the following
Number nine = four + five;
```

- Adding two numbers may make intuitive sense, but `Number` is a class. What does it mean to add two classes together?
  - For our `Number` class, you may be able to imagine what this would mean
  - But what about for a car? What about for a bank account?
- Most of the operators we have used thus far can be *overloaded*
  - `+`, `-`, `==`, `/`, `*`, `++`, `--`, `+=`, `-=`, `*=`, `/=` can all be overloaded
  - We cannot overload the `::` and `.` operators
- These operators are all just functions, but we have to list their arguments differently than what we are used to
- Operators are defined as `friend` functions, typically with `const` argument parameters

```cpp
friend Number operator +(const Number& left, const Number& right);

friend bool operator ==(const Number& left, const Number& right);
```

## Number overloaded operator example

- This example shows how to overload a number of operators

### Example [OperatorDriver.cpp](../examples/ch14_friend_overloading/4-OperatorDriver/OperatorDriver.cpp)

```{include=../examples/ch14_friend_overloading/4-OperatorDriver/OperatorDriver.cpp}
```

### Example [Number.h](../examples/ch14_friend_overloading/4-OperatorDriver/Number.h)

```{include=../examples/ch14_friend_overloading/4-OperatorDriver/Number.h}
```

### Example [Number.cpp](../examples/ch14_friend_overloading/4-OperatorDriver/Number.cpp)

```{include=../examples/ch14_friend_overloading/4-OperatorDriver/Number.cpp}
```

## Overloading `<<` and `>>`

- `cout` and `cin` use these operators to print information to the screen and extract information from user input
- For our number class, it may look like this:

```cpp
friend ostream& operator <<(ostream& outs, const Number& n);

friend istream& operator >>(istream& ins, Number& n);
```

### Example [InsertExtract.cpp](../examples/ch14_friend_overloading/5-InsertExtract/InsertExtract.cpp)

```{include=../examples/ch14_friend_overloading/5-InsertExtract/InsertExtract.cpp}
```

### Example [Number.h](../examples/ch14_friend_overloading/5-InsertExtract/Number.h)

```{include=../examples/ch14_friend_overloading/5-InsertExtract/Number.h}
```

### Example [Number.cpp](../examples/ch14_friend_overloading/5-InsertExtract/Number.cpp)

```{include=../examples/ch14_friend_overloading/5-InsertExtract/Number.cpp}
```
