---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 12, the document object model
title: Document Object Model
---

## Chapter 12: Document Object Model

CS 80: Internet Programming

Instructor: Mark Edmonds

## Introduction

- The Document Object Model gives you access to every HTML element on the page
- So far, we\'ve only written new elements to the page using `document.writeln()`
  - But this is restrictive and unintuitive
- We learned all of this information on how to build HTML documents by writing actual HTML
  - We want the best of both worlds: dynamic changes to the page while having a default, interpret to use HTML structure

## DOM Nodes and Trees

- DOM Tree represents the document
  - The tree is built based on the nesting of HTML tags in the document
    - Nested nodes are children of the containing HTML element in the tree
      - E.g. if this the `<p>` tag is inside of a `<body>` tag, the `<body>` node is the parent of the child `<p>` node
  - You\'ve been looking at the DOM Tree in the \"Elements\" view of the developer tools

## DOM Nodes and Trees

- DOM nodes are elements in the tree (which directly correspond to HTML elements)
  - Every piece of an HTML5 page (elements, attributes, text) is modeled by a DOM node
- Let\'s take a look at what the DOM looks like and take a look in the debugger

## DOM Basics

- A critical, simple, and effective method
  - `document.getElementById("html_id")`
    - This returns an object representation of an HTML element, specifically, the HTML element with the specified \"html\_id\"
    - This object is a DOM node in the DOM tree
    - Now we have direct, Javascript access to HTML elements!
      - Means we can interact with existing HTML elements through Javascript

## DOM Basics

- Let\'s dig into the object that `getElementById` returns:
  - An \"Element\"
  - <https://developer.mozilla.org/en-US/docs/Web/API/Element>

## DOM Basics

Important Methods

- `currentNode.getAttribute(attr_name)` - gets an attribute from the node (specifically `attr_name`). Attributes are HTML attributes, such as `class` or `src`, etc.
- `currentNode.setAttribute(attr_name, value)` - sets an attribute from the node (specifically `attr_name` to `value`). Attributes are HTML attributes, such as `class` or `src`, etc.
- `currentNode.removeAttribute(attr_name)` - removes an attribute from the node (specifically `attr_name`). Attributes are HTML attributes, such as `class` or `src`, etc.
- `document.createElement("HTMLtag")` - creates an HTML tag of type `HTML_tag`. E.g. `var node = document.createElement("p");` creates a paragraph tag

## DOM Basics

Important Methods

- `currentNode.appendChild(child_node)` - appends the DOM node `child_node` to to the `node`. Note that `child_node` must be a constructed DOM node
- `currentNode.insertBefore(newNode, referenceNode)` - inserts the new node before the reference node as a child of the current node
- `currentNode.replaceChild(newChild, oldChild)` - replaces current node\'s the old child with the new child
- `currentNode.removeChild(child)` - removes a child node (note that this function returns the child node)

## DOM Basics

Important Attributes

- `innerHTML` - accesses this node\'s inner HTML. This is the text to markup. E.g. if `<p>` is the `currentNode`. `currentNode.innerHTML` accesses the text within the `<p>` tag
- `parentNode` - accesses this node\'s parent HTML node.
- `length` - tells how many children node this node has

## DOM Basics

- Changing/Setting the innerHTML of a node

  ```javascript
  // Case 1: create new node
  var h1_node = document.createElement("h1"); // create new h1_node
  h1_node.innerHTML = "Hello, World!"; // change the inner HTML using innerHTML
  document.body.appendChild(h1_node); // insert our new node to the document's body (document.body gives you the required &lt;body&gt; HTML tag)
  // Case 2: modify an existing node
  var h1_node = document.getElementById("h1_ele"); // assume there is an &lt;h1 id="h1_ele"&gt; tag in the document
  h1_node.innerHTML = "Hello, World!"; // change the inner HTML using innerHTML
  ```

## Example: [`editing_dom.html`](../examples/ch12_dom/editing_dom.html)

```{include=../examples/ch12_dom/editing_dom.html}
```

## Traversing DOM

- A complicated, intimidating, and informative example of how you can interact with a DOM tree
  - The javascript (`traversing_dom/dom.js`) is intimidating. I encourage you to dive into it. It will make more sense by the end of the lecture.

## Example: [`traversing_dom/dom.html`](../examples/ch12_dom/traversing_dom/dom.html)

```{include=../examples/ch12_dom/traversing_dom/dom.html}
```

## Event Listeners

- Event listeners trigger Javascript code when the event fires
- This enables the webpage to react to a users\'s actions
  - Similar to the `:hover` we saw trigger different CSS rules based on the mouse\'s position
- Conceptual example: the event could be clicking a button in the document, and the function could be updating a table based on the input

## Event Listeners

- `addEventListener()`
  - Enables you link a function to an action in the HTML document
  - The \"action\" is an event on the webpage
  - Events include things like:
    - `mouseenter` (mouse enters the corresponding HTML element)
    - `click` (a button has been pressed and released
    - `submit` (form submit button is pressed)
  - A list of events available is here: <https://developer.mozilla.org/en-US/docs/Web/Events>

## Event Listeners

- Syntax:

  ```javascript
  target.addEventListener(event_type, callback);
  ```

- `target` = HTML element to listen for `event_type`
  - When `target` (DOM node) has `event_type` (event) occur, `callback` (function) is called

## Example: [`loading_event_listeners.html`](../examples/ch12_dom/loading_event_listeners.html)

```{include=../examples/ch12_dom/loading_event_listeners.html}
```

## DOM Collections

- DOM contains a lot of information, most of which we won\'t usually care about
- Collections are groups of related objects on a page
- Each collection contains all of the elements of the corresponding type on the page.
- Each collection is stored under the `document` object
- Collections:
  - images
  - links
  - forms

## Images Collection

- Stores all images on a page
- Accessed through `document.images` (returns a list of images)
- Each element in the list is an Image object
  - <http://www.w3schools.com/jsref/dom_obj_image.asp>
- First image\'s link can be accessed through `document.images[0].src`
  - `document.images[0].alt` is the alt display
- `document.images.length` returns the number of images
- Others are accessed similarly

## Links Collection

- Stores all links on a page
- Accessed through `document.links` (returns a list of links)
- Each element in the list is a Link object
  - <http://www.w3schools.com/jsref/dom_obj_link.asp>
- First URL\'s link can be accessed through `document.links[0].href`
  - `document.links[0].innerHTML` is the displayed text
- `document.links.length` returns the number of images
- Others are accessed similarly

## Forms Collection

- Stores all forms on a page
- Accessed through `document.forms` (returns a list of links)
- Each element in the list is a Form object
  - [http://www.w3schools.com/jsref/dom\_obj\_form.asp](http://www.w3schools.com/jsref/dom_obj_link.asp)
- First form\'s inputs can be accessed through `document.forms[0].elements` (this is a list as well!)
  - Take a look at what is available for forms here
  - <http://www.w3schools.com/jsref/coll_form_elements.asp>
- `document.forms.length` returns the number of forms
- Others are accessed similarly

## Exercise

- Write a Javascript function named `getFormvalue()` to print the values of First and Last name on the following form to `console`
  - Note that the `onsubmit` attribute specifies a Javascript function to call upon submission (one way to do form validation!)
  - Use form object documentation to help <http://www.w3schools.com/jsref/coll_form_elements.asp>

## Exercise: Corresponding HTML

```{include=../examples/ch12_dom/get_form_value.html}
```

## Example: [`first_last_name.html`](../examples/ch12_dom/first_last_name.html)

```{include=../examples/ch12_dom/first_last_name.html}
```

## Exercise

- How could we have done this using `addEventListener()`?

## Example: [`first_last_name_listener.html`](../examples/ch12_dom/first_last_name_listener.html)

```{include=../examples/ch12_dom/first_last_name_listener.html}
```
