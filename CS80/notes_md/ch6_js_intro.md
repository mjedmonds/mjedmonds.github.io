---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 6, Javascript, Introduction to Scripting
title: 'Javascript: Introduction to Scripting'
---

## Chapter 6: Javascript: Introduction to Scripting

CS 80: Internet Programming

Instructor: Mark Edmonds

## Welcome to Javascript!

- What is javascript?
  - Client side scripting language
- What is scripting?
  - Generally tied with interpreted languages, meaning the code is translated to machine code right before execution (vs. compiled code)

## Welcome to Javascript!

Why do we care?

- HTML and CSS give us a lot of control over content, structure, and presentation, but we still lack the ability to have dynamic or computational websites
- Javascript offers client-side programming, enabling fun stuff like these:
  - <https://codepen.io/HarrisCarney/pen/dPjKyK>
  - <https://codepen.io/GabbeV/pen/viAec>
  - <https://codepen.io/dissimulate/details/eZxEBO/>
- Clearly some powerful stuff!
- We will start small and with fundamentals; there are many libraries to help you with graphics
- We will concentrate on logic

## Getting Started

- `<script>` HTML element allows us to add Javascript to our HTML document
  - Typically goes in the `<head>` portion of the document
- Example:

  ```html
  <script type="text/javascript"> script_stuff </script>
  ```

## Example: [`hello_world.html`](../examples/ch6_js/hello_world.html)

```{include=../examples/ch6_js/hello_world.html}
```

## Example: [`hello_world.html`](../examples/ch6_js/hello_world.html)

- Finally we see the object model!
- We will see more, but for now:
- `document` is the HTML document, represented through a javascript object
  - We will cover this concept in more detail in Chapter 12 (Document Object Model)
- `.writeln()` is a method within the `document` object
  - It writes content to the HTML document, followed by a new line (that\'s the `ln`)
  - `"<h1>Welcome to JavaScript Programming!</h1>"` is a **string** and is the content to write to the HTML document

## External Javascript Files

- Example

  ```html
  <script src="srcipt.js">
  ```

- Loads the Javascript in `srcipt.js` into this HTML document

## Javascript Basics

Statements and Keywords
  
- **Keywords** are words with special meaning to javascript
  - `var` is an example
- A **statement** is a program statement to execute by the javascript
    interpreter
  - Statements are terminated with a semicolon `;`, as in [`hello_world.html`](../examples/ch6_js/hello_world.html)

## Javascript Basics

Variables

- A **variable** is a container to store data in
  - Think about this like a math variable, but in javascript, variables can store any data
  - *Declared* with `var myVar;`
    - Can declare multiple variables at once with a comma-serparated list
      - E.g. `var myVar, myVar1, myVar2;`
  - *Assign* the variable a value with `myVar = 5;`

## Example: [`hello_world_variables.html`](../examples/ch6_js/hello_world_variables.html)

```{include=../examples/ch6_js/hello_world_variables.html}
```

## Javascript Basics

Variables

- Sidenote: Javascript variables do not have a type; their type is determined by the content they store
  - What does this mean? Well, we\'ve seen `var` be assigned to a string (`hello_world_variables.html`) and to a number (above, `myVar =5;`).
    - So `var` represents any variable, could be a string, could be an int
    - This contrasts with many programming languages, like C/C++, Java
    - Moreover, a variable is not bound to a particular type. We can reassign it at any time to any type (e.g. `myVar = 5; myVar = "cheese";`)

## Javascript Basics

Variables

- Despite the fact variables can store any types, we still have to have a notion of types (take more CS courses to learn more about this!)
  - **String**: a string of text. E.g. `var myVar = "cheese";`
    - Can use double or single quotes, but must be consistent (whatever you start the string with, you must end the string with)
  - **Number**: a number. E.g. `var myVar = 5;`
  - **Boolean**: True/False value. E.g. `var myVar = true;`

## Javascript Basics

Variables

- **Array**: multiple of values in one variable. E.g. `var myVar = [5, "cheese", false];`
  - Elements are accessed using 0-indexing
  - E.g. `myVar[0]` is `5`, `myVar[2]` is `false`
- **Object**: everything in javascript is an object, and you can store objects in variables. E.g. `var myVar = document;`

## Javascript Basics

- **Identifiers**
  - Formal name for a variable\'s name (e.g. `myVar`)
  - Can contain letters, digits, underscores,and dollar signs.
  - Must not begin with a digit and must not be a keyword

## Javascript Basics

- Comments
  - Single line: start with `//`
  - Multiline: start with `/*` ends with `*/`

## Javascript Basics

- **Literals** are literal values you provide your script
  - They do not change value
  - Can you spot the literal?
    - `var myVar = 5;`
    - `var myVar = "cheese";`
  - These are not modifable, fixed values provided by you, the programmer.

## Javascript Basics

Basic Operators

- **Basic Operators** define operations on variables or literals. Used to process data. We will talk about more as we go along.

## Javascript Basics

Basic Operators

- **Addition/Concatenation**: `+`, used to add two numbers together, or merge two strings
  - `6 + 9;` yields `15`
  - `"Hello " + "world!"` yields `"Hello world!"`

## Javascript Basics

Basic Operators

- **Subtract, multiply, divide**: `-`, `*`, `/`, used just as they in basic math (you can\'t divide a string by another string, concatenation is special!)
  - `6 * 5;` yields `30`

## Javascript Basics

Basic Operators

- **Assignment**: `=`, we\'ve already seen this. It\'s used to take a value (either an object or a literal) and assign it another object (typically a variable)
  - `var myVar = 6 * 5;` assigns `myVar` to `30`

## Javascript Basics

Basic Operators

- **Remainder**: `%`, used to perform modulo.
  - Modulo/remainder division finds the remainder of an integer division
  - E.g. `11 % 5` yields `1` because `11 = 5 * 2 + 1`
    - We are interested in the `1`, since that is the remainder when you divide `11` by `5`

## Javascript Basics

Opertaor Precedence

- Remember PEMDAS? (Parenthsis, Exponents, Multiplication and Division, and Addition and Subtraction)
  - Defines the mathematical order-of-operations

## Javascript Basics

Escape Sequences

- Used to give or take away meaning from special characters
- `\n`: a new line (carriage return, like hitting enter)
- `\t`: a tab
- `\\`: a literal backslash (since `\` normally has special meaning - to escape other characters!)
- `\"`: double quote - for nested double quotes
  - Need to escape so we don\'t accidentally end the string!
- `\'`: single quote - for nested single quotes
  - Need to escape so we don\'t accidentally end the string!

## Javascript Basics

Examples

- [`alert.html`](../examples/ch6_js/alert.html)
  - `window` object refers the browser\'s window
  - `alert` opens a dialog to display the string
  - Take a look at `window` methods and attributes: <http://www.w3schools.com/jsref/obj_window.asp>

## Example: [`alert.html`](../examples/ch6_js/alert.html)

```{include=../examples/ch6_js/alert.html}
```

## Javascript Basics

Examples

- [`dynamic_welcome.html`](../examples/ch6_js/dynamic_welcome.html)
  - Again using `window` with `prompt()` method to ask for user input
  - Creates a dynamic welcome page
  - We couldn\'t do with this HTML and CSS

## Example: [`dynamic_welcome.html`](../examples/ch6_js/dynamic_welcome.html)

```{include=../examples/ch6_js/dynamic_welcome.html}
```

## Javascript Basics

Examples

- [`addition.html`](../examples/ch6_js/addition.html)
  - `parseInt()` function converts a string to an integer

## Example: [`addition.html`](../examples/ch6_js/addition.html)

```{include=../examples/ch6_js/addition.html}
```

## Javascript Basics

Operators and Conditionals

- We need a way to encode logic - a way to direct the program based on the program\'s state
- Primary method of controlling a programs flow
- Basic idea: \"if a condition is true, execute some code\"
  - We can stop at the if or say \"if a condition is true, execute some code, otherwise, execute this other code\"

## Javascript Basics

Operators and Conditionals

- Example:

  ```javascript
  // basic conditional
  if(5 <= 10){
    document.writeln("5 is indeed less than 10");
  } else {
    document.writeln("5 is somehow not less than 10...");
  }
  ```

## Javascript Basics

Operators and Conditionals

- But we can do even more by nesting if\'s!
  - Also allows us to check for multiple potential conditions at once (e.g. `if(cond)...else if(cond)...else...`)

## Javascript Basics

Operators and Conditionals

- Example: where `time` is the hour of the day (0-23)

  ```javascript
  // order of the conditionals matters; what happens if we flip them?
  if (time < 10) {
    greeting = "Good morning";
  } else if (time < 20) {
    greeting = "Good day";
  } else {
    greeting = "Good evening";
  }
  ```

## Javascript Basics

Equality and Relational Operators

![Javascript relational operators](images/js-relational-operators.png)

## Javascript Basics

Operators and Conditionals

- Difference between `===` and `==`
  - `===` is a more strict comparison operator
  - E.g. `"75" == 75` yields true but `"75" === 75` yields false

## Javascript Basics

Operators and Conditionals

- Compound conditionals:
  - Use logical operations `AND`, `OR`, and `NOT`
  - `AND` is represented with `&&`
  - `OR` is represented with `||`
  - `NOT` is represented with `!`
  - Combining conditions allows us to use much more powerful program flow

## Javascript Basics

Operators and Conditionals

- Compound conditionals will evaluate left to right
  - If the program can determine the overall value of the compound conditional, it will stop evaluting the rest of the conditional
  - E.g. Suppose `cond_a` is `true` and `cond_b` is `false`. 
    - `if(cond_a || cond_b)` doens\'t need to look at the value of `cond_b`, the overall condition is determined by `cond_a`.
    - Similarly, `if(cond_b  cond_a)` doesn\'t need to look at the value of `cond_a`, since `cond_b` already determined the overall state of the compound conditional.
    - Remember: left to right!
  - **Key takeaway** order matters!

## Javascript Basics

Operators and Conditionals

- Example: (pay close attention to evaluation order)

  ```javascript
  // be careful analyzing this conditional
  if(cond_a && cond_b){
    // only executes if cond_a AND cond_b are true
  } else if(cond_a || cond_d){
    // only executes if 1) cond_a is true AND cond_b is false (think about why) OR cond_d is true
  } else if(!cond_d){
    // only executes if cond_a is false AND cond_d is true
  } else {
    // will this ever execute?
    // otherwise
  }
  ```

## Exercise

- Display the current day and time in the following format:

  ```text
  Today is: Friday
  Current time is: 4:50:22PM
  ```

- **First step**: look at the `Date()` javascript function
  - <http://www.w3schools.com/jsref/jsref_obj_date.asp>

## Example: [`date_print.html`](../examples/ch6_js/date_print.html)

```{include=../examples/ch6_js/date_print.html}
```

## Exercise

- Write a program that determines if the inputted year is a leap year:
  - Every year that is divisible by 4, except for years divisible by 100, except for years that are divisible by 400
- **First step**: come up with an algorithm to check

## Example: [`leap_year_checker.html`](../examples/ch6_js/leap_year_checker.html)

```{include=../examples/ch6_js/leap_year_checker.html}
```

## Developer Tools

- No program is perfect at first
- We need a way to examine program state as the program is running
  - This will enable us to understand and fix problems in our code
- Debugging will help fix any error, but it\'s particularly good for identifying edge cases you may have not considered when writing your program
  - Common edge cases: empty string `""`, zero `0`, negative numbers, etc

## Developer Tools

- The debugger is present in any modern browser and has two main elements for javascript: console and debugger
- **Since we are editing the program as it executes, we need to remember where we are in execution**
  - Variables may not exist yet
- How to write information to the console to inspect state:
  - Use a `console.log()` statement in your javascript
  - The value/text arguments will be printed to the Console section of the Developer Tools

## Developer Tools

- Setting a breakpoint
  - Breakpoints say \"when you hit this line of code, pause the program for me\"
  - They allow you to inspect variable/program state during execution
  - Enable a breakpoint by clicking the line number
  - Important semantic note: The line of the breakpoint has **not** executed yet. It is about to execute
    - E.g. if we set a breakpoint on line 9, line 9 hasn\'t executed when the breakpoint triggers (line 8 has, however)
    - Keep this in mind!

## Developer Tools

- Stepping through a program
  - Once we are at a breakpoint we have multiple options to control the program:
    - Step Over: step over the current line of code. This means if we are at a function call, **do not** move the debugger into the function. Instead, the function will execute, and the program will pause after function completes
    - Step Into: If the program is about to call a function, move the debugger into that function and pause execution
    - Step Out: Finish the current function call and pause execution at the calling function
    - Continue: Continue the program\'s execution; basically unpauses the program

## Developer Tools

- We can also call functions or inspect variables while paused using the console
  - Move to the console, and type a javascript statement to execute
    - Can also just type variable names to get their value
  - If the javascript statement we called doesn\'t have a return value (e.g. statement doesn\'t yield a value), then the console will report `undefined`.

## Developer Tools
- Each browser has a slightly different interface, but the developer tools work the same way for all.
- Chrome introduction: [https://developers.google.com/web/tools/chrome-devtools/javascript](https://developers.google.com/web/tools/chrome-devtools/javascript)
- Firefox introduction: [https://developer.mozilla.org/en-US/docs/Tools/Debugger](https://developer.mozilla.org/en-US/docs/Tools/Debugger)

## Javascript Functions

- Functions enable reuseable code
- Sum example:

  ```javascript
  // function declaration
  function sum1(a, b){
    // do other amazing javascript things here
    return a + b;
  }
  ```

- We can then call `sum(10, 5)` which would return `15`

## Javascript Functions

- Assigning functions to variables

- Sum example:

  ```javascript
  // anonymous function assigned to variable
  var sum2 = function(a,b){
    return a + b;
  }
  ```

- We can then call `sum2(10, 5)` which would return `15`

## Javascript Functions

Hoisting
  
- The only thing you need to remember is that functions of the form of `sum1` are \"hoisted\" to the top of your program, meaning they can be used *before* they are declared
