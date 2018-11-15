---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 1, Introduction to Computers and C++ Programming
title: 'Introduction to C++'
---

## Chapter 1: Introduction to Computers and C++ Programming

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## What is a program?

- A program is a set of instructions for a computer to follow
- We will write *source code* that is *compiled* into instructions the computer can execute
- C++ is considered a high-level language that allows programmers to write English-like sentences to describe a program, rather than low-level machine (binary; 1's and 0's) instructions for the processor

## Introduction to C++

- C++ is a *compiled* language, meaning an entire program is converted into machine instructions at once
  - This is in contrast to *interpreted* languages, where the program is converted to machine instructions as the program executes (line by line)

![Compilation process](./images/ch1_compilation.png)

## History of C++

- Authored by Bjorne Stroustrup, AT&T
- Extended the C Language
  - Added features to support Object-Oriented Programming
- C++ is considered a superset of C
- Language is now an international standard
  - American National Standards Institute
  - International Standards Organization

## Program Development

- What is an *Algorithm*?
  - A sequence of precise instructions thatl eads to a solution
- What is a *Program*?
  - An algorithm expressed in a language the computer can understand

## Program Development

![Program development process](./images/ch1_program_development.png)

## Example [hello_world.cpp](../examples/ch1_intro/hello_world.cpp)

```{include=../examples/ch1_intro/hello_world.cpp}
```

## Fixing Programs

- Most programs do not work initially
- There are multiple reasons why a program does not work:
  1. A *syntax error* means your source code cannot be converted into machine code. This source code cannot produce a valid C++ program, and therefore can never be run
  2. A *runtime error* means your program has executed into a state not permissible by the program or by C++; in this case your program will crash.
  3. A *logic error* means your program compiles and runs without error, but does not produce the expected result
      - Hardest error to fix!

## Fixing Programs

- Fixing these problems consists of:
  1. *Syntax error*: examine the error and determine a fix in your source code
  2. *Runtime error*: examine the error and add error handling mechanisms to correct the error
  3. *Logic error*: examine your understanding the problem (can you solve it on a piece of paper by hand?) and make sure your program implements the same logic

## Fixing Programs

- A *debugger* can be used to inspect your program as it executes
  - This helps fix runtime and logic errors
  - Allows you to trace the execution of a program and verify it behaves as you intend

## Input and Output in C++

- Input and output allows you to get information from the user (input) and display information to the user (output)
  - We have already seen output with our `cout` statements in [`hello_world.cpp`](../examples/ch1_intro/hello_world.cpp)

## Input and Ouput in C++

- C++ input statement:
  - `cin >> number;`
  - Value is extracted from the keyboard and stored in the variable called `number`
- C++ output statement:
  - `cout << "Hello, world!";`
  - Sends information from program to the terminal screen
  - Double quotes `"..."` delimit a *string*
  - `\n` sends a *newline character* to the terminal (carriage return)

## Variables and Datatypes

- Variables are named memory locations to store data in
- Think of them like a box that you can store data in
- You refer to a particular box through a name (called an *identifier*)
- Variables must be declared
  - Variable declarations tell the computer "I want a box named `my_variable_name` to store data of a particular type"

## Variables and Datatypes

==========================
| Datatype | Description |
==========================

FILL IN TABLE

## Variables and Datatypes

- Identifiers are the names of variables
- Identifiers must:
  - Begin with `a-z`, `A-Z`, or `_`
  - Followed by `a-z`, `A-Z`, `0-9` or `_`
- Identifiers are case-sensitive
- It is best practice to initialize variable values when they are delcared

## Keywords

- Keywords have special meaning to C++; they are reserved for the language itself

INSERT TABLE OF KEYWORDS

- We will learn more about these keywords as we go, but you cannot use a keyword for anything other than it's purpose as a keyword (i.e. you cannot use a keyword as an identifier)

## Literals

- A literal, fixed, static value used in a program
- Three basic types of literals in C++

INSERT TABLE OF LITERALS

## Literals vs. Variables

- A literal is a fixed values that never changes
- A variable is a container for data
  - A variable can change its data over time
  - A variable can only hold one value at a time
- A literal has no "box" (memory) to store data in; a literal is a fixed value embedded in your program.