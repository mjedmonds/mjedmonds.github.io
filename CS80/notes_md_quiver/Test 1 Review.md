**Test 1 Review**

****

NOTE: while most of these are high level questions, make sure you can actually produce corresponding HTML. You will be asked to write snippets. Expect the exam to be about half short questions and half snippets.

**Ch 1 - Computers and the Internet**

* What's the difference between client-side programming and server-side programming?
  * client side runs on the client's device (e.g. a computer or cell phone)
    * example technologies: HTML5, CSS, javascript
  * server-side runs on the server
    * applications that respond to client requests
    * example technologies: Apache, MySQL, PHP
* What is a hyperlink?
  * link to another document
* What is a URI? what is a URL?
  * URI = uniform resource identifier
    * examples: http://, [file://](file:///), ftp://
  * URL = uniform resource locator
    * URIs that start with http:// or https://
* What are the steps of a HTTP request?
  * Web browser sends request
    * E.g. GET /cs80/all\_the\_answers.html HTTP/1.1
  * Server responds
    * E.g. HTTP/1.1 403 Forbidden
* What information is in the HTTP header?
  * additional information regarding the response, such as the MIME type of information being sent
    * E.g. jpeg, html, etc
  * Followed by a blank line, then the message content
* What are the two most common HTTP requests?
  * GET and POST
    * GET requests content from the server
      * information can be sent to the server using the URL
    * POST sends information to the server
      * information is sent to the server in the HTTP message
* What is an attribute? What is a method?
  * Attributes are data - e.g. how much gas is in a car
  * Methods are functions, operations that manipulate data - e.g. accelerate
* What is the difference between a class and an instance?
  * A class acts as a blueprint, while an instance is a “real” incarnation of the class
* What is a benefit of information hiding?
  * The user (a programmer) doesn’t have to understand exactly how the class works to use it successfully
  * Prevents the user from accessing/editing data that they shouldn’t
* What is a benefit of encapsulation?
  * Grouping data and methods together enables information hiding
  * Objects are unaware and unable to access other object’s hidden data and methods
* What is inheritance?
  * Enables a class to inherit the chracteristics (attributes and methods) of an existing class
  * Additional characteristics can be added to the derived class (the class that’s doing the inheriting) to create different versions
  * Enables a heirarchical relationship between objects (just like in the real world!)

**Ch 2 & 3 - HTML5**

* What does HTML stand for?
  * Hypertext markup language
* What are HTML documents composed of?
  * A series of HTML elements (or tags) and text
  * Together these specify the structure and content of a document
* List an example of an element that does not markup text
  * `​<img>`​
  * \<meta\>
  * \<br\>
  * `​<wbr>`
* How should HTML elements be nested?
  * In the order of the nesting, e.g. the first tag in an HTML document should be the last closing tag
  * Do not “overlap” the closing of nested tags
* What are the valid range of headings?
  * 1 through 6
* Which heading is the largest?
  * `​<h1>`​
* Write the HTML to link to google.com.

```html
<a href="http://google.com">Google</a>
```

* Text manipulation and special characters:
  * `​<del>`​ - strikethrough
  * `​<sup>`​ - superscript
  * `<sub>`​ - subscript
  * `​&lt;`​ - symbol, \<
  * `​&gt;`​ - symbol, \>
  * `​&amp;`​ - symbol, &
  * `​&trade;`​ - symbol, trademark
  * `​&copy;`​ - symbol, copyright
  * `​&quot;`​ - symbol, “
  * `​&apos;`​ - symbol, ‘
* What element starts an ordered list? What element starts an unordered list?
  * `​<ul>`​ starts unordered list
  * `​<ol>`​ starts ordered list
* What element indicates a list element? Do ordered lists and unordered lists have different list elements?
  * Same element for both - `​<li>`​ which requires a closing tag
* What attributes are required for an `​<`​`img>?`
  * `src`​ and `​alt`​
* What is the difference between `​<th>`​ and `​<td>?`
  * `<td>`​ is used for table data cells, `​<th>`​ is used for header cell
  * `​<th>`​ typically has centering and bold already applied
* What do the `​rowspan`​ and `​colspan`​ attributes do?
  * `​rowspan`​ extends the cell to use two rows (merges cells vertically)
  * `​colspan`​ extends the cell to use two columns (mergers cells horizontally)
* Know how to create a table
  * See the tables example
* What does internal linking do?
  * Links to a specific element in an HTML document
  * Every element can be given an `​id`​ attribute, whose value can be used to link to with a `​href=“#id_value”`​ where `​id`​`​_value`​ is the value of an element’s `​id`​ attribute​
* What does the `​method`​ attribute specify for a form?
  * The HTTP request to use to send the form data to the server, either `​GET`​ or `​POST`​
* What does the `​action`​ attribute specify?
  * The URL to send the form to
* What form `​`​input resets a form to it’s default state?

```html
<input type="reset" value="Clear">
```

* What does the `​hidden`​ attribute mean on a form `​<input>`​ element?
  * The user cannot modify the input
  * A mechanism to send information with every form - the user has no actual input
* What input type does not perform any validation, even though you would expect it to?
  * `​tel`​
  * telephone numbers have many different formats
* New HTML5 form input types:
  * `password` - provides a password-protected ﬁeld. this is only visually enforced (displays a \* instead of the text), the password still should be encrypted be sent over HTTP
  * `color` - color input, most browsers have a color picker
  * `number` - user inputs a number, similar to a text but for numbers
  * `range` - user picks between a range of values
  * `checkbox` - user one or more options
  * `radio` - user picks one option from a list
  * `month` - user inputs a month and a year
  * `date` - user inputs a date, most browsers have calendar picker
  * `search` - user inputs a search query to execute on the server
  * `tel` - telephone number input, HTML5 does not validate this!
  * `url` - valid URL input
  * `​`​we went over a couple more as well
* What does the `​autofocus`​ do for an attribute?
  * Automatically gives focus on the input element (e.g. the user can type into this form immediately)
* How do you bypass form validation on the `​form`​ element? How do you bypass form using a `​submit`​ input type?
  * The `​novalidate`​ attribute on the `​form`​ element will prevent validation
  * The `​formnovalidate`​ attribute on the `​input`​ element (with `​type=“submit”`​)
* How do you make a form input required?
  * `​`​Add the `​required`​ attribute to the form input
* What is a regular expression?
  * A pattern to match text to
  * Defines a search pattern to look for
* Know how the `​autocomplete`​ works and how to use it
  * Set to `​on`​ or `​off`​ to enable or disable.
  * Uses previous answers to fill in data
* What is a `​datalist`​ and how do you use it?
  * Allows predefined list of options that will fill as the user types
  * See `​adv_new_forms.html`​ for information on how to use this.
* Review the page structure elements:
  * `header`: used to specify the header of the webpage, but can actually be included multiple times
    * Used to give introductory content or navigational links
* * `footer`: used to specify the footer of the webpage, but can actually be included multiple times
    * Used to give authorship information, copyright, contact, sitemap, etc time: used to identify a date, a time, or both
  * `nav`: used to group navigational links
    * Do not place all links in the nav element, only the navigational ones (could be in the header or the footer typically)
  * `ﬁgure`: describes a ﬁgure, used to group a ﬁgcaption and the img tag
  * `ﬁgcaption`: provides a caption for the corresponding ﬁgure
  * `article`: speciﬁes independent, self-contained content
    * can be nested
    * intended for forum posts, blog posts, news story, commentary, etc
  * `details`: provides information about a speciﬁc topic
  * `summary`: displays summary of content inside of a details tag
    * The details of the summary are contained in a details tag
  * `section`: provides a section-based structure to a page; similar to article, but more general
    * can be nested
    * used frequently with id attributes for internal linking
    * typically also comes with a header of some kind
  * `aside`: describes content related to something, but not critical
    * could be background history or related information
  * `meter`: shows an amount
    * similar to a range (but is not input), or a loading bar (but does not animate)
  * `mark`: highlight enclosed text
  * `wbr`: controls when to break a word when text wrapping to the next line
    * would this require a closing tag?