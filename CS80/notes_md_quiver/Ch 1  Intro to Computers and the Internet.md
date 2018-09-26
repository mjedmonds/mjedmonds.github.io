# Chapter 1: Introduction to Computers and the Internet

Course expectations and recipes for success:

1. Turning in assignments and tests on time
2. Doing the project fully (this means using at MINIMUM HTML5 and CSS, see Project online for more detailed info)
3. Attend class

Mini-project info:

* You will be required to submit a project worth 20% of your grade the last week of class
* You may work in groups
* You are only required to use HTML5 and CSS, but it is strongly encouraged to use other technologies you learn during the semester
* You may work in groups of up to 4, but you do not have to. The expected quality/effort will be based on how many group members you have
* You are expected to work a minimum of 20 hours on this project (not that anyone is checking the time, but it will show in the effort)

General motivation for this course: 

* computer science in general is a massive field that is probably not going become less integral to our lives
* learning about computer science, including internet programming, will make you more employable, regardless of your field, and will help you in your everyday life (figuring out what is wrong with your computer is much easier when you know how they work)
  * Applications of computer science: Cloud computing, GPS, robotics, email, the web, video games, cars, cell phones, personal computers

WARNING: this lecture will be largely based on the book, but that won't be true for most lectures

**Chapter 1: Computers and the Internet**

Client-side programming

* web applications that run on the client
  * *client* refers to the user's device (e.g. a computer or cell phone)
* Example: you make your own webpage using HTML5
* Technologies: HTML5 (hyper-text markup language), CSS (cascading style sheets), Javascript

Server-side programming 

* applications that respond to client-side requests
  * these applications respond to information coming from the client
* Example: user submits a registration form that must be saved in the server's database
* Technologies: Apache (web server), MySQL (database), PHP

**1.3 - Basic Concepts**

HTML5

* Chapters 2 and 3
* HyperText Markup Language
* Specifies the content and the structure of a webpage

CSS

* Chapter 4
* Cascading Style Sheet
* controls the presentation of the webpage
* separates the presentation from the content and structure of the webpage
* enables changing the view of the website

Javascript

* Chapters 6 and 7
* javascript helps make web pages dynamic; e.g. they change with user interaction
* these interactions are referred to as *events*
  * Examples of events: losing focus on a form, hitting a button, changing the mouse location

jQuery

* Simplifies javascript by providing tons of libraries
* Provides portable behavior
  * Why does portable matter?
    * Not ever web browser behaves the same way
    * You've probably seen a web browser complain about compatibility issues before

**1.4 - Do some of the demos**

[https://developer.mozilla.org/en-US/docs/Web/Demos\_of\_open\_web\_technologies](https://developer.mozilla.org/en-US/docs/Web/Demos_of_open_web_technologies)

**1.5 - A brief history of the internet**

ARPANET

* The first version of the internet
* ARPA stands for Advanced Research Projects Agency
* First message was sent from UCLA to Stanford

TCP/IP

* TCP = Transmission Control Protocol
  * Ensures transmitted data integrity and that the destination was correct
* IP = Internet Protocol
  * Different types and configurations of networks appeared over time
    * Each one was a sub-network
  * IP creates a network of networks
* Each computer on sub-networks and the Internet is assigned its own IP address
  * We used to use IPv4, which is 32-bit (meaning approximately four billion address)
  * We ran out of IPv4 address; we now use IPv6, which is 128 bit (containing approximately 340 follow by 36 zeros worth of address
    * We should be good for a while!

World Wide Web, HTML, HTTP

* World Wide Web is a section of the internet
* Specifically, this 'section' of the internet servers HTML (hypertext markup language) documents
* The hypertext transfer protocol (HTTP) is the communication protocol used to serve an HTML document
* A URL (uniform resource locator) specifies the location of the html document on the web.
  * They start with http://

**1.6 - Web Basics**

Hyperlinks

* links to another document
* Documents are typically HTML pages
  * Can also link to an email address via mailto:
  * Can also link to a file, even a local file (the local file would need to exist)

URIs and URLs 

* URI = uniform resource identifiers
  * Can be files ([file://](file:///)), file transfers (ftp://),
* URL = URIs that start with http:// or https://
  * Remember, http: = hypertext transfer protocol
* Anatomy of a URL
  * Ex: <http://www.deitel.com/books/downloads.html>
  * [www.deitel.com](http://www.deitel.com/) is the **hostname **(which is hosted on a **host** computer)
  * This hostname is translated into an IP address (remember IP stands for Internet Protocol)
    * This IP address uniquely identifies the host on the Internet
    * This translation occurs by looking up the hostname on a DNS server (DNS = domain name system)
      * DNS is pretty complicated, but think of it like a network of computers whose sole purpose is to facilitate this lookup
      * The complicated part: these servers need to sync updates without messing the entire system up
      * Hackers do DNS attacks to trick people into giving up personal information to the wrong website (even though it looks like the right one)
  * /books/downloads.html is the resource's location (/books) and name (downloads.html) on the webserver

The request/receive process

* Web browser sends
  * GET /books/downloads.html HTTP/1.1
* GET is an HTTP command asked for a particular resource, in this case requesting
  * /books/downloads/html
* The HTTP/1.1 specifies the protocol and version
  * Any server that can understand HTTP version 1.1 can successfully interpret this request

* The server responds with another message, indicating what happened with the request
  * HTTP/1.1 200 OK
    * indicates success
  * HTTP/1.1 404 Not found
    * indicates the resource could not be found
  * 100s = informational (continue, switching protocols)
  * 200s = success (ok, accepted, no content)
  * 300s = redirects, more action needed (multiple choices, use proxy, permanent redirect)
  * 400s = client error (bad request, unauthorized, forbidden)
  * 500s = server error (internal server error, bad gateway, loop detected)

HTTP Header

* Next part of the response
* provides additional information about the response, such as the type of information being sent (e.g. jpeg, html, etc.)
* Ends with a blank line, to indicate that the content is about to start
* Then the content of the message is sent

Two most common HTTP requests: get (request information) and post (send information) 

**1.8 Client-side scripting vs. server-side scripting**

Client-side

* Script runs on the client
* Example: Javascript
* Problems: script execution is limited by client's browser's capabilities, security concerns
* Benefits: doesn't use bandwidth to process information (e.g. form validation can happen entirely on the client

Server-side

* scripts that run on the server
* example: PHP, database access
* Problems: time (client may wait for server), extra bandwidth potentially
* Benefits: not limited by client's computer; means web designer can control what's on the page

Ajax

* covered in detail in ch 16
* allows webpages to behave like desktop applications
* facilitated by sending requests to the server without loading an entirely new HTML document

**1.13 Types of Programming Languages**

* Guessing most people are aware that computers only understand 0's and 1's
* When you write code, this code is typically translated down to a language that is comprised of 0's and 1's
* Languages that are understood directly by computers (e.g. they are made of 0's and 1's) are known as *machine langauges*
  * However, this is very cumbersome
  * People started writing English abbreviations of these 0's and 1's
    * These formed a higher abstraction of programming, known as assembly languages
* All of this was still quite cumbersome, so *high-level languages* were created to provide more abstraction
  * High level languages, such as C++, python, java, javascript, etc, allow programmers to write statements that are almost english
* Two types of high-level languages:
  * Interpreted - program statements are translated to machine code as the program executes (as each line of code is running)
    * E.g. python, javascript
    * Good for the web, code can start running as soon as it downloads to th client's computer
  * Compiled - all program statements are converted into machine code, then the program can run
    * E.g. C++, Java
    * Generally significantly faster than interpreted languages, the translation doesn't happen as the program is running

**1.14 Object Oriented Programming**

* This is a topic for an entire course
* How many people have heard of this before?
* How many people have used OOP before?
* Basic concept: group data and operations together logically, allowing for hierarchies of relationships as well
* Example: a car
  * Operations (methods): steer, accelerate, decelerate, fill up with gas, etc
  * Data: speed, heading, gas tank status, odometer, etc.
  * Important notes:
    * You don't have to know how the car precisely works to use one. You simply know that the pedal accelerates the car, brake decelerates, etc
      * This is known as *information hiding*
      * Another engineer has designed how the care operates, you just use the public (available) operations
        * But there are many more operations happening inside the car than you are aware
    * We refer to the design of the car as the *class* (think of this like a blueprint)
    * Once you have the design for a car, you can reuse it
      * Each "usage" is an instantiation of a car
    * Similarly, once you have a design of a car, you can extend it to add new features
      * E.g. add upgrades, wings, etc
      * This is known as inheritance