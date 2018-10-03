---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 16, Ajax
title: Ajax
---

## Chapter 16: Ajax

CS 80: Internet Programming

Instructor: Mark Edmonds

## What is Ajax?

- **A**synchronous **J**avascript **A**nd **X**ML
  - Misleading name! Originally developed for XML, but you can transfer plain text or JSON with it as well.

## What is Ajax?

- The idea: we load data as the user is viewing and interacting with the page; Javascript communicates with the server in the background to update the page.
- The effect: web applications that behave much more similarly to desktop applications
- The benefit: web applications don\'t have to reload a page to get new data. This can be incredibly simple data or complex data to enable drastic changes to the page

## What is Ajax?

- A side note about practicality:
  - We will learn about Ajax, but running Ajax requires a webserver to respond to requests. We will eventually cover webservers which will enable us to run our own basic Ajax examples

## Live Examples

- <http://test.deitel.com/iw3htp5/ch16/fig16_05/SwitchContent.html>
- <http://test.deitel.com/iw3htp5/ch16/fig16_08/PullImagesOntoPage.html>
- <http://test.deitel.com/iw3htp5/ch16/fig16_09-10/AddressBook.html>
- <http://kengeddes.com/cs80/examples/ajax.html>
  - <http://kengeddes.com/cs80/examples/ajax.js>
- <http://kengeddes.com/cs80/examples/ajax-b.html>
  - <http://kengeddes.com/cs80/examples/ajax-b.js>
- <http://javascript.cs.lmu.edu/playground/ajax/>

## Ajax Basics

- \"Raw\" Ajax uses Javascript directly to send asynchronous requests to the server, and updates the webpage using DOM
- There are a lot of cross-browser, cross-operating system considerations you have to handle when using raw Ajax
  - Instead, jQuery, [ASP.NET](http://ASP.NET) Ajax, etc can provide easy-to-use cross-platform support

## Ajax basics

- `XMLHttpRequest` - object that manages the interaction between the server and the webpage (without reloading)
  - Abbreviated `XHR`

## Traditional Webpage

![Traditional webpage](images/ch16_traditional_page.png)

## Ajax Webpage

![Ajax webpage](images/ch16_ajax_page.png)

## Ajax Steps

1. Client creates XHR object
2. XHR sends a request to the server and waits for a response
- These requests are made **asynchronously**, which means the user can keep interacting with the web page while the request finishes
3. Many things can happen here, client could interact more with the webpage, create new XHR requests, etc
4. Server replies to the request in step 2
5. Client executes a callback function, which processes the data recieved in step 4 (could modify the DOM, etc). Commonly a partial page update

## Ajax Basics

- This process is asynchronous, so tracking the exact execution can be difficult. Lots of things could happen during step 3 above

## Conceptual Example - Validating a form

- We can accomplish a lot of this using the new HTML5 forms, but provides more generic form support
- We can validate any type of form data (e.g. zip code, etc), asynchronously, as the user fills in the form.
- Enables a more powerful form model, you see this all the time online!

## Example - SwitchContent

- The basic concept: when the user puts their mouse over a textbook cover, we load that textbook\'s corresponding information

## Example: [`SwitchContent.html`](../examples/ch16_ajax/SwitchContent.html)

```{include=../examples/ch16_ajax/SwitchContent.html}
```

## Example - SwitchContent

- What\'s doing all the Ajax heavy lifting?
  - `getContent` and `stateChange`

## Pelimaries: Exceptions

- Exceptions indicate an error happened during data processes, but allow the program to continue running **if** the error is \"handled\"
- We refer to \"handling\" an error as **catching** an exception
- We refer to indicating an error occured as **throwing** an exception

## Pelimaries: Exceptions

- When we want to catch an exception, we acknowledge an error by happen by wrapping the relevant portion of code in a `try...catch` block
  - We put code that might cause the exception in the `try` portion
  - We put error-recovery code in the `catch` block
  - The try block will always execute (that\'s the code we are trying to run)
  - The catch block will only run if an exception is thrown

## Pelimaries: Exceptions

- Syntax

  ```javascript
  try {
    // code that might throw an exception
  } catch (exception) {
    // error recovery code 
  }
  ```

## `getContent`

1. Creates a raw Ajax object
2. Registers the function `stateChange` as the callback functino for the `readystatechange` event
    - The `readystatechange` event is triggered when the value of of the XHR\'s `readyState` property is changed
    - `readyState` can be 5 values: <https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/readyState>
    - A related property, `status` contains the HTTP status code of the HTTP request (200 = success)

## `getContent`

3. Opens the url and specifies the HTTP request with the GET method, and `true` says to do this operation aynschronously
    - Basically creates the HTTP request
4. Send the HTTP request

## `stateChange`

- The conditional statement makes sure that the aync request is completed.
  - Question: when will the `stateChange` function get called? How many times will it get called?
- Body of the state change processes the data from the request.

## Running SwitchContent

- If you want to run this example, download the files from the ch16 examples
- But this isn\'t enough, we need an actual webserver to respond to the Ajax request
- We can start a simple webserver (using any python console) with `python -m StimpleHTTPServer` from the folder with our examples downloaded
- Then navigate to `http://localhost:8000/SwitchContent.html` in your web browser

## Ajax Events and Objects

![Ajax events and objects](images/ch16_ajax_props.png){width="70%"}

## Ajax Methods

![Ajax methods](images/ch16_ajax_methods.png)

## Ajax, XML, and DOM

- When XHR receives XML data, it is stored as an XML DOM obejct (tree)
- This is best explained with the following example

## Example: [`PullImagesOntoPage.html`](../examples/ch16_ajax/PullImagesOntoPage.html)

```{include=../examples/ch16_ajax/PullImagesOntoPage.html}
```