// Fig. 12.5: dom.js
// Script to demonstrate basic DOM functionality.
var currentNode; // stores the currently highlighted node
var idcount = 0; // used to assign a unique id to new elements

// register event handlers and initialize currentNode
function start() {
  document.getElementById("byIdButton").addEventListener(
    "click", byId, false);
  document.getElementById("insertButton").addEventListener(
    "click", insert, false);
  document.getElementById("appendButton").addEventListener(
    "click", appendNode, false);
  document.getElementById("replaceButton").addEventListener(
    "click", replaceCurrent, false);
  document.getElementById("removeButton").addEventListener(
    "click", remove, false);
  document.getElementById("parentButton").addEventListener(
    "click", parent, false); 
  // initialize currentNode
  currentNode = document.getElementById( "bigheading" );
} // end function start

// call start after the window loads
window.addEventListener("load", start, false);

// get and highlight an element by its id attribute
function byId() {
  // get the text from the input text box with id "gbi"
  var id = document.getElementById("gbi").value;
  // get the target by getting the element that has the id from the value above (the input text box)
  var target = document.getElementById(id);
  // make sure target is a valid DOM node before switching the highlight to it
  if (target)
    switchTo(target);
} // end function byId

// insert a paragraph element before the current element
// using the insertBefore method
function insert() {
  var newNode = createNewNode(document.getElementById("ins").value);
  currentNode.parentNode.insertBefore(newNode, currentNode);
  switchTo(newNode);
} // end function insert

// append a paragraph node as the child of the current node
function appendNode() {
  var newNode = createNewNode(document.getElementById("append").value);
  currentNode.appendChild(newNode);
  switchTo(newNode);
} // end function appendNode

// replace the currently selected node with a paragraph node
function replaceCurrent() {
  var newNode = createNewNode(document.getElementById("replace").value);
  currentNode.parentNode.replaceChild(newNode, currentNode);
  switchTo(newNode);
} // end function replaceCurrent

// remove the current node
function remove() {
  if (currentNode.parentNode == document.body)
    alert("Can't remove a top-level element.");
  else {
    var oldNode = currentNode;
    switchTo(oldNode.parentNode);
    currentNode.removeChild(oldNode);
  }
} // end function remove

// get and highlight the parent of the current node
function parent() {
  var target = currentNode.parentNode;
  if (target != document.body)
    switchTo(target);
  else
    alert("No parent.");
} // end function parent

// helper function that returns a new paragraph node containing
// a unique id and the given text
function createNewNode(text) {
  var newNode = document.createElement("p");
  // this just makes sure new nodes have a unique ID
  nodeId = "new" + idcount;
  ++idcount;
  newNode.setAttribute("id", nodeId); // set newNode's id
  // this adds the new node's ID to the text printed on the screen in [new(idcount)]
  text = "[" + nodeId + "] " + text;
  newNode.appendChild(document.createTextNode(text));
  return newNode;
} // end function createNewNode

// helper function that switches to a new currentNode
function switchTo(newNode) {
  currentNode.setAttribute("class", ""); // remove old highlighting
  // change current node to the new node
  currentNode = newNode;
  currentNode.setAttribute("class", "highlighted"); // highlight
  // update the text box's text to be the currentNode's ID
  document.getElementById("gbi").value = currentNode.getAttribute("id");
} // end function switchTo
