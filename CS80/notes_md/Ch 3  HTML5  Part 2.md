HTML5 introduces new input types for forms

* These input types are self-validating
  * No need for javascript validation!
* However, the input data should be verified server-side

New HTML5 form input types (each is part of a \<input type="type"\> tag):

* *color*: allows user to input a RGB, many browsers have color picker.
  * input must be a hexadecimal value (color code)
* *date*: calendar date input, many browsers have a calendar-style picker
* *datetime: *date and time input
  * yyyy-mm-ddThh:mm+ff in UTC (English time)
* *datetime-local: * date and time input
  * yyyy-mm-ddThh:mm+ff
* *email: *email input
  * address@domain.com
* *month: *month input
  * yyyy-mm
* *number: *any number input
  * min and max attributes set the min and max possible valid values
* *range: *range slider between particular values - no validation required
  * min and max attributes set the min and max possible values
  * all values are valid
* *search: *search field, behaves like a text input
* *tel: *telephone number input,** HTML5 does not validate this input!**
* *time: *time input
  * hh:mm
* *url: *valid URL input
  * [http://domain.com](http://domain.com/)
* *week: *input a specific week (nn is a week number, between 01 and 53
  * yyyy-Wnn

If a browser does not support the specified input type, the type will be treated as "text".

* Means you must validate server-side!

Input *tabindex* attribute

* enables controlling the order of input focus on TAB
* ordering starts at 1

HTML5 new form attributes:

* *autofocus:* applied to input tag, automatically gives focus to this element (e.g. user can type immediately)
  * Can only be used on one input element per document
* *formnovalidate*: applied to input tag, allows a form to bypass validation
  * Must be applied to the submit input type
  * Means you must validate server side!!
* *novalidate:* applied to the form tag, allows a form to bypass validation
  * Means you must validate server side!!
* *placeholder*: applied to input tag, temporary text in an input field
  * Typically either the format of the input, or an example
  * Only applies to the following input types:
    * text
    * search
    * url
    * tel
    * email
* *required:* applied to input tag, requires the user to input the form element
  * Form cannot be submitted until they do
  * this is overridden by formnovalidate or novalidate
* *pattern: *applied to input tag, requires the input match the specified regular expression
  * What's a regular expression (regex)?
    * A pattern matching tool
    * Text is described through a pattern, rather than a full description outlining every character
  * side note: our example pattern explained
    * pattern = "\\(\\d{3}\\) +\\d{3}-\\d{4}"
    * side note: "\\" in regex is similar to "&" in HTML
      * It escapes the special character
        * escaping meaning stripping it of its special meaning
    * "(" has a special meaning in regex, namely to start saving the matched pattern
      * ")" marks the end of this saved pattern
      * You can then reference it later with \\\# where \# is the number of () used in the expression you wish to reference
        * E.g. to reference the first saved (), use \\1
      * because of this special meaning, we have to escape it
    * "\\d" says we want to look for a digit ([0-9])
      * In this case, the escape gives "d" a special meaning - namely a digit
    * {3} says we want to look for the previous pattern 3 times (3 digits)
    * the " " is a literal space to look for
      * "+" means match the previous pattern 1 or more times
    * then we look for 3 more digits, followed by a "-" then 4 more digits
* *autocomplete*: added to form or input tag, allows user to use previously submitted information when returning to the same form
  * You can turn autocomplete on or off for specific elements, overriding a value already set
    * Allows you to protect sensitive information from being autocomplete candidates
      * E.g. password, credit card info, etc.

*datalist* element

* provides input options for a text form input
* As the user starts typing, the list will narrow
  * how the list narrows depends on the browser
* The datalist must be connected to an input through the *id* attribute
  * This is the glue between the list and the corresponding form input
  * also means one list can be used on multiple form inputs

Page structure elements

* *header*: used to specify the header of the webpage, but can actually be included multiple times
  * Used to give introductory content or navigational links
* *footer*: used to specify the footer of the webpage, but can actually be included multiple times
  * Used to give authorship information, copyright, contact, sitemap, etc
* *time:* used to identify a date, a time, or both
* *nav:* used to group navigational links
  * Do not place all links in the nav element, only the navigational ones (could be in the header or the footer typically)
* *figure:* describes a figure, used to group a *figcaption* and the *img* tag
* *figcaption:* provides a caption for the corresponding figure
* *article*: specifies independent, self-contained content
  * can be nested
  * intended for forum posts, blog posts, news story, commentary, etc
* *details:* provides information about a specific topic
* *summary:* displays summary of content inside of a *details* tag
  * The details of the summary are contained in a *details *tag
* *section:* provides a section-based structure to a page; similar to article, but more general
  * can be nested
  * used frequently with *id* attributes for internal linking
  * typically also comes with a header of some kind
* *aside:* describes content related to something, but not critical
  * could be background history or related information
* *meter*: shows an amount
  * similar to a *range* (but is not input), or a loading bar (but does not animate)
* *mark: *highlight enclosed text
* *wbr:* controls when to break a word when text wrapping to the next line
  * would this require a closing tag?

But remember, these are general guidelines. HTML is a like a toolbox; you are free to use them as you see fit. But remember, a hammer is better at nailing than a saw. In general, it's best to stick to the convention.

Advanced HTML5

* *video*: allows you to add a video
  * *controls* attribute (no arguments/assignment) allows you to add video control buttons, such as play, pause, volume
  * *height *and* width * can be added to control the size of the video
  * *muted *will start the video initially muted
  * *loop* will determine whether or not the video should loop after finishing
  * *autoplay *will start the video as soon as it loads
  * **the video tag is dissimilar from the *img tag*
    * you can use the video tag as a void tag (like an img tag) or you can specify multiple *source* tags
    * *source* tags specify a video file and a type
      * a video tag can have multiple source tags; the browser will play the first type supported.
      * If no types are supported, the text in between the video tag will be displayed.
  * Example (void tag):

```html
<video src="movie.mp4" width="320" height="240" controls>
```

* Example (with multiple sources):

```html
<video width="320" height="240" controls>
    <source src="movie.mp4" type="video/mp4">
    <source src="movie.ogg" type="video/ogg">
    Your browser does not support the video tag.
</video>
```

* *audio: *extremely similar to playing video
  * Only difference with video is no *height* and *width *attribute
  * *controls, autoplay, loop, muted* are all the same
  * must specify an audio file (like MP3) instead of video
* *canvas:* allows you to draw 2D and 3D drawings on the screen
  * This requires javascript, so just hold on, we will go over this later!

** **