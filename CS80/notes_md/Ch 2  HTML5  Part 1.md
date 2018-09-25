# Chapter 2: HTML Part 1

HTML:

* What does it stand for?
  * Hypertext markup language
* What is a markup language?
  * Not a traditional programming language
  * Specifies the structure and content of documents

Editing HTML

* All you need is a text editor and a web browser
* Text editors
  * Notepad++, Sublime Text, TextEdit, vim, etc
  * Anything will do, but don't use Microsoft Word (technically you can do this but it will make for a painful semester and you will almost certainly get points off)
* Web browsers
  * Chrome, firefox, IE, etc
  * For this course, firefox seems to be the most agreeable
    * There is one with Ajax that only works with firefox

HTML Concepts

* Documents are composed of HTML5 *tags*
* These tags outline this structure and content of a webpage
* Tag format:
  * \<*tag\> *begins the tag
  * \</*tag\>* closes the tag
  * Most tags have a beginning and an end
    * Exceptions: \<meta\> (specifies document metadata, \<img\> tag (adds an image to the page), there are others we will come across
    * We can tags without an ending *void elements* because they do not markup text (text is not placed between a start and an end tag).
* Tags can be *nested* e.g. there is a tag inside of another tag before the outer tag's closing tag
* Attributes: content inside of a tag that specifies information about this particular use of the tag
  * we'll see an example in a second
* Elements: the portions of a HTML document
  * The beginning to closing of a tag form an element
  * e.g. \<tag\> content \</tag\> is an element

Go over hello\_world.html example

HTML5 Validation

* You can validate HTML online!
* Go to [https://validator.w3.org/\#validate\_by\_upload](https://validator.w3.org/#validate_by_upload) to validate a file
* Go to [https://validator.w3.org/\#validate\_by\_input](https://validator.w3.org/#validate_by_input) to validate input
* Upload hello\_world.html example to validator
  * move the \<!DOCTYPE\> to show the must be on first line error

Headings

* heading elements designate a level of importance for a topic on a page
* headings range from \<h1\> to \<h6\>
  * The lower the number, the greater importance
  * so \<h1\> is the most important

Hyperlinks

* Provides a link to another HTML document
* Can be on this host or on a different host
  * What does this mean?
  * You can link internally to your own content or to a new host's webpage.
  * In either case, a new HTTP request is triggered
* Links are facilitated using the \<a\> tag with a corresponding attribute of "href"
  * 'a' stands for 'anchor'
  * 'href' stands for 'hypertext reference'
* We can href other protocols (e.g. https://, ftp://, mailto:, file:, etc) or even javascript!
  * If it's javascript the script will execute when clicked
  * This will make more sense once we get to javascript, hold on!

Images

* added to HTML using the \<img\> tag
* \<img\> tag is one of the tags without an ending \</img\>
* the src attribute specifies where the image is located
  * The location can be a relative path (e.g. stored on the same computer as the html document)
  * The location can be a remote path (e.g. an image stored on a different host)
    * Remember since html is rendered client-side, most of the time you need a remote path (since the image will not exist on the client's computer).
* Must use an alt attribute, it is allows for two important usages:
  * for those with poor or no eyesight to still understand the content on the page. A text-to-speech program can read the alt description to a visually impaired person.
  * if the image fails to load (maybe it's an external image), the alt can still describe what the image is
  * Usually the alt is a sentence long, but can be longer. It should be as brief as possible while still being descriptive
* Common attributes used: specifying height and width'
  * Height and width are both measured in pixels
  * If there are no height and width are specified, image will be rendered at it's own size (the original image size)
* Images can be nested inside of a link tag (\<a\>) to create an image that is also a hyperlink

Special Characters and horizontal rules

* HTML itself uses certain characters to represent the structure of the document.
  * These symbols have special meaning within the document itself
  * What are some examples?
    * How are tags wrapped?
      * Around a \< and a \>
* Clearly, we still want to be able to include these tags in an HTML document.
* Solution: We have to use a special convention to include these restricted characters
* These special conventions are called *character entity references*
  * The basic format: &ref;
    * Where ref is a reference to the character you wish to insert
  * E.g. &lt; inserts the less-than symbol (\<)
  * You can find a list of these symbols online
    * Do a quick google search go all of the symbols available
    * [http://www.w3schools.com/html/html\_entities.asp](http://www.w3schools.com/html/html_entities.asp)
    * <https://www.w3.org/TR/REC-html40/sgml/entities.html>

Lists

* like a normal list but in HTML!
* Two types of lists:
  * Unordered list and ordered list
* Unordered list (bulleted list)
  * 'ul' tag starts an unordered list (ul stands for unordered list)
  * each list item is a nested 'li' tag (li stands for list element)
* Ordered list (numbered list)
  * 'ol' tag starts an ordered list
  * each list item is a nested 'li' tag
* We can also make lists inside of lists (nested lists)
  * Just like your word processor
  * Bullets of an unordered list will change based on the nesting level

\<br\> tag - a line break

Tables

* like a textbook table or excel spreadsheet (except without math functions)
* started with the 'table' tag
* the nested 'caption' tag gives the table a title and summarizes the table's content
* \<thead\> and \<tfoot\> specify the header and footer of the table, respectively
  * Maybe you want different styling for the header and footer using CSS
  * Again, we'll cover that later
* \<tbody\> specifies the main body portion of the table
* \<thead\> and \<tfoot\> have the same internal structure
  * Each is comprised of at least one \<tr\> element, which is a table row
  * note that no table requires all three, but you should use them appropriately
    * If your table has a header, put the header, etc
    * Makes table maintenance easier later
  * Each \<tr\> tag is comprised of \<th\> tags, which is a *header cell*. It is different from the normal cell.
    * It's different to allow easier styling using CSS
    * the table fills left to right along the columns
  * repeat this \<tr\> and \<th\> pattern for each row, and each column you want to specify
  * \<tfoot\> can be below or above
* \<tbody\> follows the same convention, but uses a \<td\> element instead of \<th\>
  * 'td' stands for 'table data'
* By default, each table column is only as wide as its largest cell.
* rowspan and colspan
  * these attributes allows a cell to span multiple rows or columns
    * This is like merging rows/columns in a document
  * rowspan allows a single table cell to span the width of more than one cell or row
  * colspan allows a single table cell to span the width of more than one cell or column
  * These attributes can be applied in \<th\> and \<td\> elements

Forms

* mechanism for the user to send data to the server from the client
* The user types in the data, then hits 'submit' the submit triggers a HTTP request to the server to accept the form
  * The receiving end will be covered in CH 17
* Forms use the \<form\> tag
* Important \<form\> attributes:
  * These setup the form and specify how and where to send data to the server
  * 'method'
    * 'get'
      * appends form data to url in name/value pairs
      * length of URL is limited (~3000 characters limit)
      * never use this to send sensitive data
      * best suited for things like a query or other non-secure data (you can bookmark the url to effectively save the form submission)
    * 'post'
      * Appends form data to HTTP request
      * Has no size limitations
      * Cannot be bookmarked (since it does not modify the URL)
  * 'action'
    * specifies where to send the form data
    * must be a valid URL
    * The server \*should\* know how to respond to the form submission
* Once we have the form setup, we can add inputs
* Inputs are added using the \<input\> tag
  * important attributes
    * 'type'
      * controls the type of the input, has a bunch of options
      * options include: text, button, color, password, radio, range, reset, submit, etc. look them up online for more
      * 'hidden' is a special type
        * It submits data to the server that is predetermined in the HTML page
        * The user cannot control this input
        * Might be used for sending information to another server to identify where the form is coming from
      * 'text' has a couple of special attributes: 'size' - specifies the size of the text box and 'maxlength' which specifies the maximum length of the input
    * 'name'
      * Gives the input a name that can be referenced once the server receives the submission
      * This is basically the glue of the form between the inputs the client fills out and how the server processes them
    * 'value'
      * Gives the input an initial value
* Please lookup the following form elements in your book or online:
  * textarea - multiline text input, has rows and cols attributes
  * password - provides a password-protected field. this is only visually enforced (displays a \* instead of the text), the password still should be encrypted be sent over HTTP
  * color - allows color input
  * number - allows user to input a number, similar to a text but for numbers
  * range - allows user to pick between a range of values
  * checkbox - allows user to tick multiple options
  * radio - allows user to pick one option from a list
  * they all follow a similar pattern, but familiarize yourself
* \<select\> tag presents a dropdown menu with a preselected list of options

Internal Linking

* mechanism to jump between locations in a single document, without reloading the HTML page
* basic idea: we uniquely mark elements in the document using the 'id' attribute, then we refer to the corresponding id in an anchor (remember this is a link) tag
* The link tag can reference a specific tag in a different HTML document, even on a different host
*