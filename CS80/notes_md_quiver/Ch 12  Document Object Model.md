## Introduction
* The Document Object Model gives you access to every HTML element on the page
* So far, we've only written new elements to the page using `document.writeln()`
    * But this is restrictive and unintuitive
* We learned all of this information on how to build HTML documents by writing actual HTML
    * We want the best of both worlds: dynamic changes to the page while having a default, interpret to use HTML structure

## DOM Nodes and Trees
* DOM Tree represents the document 
    * The tree is built based on the nesting of HTML tags in the document
        * Nested nodes are children of the containing HTML element in the tree 
            * E.g. if this the `<p>` tag is inside of a `<body>` tag, the `<body>` node is the parent of the child `<p>` node  
    * You've been looking at the DOM Tree in the "Elements" view of the developer tools
* DOM nodes are elements in the tree (which directly correspond to HTML elements)
    * Every piece of an HTML5 page (elements, attributes, text) is modeled by a DOM node 

* Let's take a look at what the DOM looks like
    * Look at `tables.html`, load it into Firefox and press Option + Command + C (should be Control + Alt + C in Windows, but it's under the normal debugger pane) 

* A critical, simple, and effective method
    * `document.getElementById("html_id")`
        * This returns an object representation of an HTML element, specifically, the HTML element with the specified "html_id"
        * This object is a DOM node in the DOM tree
        * Now we have direct, Javascript access to HTML elements!
            * Means we can interact with existing HTML elements through Javascript 

* Let's dig into the object that `getElementById` returns
    * An "Element"
    * [https://developer.mozilla.org/en-US/docs/Web/API/Element](https://developer.mozilla.org/en-US/docs/Web/API/Element)
* Important methods (for now):
    * `currentNode.getAttribute(attr_name)` - gets an attribute from the node (specifically `attr_name`). Attributes are HTML attributes, such as `class` or `src`, etc.
    * `currentNode.setAttribute(attr_name, value)` - sets an attribute from the node (specifically `attr_name` to `value`). Attributes are HTML attributes, such as `class` or `src`, etc.
    * `currentNode.removeAttribute(attr_name)` - removes an attribute from the node (specifically `attr_name`). Attributes are HTML attributes, such as `class` or `src`, etc.
    * `document.createElement("HTMLtag")` - creates an HTML tag of type `HTML_tag`. E.g. `var node = document.createElement("p");` creates a paragraph tag
    * `currentNode.appendChild(child_node)` - appends the DOM node `child_node` to to the `node`. Note that `child_node` must be a constructed DOM node
    * `currentNode.insertBefore(newNode, referenceNode)` - inserts the new node before the reference node as a child of the current node
    * `currentNode.replaceChild(newChild, oldChild)` - replaces current node's the old child with the new child
    * `currentNode.removeChild(child)` - removes a child node (note that this function returns the child node) 
* Important Attributes:
    * `innerHTML` - accesses this node's inner HTML. This is the text to markup. E.g. if `<p>` is the `currentNode`. `currentNode.innerHTML` accesses the text within the `<p>` tag
    * `parentNode` - accesses this node's parent HTML node.
    * `length` - tells how many children node this node has

* Changing/Setting the innerHTML of a node

```js
// Case 1: create new node
var h1_node = document.createElement("h1");  // create new h1_node
h1_node.innerHTML = "Hello, World!";         // change the inner HTML using innerHTML
document.body.appendChild(h1_node);          // insert our new node to the document's body (document.body gives you the required <body> HTML tag)

// Case 2: modify an existing node
var h1_node = document.getElementById("h1_ele");  // assume there is an <h1 id="h1_ele"> tag in the document
h1_node.innerHTML = "Hello, World!";              // change the inner HTML using innerHTML
```

* A complicated, intimidating, and informative example of how you can interact with a DOM tree
    * [traversing_dom/dom.html](https://www.dropbox.com/sh/ytz4zrzj5dgz0zw/AACEbGNI2vtLMzDgf8n6LPKba?dl=0) example. 
        * The javascript (`traversing_dom/dom.js`) is intimidating. I encourage you to dive into it. It will make more sense by the end of the lecture.

A more practical exercise:
* [editing_dom.html](https://dl.dropbox.com/s/7728wy1y0zr044s/editing_dom.html?dl=0)

## Event Listeners
* `addEventListener()`
    * Enables you link a function to an action in the HTML document
        * The "action" is an event on the webpage
        * Events include things like:
            * mouseenter (mouse enters the corresponding HTML element)
            * click (a button has been pressed and released
            * submit (form submit button is pressed)
        * A list of events available is here: [https://developer.mozilla.org/en-US/docs/Web/Events](https://developer.mozilla.org/en-US/docs/Web/Events)
    * Conceptual example: the action could be clicking a button in the document, and the function could be updating a table based on the input
    * Syntax:

```js
target.addEventListener(event_type, listener); // target = HTML element to listen for event_type on (when target has event_type happen, listener is called)
```

* An important note: Javascript cannot access the DOM before the HTML is loaded - the the Javascript itself is loaded before HTML!
    * Solution:
        * Use `window.addEventListener("load", start, false);` when  you need to add event listeners to a an HTML element
        * the `start` function is only called after the HTML elements are loaded, meaning `getElementById()` won't fail (since the HTML element has been loaded)!
* Example:

```html
<!DOCTYPE html>
<html>

<head>
  <meta charset=utf-8 />
  <title>Proper Loading</title>
  <script>
    
    function start(){
      document.getElementById("p1").addEventListener("mouseenter", addHighlight, false);
      document.getElementById("p1").addEventListener("mouseleave", removeHighlight, false);
    }

    window.addEventListener("load", start, false);

    function addHighlight() {
      var p1 = document.getElementById("p1");
      p1.setAttribute("style", "background-color: #3F6");
    }
    
    function removeHighlight() {
      var p1 = document.getElementById("p1");
      p1.removeAttribute("style");
    }
  </script>
</head>

<body>
  <p id="p1">
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque faucibus augue in risus tempus viverra. Etiam gravida augue a venenatis sollicitudin. Praesent varius ex varius, accumsan libero vel, bibendum eros. Aenean tristique mattis sem id scelerisque. In cursus ultrices massa nec tristique. Phasellus efficitur ac neque eu suscipit. Donec volutpat pretium justo, eget fringilla sapien. Integer vitae metus eget lorem auctor vestibulum non ut risus. Aenean hendrerit iaculis sapien. Nunc vestibulum purus quam, nec consequat sem cursus a. Aenean interdum euismod dui id dapibus. Curabitur vel placerat purus. Etiam dolor turpis, dictum in augue sit amet, suscipit suscipit leo. Aliquam auctor fringilla ligula, vitae sodales ligula facilisis quis. Donec consequat molestie tempus. Donec faucibus elit ullamcorper ante accumsan congue.
  </p>
</body>

</html>
```

* see [loading_event_listeners.html](https://dl.dropbox.com/s/foy0rj2ounxo81y/loading_event_listeners.html?dl=0)

## DOM Collections
* DOM contains a lot of information, most of which we won't usually care about 
* Collections are groups of related objects on a page
* Each collection contains all of the elements of the corresponding type on the page.
* Each collection is stored under the `document` object
* Collections:
    * images
    * links
    * forms

### Images Collection
* Stores all images on a page
* Accessed through `document.images` (returns a list of images)
* Each element in the list is an Image object
    * [http://www.w3schools.com/jsref/dom_obj_image.asp](http://www.w3schools.com/jsref/dom_obj_image.asp) 
* First image's link can be accessed through `document.images[0].src`
    * `document.images[0].alt` is the alt display
* `document.images.length` returns the number of images
* Others are accessed similarly

### Links Collection
* Stores all links on a page
* Accessed through `document.links` (returns a list of links)
* Each element in the list is a Link object
    * [http://www.w3schools.com/jsref/dom_obj_link.asp](http://www.w3schools.com/jsref/dom_obj_link.asp) 
* First URL's link can be accessed through `document.links[0].href`
    * `document.links[0].innerHTML` is the displayed text
* `document.links.length` returns the number of images
* Others are accessed similarly

### Forms Collection
* Stores all forms on a page
* Accessed through `document.forms` (returns a list of links)
* Each element in the list is a Form object
    * [http://www.w3schools.com/jsref/dom_obj_form.asp](http://www.w3schools.com/jsref/dom_obj_link.asp) 
* First form's inputs can be accessed through `document.forms[0].elements` (this is a list as well!)
    * Take a look at what is available for forms here
    * [http://www.w3schools.com/jsref/coll_form_elements.asp](http://www.w3schools.com/jsref/coll_form_elements.asp)
* `document.forms.length` returns the number of forms
* Others are accessed similarly


Exercise:
* Write a Javascript function named `getFormvalue()` to print the values of First and Last name on the following form to `console`. Note that the `onsubmit` attribute specifies a Javascript function to call upon submission (one way to do form validation!) Use form object documentation to help [http://www.w3schools.com/jsref/coll_form_elements.asp](http://www.w3schools.com/jsref/coll_form_elements.asp)

```html
<!DOCTYPE html>  
<html>
  <head>  
    <meta charset=utf-8 />  
    <title>Return first and last name from a form - w3resource</title>  
  </head>
  <body>  
    <form method="get" id="form1" onsubmit="getFormvalue()">
      First name: 
      <input type="text" name="fname" value="David"><br>
      Last name: 
      <input type="text" name="lname" value="Beckham"><br>
      <input type="submit" value="Submit">
    </form>
  </body>  
</html> 
```

* Solution:

-----------------------

```js
function getFormvalue() {
  var form = document.getElementById("form1");
  for (var i = 0; i < form.length; i++) {
    if (form.elements[i].value != 'Submit') {
      console.log(form.elements[i].value);
    }
  }
}
```

* See [first_last_name.html](https://dl.dropbox.com/s/z1d8fwuyamarzu1/first_last_name.html?dl=0)
* How could we have done this using `addEventListener()`?

-------------------------
*  Solution:

```js
function start(){
  // listen for the submit event on the form
  document.getElementById("form1").addEventListener("submit", getFormvalue, false);
}

window.addEventListener("load", start, false);

function getFormvalue() {
  var form = document.getElementById("form1");
  for (var i = 0; i < form.length; i++) {
    if (form.elements[i].value != 'Submit') {
      console.log(form.elements[i].value);
    }
  }
}
```

* See [first_last_name_listener.html](https://dl.dropbox.com/s/f16il0glxrd17ya/first_last_name_listener.html?dl=0)
* Go over [dom.js](https://www.dropbox.com/s/xkm2eua8h9rcapn/dom.js?dl=0)



