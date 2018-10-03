---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 18, PHP
title: PHP
---

## Chapter 18: PHP

CS 80: Internet Programming

Instructor: Mark Edmonds

## PHP

- Extremely common
- Open-source
- Platform independent

## Preliminaries

- PHP handles client requests
- PHP is embedded into HTML documents, but executes on the server *before* the HTML document is delivered to the client
- PHP files have the extension .php

## Preliminaries

- php code resides between `<?php /* PHP code */ ?>`
  - Single line php comments start with `//`
  - Multiline comments are enclosed with `/* */`
- Statements terminated with a semicolon `;` (required)

## Variables

- Declared with `$name`
  - `name` must start with a letter or underscore
  - `name` can only contain `A-z`, `0-9`, and `_`

## Variables

- Variables are case-sensitive
- Loosely typed
  - Similar idea as Javascript. Variables have types, but their type can change on the fly
  - In PHP, we have to explicitly change types

## PHP Types

![PHP Types](images/ch19_php_types.png)

## Example: [`first.php`](../examples/ch19_php/first.php)

```{include=../examples/ch19_php/first.php}
```

## Important Notes

- Line 6 declares a php variable named `name` and sets it equal to Paul
- Line 14 prints text into the `<h1>` tag **before the file is served to the client**
  - Note that the value of `$name` is printed, not the string \"\$name\"
  - Double quoted strings will have variables evaluated (called *interpolating* a variable)
  - Single quoted strings will have the entire string taken as a literal value (no interpolation)

## Example: [`data.php`](../examples/ch19_php/data.php)

```{include=../examples/ch19_php/data.php}
```

## Types and Conversion

- `gettype` gets the type of the parameter
- `settype` changes the type of first parameter to the second parameter
- Using `settype` can result in data loss: values may be truncated
  - For example, converting 3.5 to an int yields 3, and converting the int back to a double yields 3
  - Same thing happens with strings \"3.5 seconds\" as a double becomes 3.5

## Types and Conversion

- Casting
  - Creates a temporary copy of the data before converting it
  - Means we won\'t lose data
  - Useful when a different type is required for a specific oepration, but you want to retain the original value

## String Concatenation

- Same as with javascript, but the operator is `.`

## Constant values

- Created with `define("NAME", value);`
- Not a variable, a constant
- Used by simply typing `NAME` where you want the value

## Conditionals

- Basically the same as Javscript, but `else if` is `elseif` (another keyword)

## Arithmetic Operators

- Same as Javascript

## Example: [`operators.php`](../examples/ch19_php/operators.php)

```{include=../examples/ch19_php/operators.php}
```

## Arrays

- PHP also supports arrays
  - Note that if an array does not exist, but is assigned, the array will be created
- PHP arrays may be *associative arrays*, meaning they have non-integer indicies
  - E.g. you index an array by a name, or by student ID number (stored as a string)

## Arrays

- `reset` resets the internal pointer of the array to the beginning of the array
  - `key` returns the index of the element pointed to by the internal pointer
  - `next` moves the internal pointer down one element of the array
- `foreach` is specifically for iterating through arrays
  - `as` divides the key/value (key is on the left, value is on the right

## Example: [`array.php`](../examples/ch19_php/array.php)

```{include=../examples/ch19_php/array.php}
```

## String Comparisons

- `strcmp` compares two strings.
  - returns -1 if the first string alphabetically precedes the second string
  - returns 0 if the two strings are equal
  - returns 1 if the first string alphabetically follows the second string
- Can also use relational operators
  - `==, !=, <, <=, >, >=`

## Example: [`compare.php`](../examples/ch19_php/compare.php)

```{include=../examples/ch19_php/compare.php}
```

## Regular Expressions

- There is no escape from regular expressions
- php uses the `preg_match` function to search for a string with the specified pattern

## Regular Expressions

- Important regex characters
  - `^` means beginning of line
  - `$` means end of line
  - `[]` denotes a bracket expression
    - lists of characters
    - can specify a range with `-`
    - E.g. `[a-z]` are all characters a through z

## Regular Expressions

- Quantifiers
  - specifies a quanity to match with the previous expression
  - `*` means \'zero or more times\'
  - `+` means \'one or more times\'
  - `?` means \'zero or one times\'
  - `{n}` means \'exactly n times\'
  - `{m,n}` means \'between m and n times\'
  - `{n,}` means \'n or more times\'

## Character Classes

![Regex Character Classes](images/ch19_character_classes.png)

## Example: [`expression.php`](../examples/ch19_php/expression.php)

```{include=../examples/ch19_php/expression.php}
```

## Form Processing

Superglobal Arrays

- Special arrays that contain client information
- Client information includes:
  - Client\'s web browser
  - Data sent to the server by the client `$_GET` and `$_POST`
    - E.g. if the user submit\'s a form and it is posted to a script (remember the `action` attribute), then the information is available in the `$_POST` array
  - Cookies

## Superglobal Arrays

![Superglobal arrays](images/ch19_superglobal_arrays.png)

## Example: [`form.html`](../examples/ch19_php/form.html)

```{include=../examples/ch19_php/form.html}
```

## Form Processing

- Let\'s break down this form (it\'s been a while)
  - It uses the `POST` HTTP method to send data to `form.php`
  - It has the following inputs:
    - `fname` (text)
    - `lname` (text)
    - `email` (text)
    - `phone` (text)
    - `book` (options)
    - `os` (radio)

## Form Processing

- So when we hit `Register` (the `submit` input), we will send the inputs to `form.php` using the `$_POST` superarray
  - Had we used the `GET` method we\'d see values in the `$_GET` superarray
- The input names are the glue; the register an input to an entry in the superarray
  - This is why names mattered in chapter 2/3!!

## Example: [`form.php`](../examples/ch19_php/form.php)

```{include=../examples/ch19_php/form.php}
```

## Form Processing

- This validates the phone number!
  - Very important to validate your form inputs
- `die()` terminates the script, stops processing the form

## Example: [`data.html`](../examples/ch19_php/data.html)

```{include=../examples/ch19_php/data.html}
```

## Example: [`database.php`](../examples/ch19_php/database.php)

```{include=../examples/ch19_php/database.php}
```

## Database Processing

- This assumed we followed the Chapter 18 instructions for setting up MySQL
  - Includes source-ing the `products.sql` file
- `mysqli_connect` connects to the database
- `mysqli_select_db` opens the `products` database
- `mysqli_query` executes a MySQL query (what we learned about in chatper 18)
- `mysqli_close` closes the database

## Database Processing

- `mysqli_fetch_row` returns an associative array containing the column of the current row from the query result
  - The `key` is a unique column ID for the query
- `mysqli_fecth_assoc` returns an associative array where the column names are the keys storing the corresponding values
- `mysqli_num_rows` stores the number of rows in the query result

## Cookies

- What is a cookie?
  - A piece of information from the server that resides on the client\'s computer
  - Just a text file
  - Maintains information about the client in between browsing sessions
    - Cookies mean you don\'t have to login everytime you visit a website
    - The cookie stores your login session (not password), basically meaning the website assumes you are the same user
  - You can disable cookies if you want, but it makes browsing significantly more annoying!
  - Can also track other client activity

## Cookies

- Cookies are text files
  - Should never store passwords, credit card info, etc
- Cookies are only accessible by the website that placed the cookie on the client\'s computer
- Cookies have an expiration date - at which point the browser will delete the cookie off of the client\'s computer
- Cookies are sent back to the originating server when the user connects to that server

## Example: [`cookies.html`](../examples/ch19_php/cookies.html)

```{include=../examples/ch19_php/cookies.html}
```

## Example: [`cookies.php`](../examples/ch19_php/cookies.php)

```{include=../examples/ch19_php/cookies.php}
```

## Cookies

- `setcookie` creates a cookie
  - First parameter is the name
  - Second parameter is the data
  - Third parameter is the expiration date
    - If there is no expiration date, the cookie is a *session cookie*, which means it only exists during the current browsing session (when the user closes the browser, the session ends)
    - If a expiration date is specified, we call this cookie a *persistent cookie*
- Cookies are then accessible through the `$_COOKIE` superarray

## Example: [`readCookies.php`](../examples/ch19_php/readCookies.php)

```{include=../examples/ch19_php/readCookies.php}
```