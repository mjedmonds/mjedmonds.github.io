---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 6, I/O and Streams
title: 'I/O and Streams'
---

## Chapter 6: I/O and Streams

Instructor: Mark Edmonds

<edmonds_mark@smc.edu>

## File I/O

- Thus far, we have either printed to the screen or gotten input directly from the user
- What if we could read data from files and save data to files?
- This would enable us to save information beyond the current program execution and use the data later
- Your program *reads* from a file when it takes input from a file
- Your program *writes* to a file when it sends information to a file
- This chapter examines *streams* to accomplish I/O

## Streams

- Streams will serve as our first introduction to objects
- A **stream** is a flow of characters
  - If the flow is into your program, the stream is called an **input stream**
  - If the flow is out of your program, the stream is called an **output stream**
- The data in the stream can come from a file or from a keyboard - the stream does not care
- `cin` and `cout` are both special stream *objects* included from the `iostream` header
- Suppose your program defines an input stream `in_stream` that comes from a file (this does not show how to create `in_stream`):

```cpp
int some_number;
instream >> some_number
```

- This `int` is filled with a number from this file.

```cpp
out_stream <<  some_number << endl;
```

- This will output the value stored in `some_number` to the file.
  - This effectively saves `some_number` to the file
- Input streams are created with:

```cpp
ifstream in_stream
```

- Output streams are created with:

```cpp
ofstream out_stream;
```

- Both types are provided by `fstream`, which can be included with `#include <fstream>`

- Important functions:
  - `open()` - opens a file
  - `close()` - close a file
- See documentation at
  - <http://www.cplusplus.com/reference/fstream/ifstream/>
  - <http://www.cplusplus.com/reference/fstream/ofstream/>

## Example: [`simple_io.cpp`](../examples/ch6_io/simple_io.cpp)

```{include=../examples/ch6_io/simple_io.cpp}
```