---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 8, Strings & Vectors
title: 'Strings & Vectors'
---

## Chapter 8: Strings & Vectors

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## CStrings vs. `string`

- Below, we'll outline how you would directly store a string as an array of characters
- However, in general, it's much easier to use the `string` class to manipulate text data, as we have already been doing.
- This chapter is important for your understanding of C++ (and C), but I would recommend sticking to using the `string` class unless you have a good reason to use CStrings in C++

## CStrings

- So far, we've dealt only with string literals such as "Hello, World!", but what if we want to store strings as variables?
- We'll use what's called a _C-style string_ to do this

## CStrings are arrays

- Just any array!
- We can write an array of characters to form a string:

```c
char arr[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
```

- **But this is is not a C-string**
  - This is an array of characters, but not a C-style string.
- Well what is a C-string?
  - A character array whose final character is the null character `\0`:
- To write "Hello World!" as a C-string:

```c
char arr[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
```

- But this is incredibly tedious to define strings this way
- Fortunately, we can assign a character array to string literal to create a C-string

```c
char arr[] = "Hello, World!"; // arr will terminate with a null character.
                              // Null character is automatically added by the compiler
```

- Another example:

```c
char t[5] = "HI";
```

![IMAGE](resources/C2337804E361BB9DCBE2095C3204CC19.jpg)

- When we initialize a character using a string literal, the null character is automatically added
  - This means the character array must have enough space for every character of the string plus an additional element for the null character.
    - For instance, if we do the following, we don't end up with a C-string (there's no room for the entire string (and therefore there isn't room for the null character either)

```c
char arr[5] = "Hello, World!"; // arr only stores the first 5 chracters
                               // arr has the values [H', 'e', 'l', 'l', 'o']
```

- But we also don't have to fill up the entire array either, the null-character indicates the end of the string.
- **Bottom line**: a character array is only a character array if it is **null-terminated**, meaning the final character is the null-character
- Why does any of this matter?
  - Strings are an incredibly common data type in real-world data.
  - Storing names, addresses, email addresses, etc all required strings.
  - There is a very large standard library header, called `<cstring>`, that provides a wide range of functionality for CStrings.
    - All of this functionality relies on using CStrings, not character arrays.

## String Library

- Large library available for us to use to copy, compare, and manipulate strings.
- This is intended to help you, so you should view this as free functionality (as long as you are willing to read a tiny bit to figure out what the library functions do)
- Include the library with:

```c
#include <cstring>
```

- The following table summarizes the CString library

| Function          | Meaning               | Argument types   | Return type |
|-------------------|-----------------------|------------------|-------------|
| strcpy(dest, src) | dest = src            | cstring, cstring | void        |
| strcat(dest, src) | dest = dest + src     | cstring, cstring | void        |
| strlen(src)       | length of cstring src | cstring          | int         |
| strcmp(s1, s2)    | compares s1 and s2    | cstring, cstring | int         |

### Converting strings to other data types

- A bunch of functions to do this for you (included in `<cstdlib>`):
  - `atoi`: string to int
  - `atof`: string to float
  - `atol`: string to long
  - `strtod`: string to double
  - There are some more rare conversions provided by `<cstdlib>` as well

## Example: [`CStrings.cpp`](../examples/ch8_strings_vectors/CstringsDriver.cpp)

```{include=../examples/ch8_strings_vectors/CstringsDriver.cpp}
```

## Stream input

- By default, when we use the stream insertion operator `>>`, it will eat whitespace (meaning any whitespace in the input won't be received by our programs)
- But whitespace can be meaningful in strings
- To read character data, we can use the `getline` function
- The `getline` function has the following signature

```cpp
istream::getline(char s[], int i)
```

- This function reads up to `i-1` characters into `s` and will stop at a newline

```cpp
const int LINESIZE=80;
char line1[LINESIZE];
char line2[LINESIZE];

cin.getline( line1, LINESIZE );
cin.getline( line2, LINESIZE );
```

## Summarizing CStrings

- CStrings are not as nice to work with as `string`s
- At least you can always use loops to process character data, and look for the null-character `\0` to terminate the string

## `string` class

- With C++, we have a much easier way to work with strings, as we have been
- The `string` class is provided by the `<string>` library
- The class allows for:
  - Concatentation using the `+` operator
  - Default and string argument constructor (can construct an empty string or initialize with a string literal)
  - Character access using the `[]` operator (indexing like an array)
  - `<<` and `>>` have been overloaded as you would expect (similar to how `cout` and `cin` operate)
  - All boolean operators work as you would expect

```cpp
#include <string>

using namespace std;

int main() {
  string name, dog("dog"), hotdog;
  cin  >> name;
  hotdog = "hot " + dog;

  for (int i=0; i < name.length(); ++i) {
      cout << name[i] << " ";
  }
}
```

## `getline` for `string` objects

- `getline()` for `string` objects is a normal function, not a member of `istream`

```cpp
string& getline(istream& input, string& str, char delimiter = '\n' );
```

## `string` member functions

| Function            | Meaning                                    | Argument types | Return type |
|---------------------|--------------------------------------------|----------------|-------------|
| substring(pos, len) | substring starting at   pos for length len | int, int       | string      |
| empty()             | tests whether or not   the string is empty | int, string    | boolean     |
| insert(pos, str)    | inserts str at pos                         | int, string    | void        |
| remove(pos, len)    | remove starting at   pos for length len    | int, int       | void        |
| find(str)           | find first occurrence   of str in instance | string         | int         |

## Example: [`strings.cpp`](../examples/ch8_strings_vectors/StringDriver.cpp)

```{include=../examples/ch8_strings_vectors/StringDriver.cpp}
```

## Vectors

- Vectors are similar to arrays, but their size can change size as your program runs.
- Much like how the `string` class is easier to use than CStrings, the `vector` class is much easier to use than native C++ arrays
- The `vector` class is included in the `<vector>`
- Vectors have a base type
- To declare a vector with the base type int, we would write:

```cpp
vector<int> v; // creates a vector that can store ints
```

- Here, `<int>` identifies the template class
- You can use any base type in a template class

```cpp
vector<string> v; // creates a vector that can store strings
```

- Similar to arrays and strings, vectors are indexed starting at 0, and we use `[]` to read or change values of a item:

```cpp
v[i] = 42;
cout << v[i];
```

- But we can't use `[]` to initialize a new element (i.e. grow the vector)

## Initializing vector elements

- We can use the member funciton `push_back()` to add an element to a vector:

```cpp
vector<double> v;
v.push_back(0.0); // v contains [0.0]
v.push_back(1.1); // v contains [0.0, 1.1]
v.push_back(2.2); // v contains [0.0, 1.1, 2.2]
```

- We can also initialize multiple vector elements at a time:

```cpp
vector<int> v(10); // allocates a vector with 10 default-initialized integers
```

- With this initialization, we can use `[]` to assign values to elements 0-9, and `push_back` will generate a new element in position 10

## `size` of a vector

- With native arrays, we always had to keep track of how big our array was with a separate variable (e.g. `arr_len`)
- The `vector` class comes with a built-in member function `size` to return the number of elements in a vector
- To print every element of a vector, we might use:

```cpp
for (unsigned int i = 0; i < v.size(); i++){
  cout << v[i] << endl;
}
```

- We used an `unsigned int` instead of an `int` because:
  1. `unsigned int`s are nonnegative integers
  2. the `size()` function returns an `unsigned int`, so the compiler may issue a warning if the types don't match
