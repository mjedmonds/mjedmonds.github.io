**CSS = Cascading Style Sheet**

What does HTML5 do?

* Specifies the content and structure of the webpage

So far, we haven’t controlled the *presentation* of the webpage at all.

CSS allows us to control the presentation of the page

Why not control the presentation within the HTML?

* You can!
* But in general, it’s better to separate!
  * Why? Because you can swap the style without changing anything in the HTML document

**Starting simple: inline styles**

* Specify the style in the html tag through a *style *attribute
  * E.g. to change the font size, one might apply the attribute `​style=“font-size: 45pt;”`​ which would set the font size to 45pt.
* Advantage:
  * Styling is applied solely to this instance of the tag (useful if we want custom styling for one particular tag)
* Disadvantage:
  * Styling is applied solely to this instance of the tag (meaning it has no generality; we can’t change the style of every tag across the entire document. In our example, we may want to change every `​<h2>`​ in the document
* See: `​inline_styles.html`​

**Embedded style sheets**

* Idea: embed a styling sheet inside the `​<head>`​ tag of the HTML document
* Example:

```html
<style type="text/css">
  p { font-size: x-large;
      font-family: arial, sans-serif; }
</style>
```

* What does this do?
  * Changes every `​<p>`​ tag in the document to have an extra large font and use Arial font
* Each property is a key-value pair
  * Key is the property to change (e.g. `​font-size`​)
  * Value is the setting of the property (e.g. `​x-large`​)
  * Key and value are always separated by a `​:`​ and the key-value pair is terminated with a `​;`​
* Advantage:
  * Styling is applied across every instance of an element in the entire document
* Disadvantage:
  * Styling is still restricted to this HTML document; we cannot “export” the embedded style sheet to other HTML documents
* See `​embedded_styles.html`​

**Common CSS Properties**

* `**​**font-family`​
  * Names the font to use.
  * Typically a comma-separated list. The browser will attempt to use the first font availabe in the list. The final entry in the list should be a generic font, like `​serif`​, `​sans-serif`​, `​monospace`​, `​cursive`​, or `​fantasy`​
  * Example: `​font-family: helvectica, tahoma, sans-serif;`
* `​font-size`
  * ​Controls the font size of text
  * Can specify size two different ways: through a point value (`​NUMBERpt)`​ or with a relative size
    * Available relative sizes: `​xx-small`​`​, x-small, small, smaller, medium, large, ``​larger`​`​, x-large, xx-large`)
    * Preferrable to use relative sizes
      * Why? Different computers have different resolutions, so using `​pt`​ will result in different effects based on the user’s display
  * Example: `​font-size: x-small;`​
* `​font-style`​
  * Controls the font’s additonal styling
  * Possible values: `​normal, italic, oblique`
  * Example: `​font-style: italic`​
* `​background-color`
  * ​Sets the background color. Takes hexidemial value or rgb
  * Example: `​background-co``lor: \#668B8B`
  * ​See: `​background_color.html`​
* `​background-image`​
  * Takes a `url(‘image’)` and uses it as the background
  * Can have a list of comma-separated `​url()`​’s to fetch
  * Example: `​background-image: url(‘http://eskipaper.com/images/sand-dune-pictures-1.jpg')`
  * ​See: `​background_image.html`​
* `​background-repeat`​
  * specifies whether or not you would like the background to repeat or not
  * By default, background repeats
  * Possible values: `​repeat, repreat-x, repeat-y, no-repeat`
    * ​`​repeat`​ will repeat in both the x and y direction
  * Example: `​background-repeat: repeat-x`​
* `​background-position`​
  * specifies the background relative to the HTML element.
  * X is offset from the left and Y is offset from the top
  * Takes unit values (like width and height) or `​left, right, center,`​ for X `top, bottom, center`​ for Y
  * By default, background position is (0,0) relative to the element’s position in the document
  * Example: `​`​`​background-position: center left;`​
    * If you only specify one, the other will default to center
* `​background`​
  * This is a shorthand way to apply all of the above
  * `background: bg-color bg-image position bg-repeat`**
* `​text-align`​
  * `​center`​, `​left`​, or `​right`​ to align text
* CSS property list reference: [https://developer.mozilla.org/en-US/docs/Web/CSS/CSS\_Properties\_Reference](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Properties_Reference)

**Common CSS-related HTML tags**

* `​`**​**`**​\<**div>`​
  * specifies a HTML block element, similar to `​<p>`​, but doesn’t denote a paragraph
  * starts with a new line and takes up as much width available (stretches to the left and right as much as possible)
    * `​<h1>-<h6>`​ and `​<p>`​ are also block elements (consider their behavior!)
* `​<span>`​
  * an inline block
  * has minimal width and doesn’t start a new line
* Why do these matter?
  * They are commonly used to apply styling to subsections of the document, when no other divisor exists
  * E.g. think of the `​<em>some text</em>`​ as `​<span style="font-style: italic;”>some text</span>`​
    * We may/probably don’t have a built-in tag to help us, so `​div`​ and `​span`​ can be a very general way to apply styling to a specific section

**CSS Classes and Selectors**

* It’s pretty limiting to only be able to use CSS styling on an element-by-element basis
* CSS classes are applied to a tag on a tag-by-tag basis using the `​class`​ attribute
* Advantages:
  * Can use the same class among multiple HTML tags
  * Updating the CSS class will update all tags
* Usage:
  * All classes start with `​.`​
  * Example: `​.emph { font-style: italic; }`​, can apply this class using `​<p class=“emph”>some_text</p>`
* We can even apply certain classes only to specific HTML tags
  * This type CSS styling increases the *specifcity* of the styling, which help resolve styling conflicts (more on this in a bit)
  * Example: `​p.emph { font-style: italic; }`​ only defines our `​emph`​ class for use within a `​<p>`​ HTML tag
* Selectors are a bit more general (classes are a type of selector)
  * They specify how the CSS rules should be applied
  * A class is a selector rule, but we also have selectors for `​id`​’s with `​#id`​
    * Example: in CSS, we have `​#htmlid { color: blue }`​ and within html we have `​<section id=“htmlid”>`​. All of this section’s font will be blue!
* CSS Precedence
  * ID selection has the highest precedence
  * Followed by tag-specific classes (e.g. `​p.emph`​)
  * Followed by classes (e.g. `​emph`​)
  * Followed by HTML tag rules (e.g. `​`​`​p`​)

**Conflicting Styles**

* What does *Cascading** *mean?
  * “falling through”
* So far, we’ve seen rules will maintain their presence in nested children until something overwrites their value (consider `​background_color.html`​)
* But what’s the actual logic hear?
  * Children of HTML elements inherit the CSS styling of their parents
  * Children style’s have a higher precendence over their parents, so their styling will always replace their parents (if applicable)
* Let’s try a weird scenario:
  * We defined a `​emph`​ both as a CSS class and a CSS class for `​<p>`​
  * So what happens when we right a normal `​<p>`​ (no class specified) inside of a `​<div class=“emph”>`​?
  * See `​conflicting_styles.html`​
* There are other ways to generate conflicts (such as `​background_color.html`​ using normal nesting)
* But the general rule: the most specific styling takes precedence

**External Style Sheets**

* Idea: store the style sheet elsewhere and import it into the HTML document
* Advantage:
  * We can use the same styling across multiple HTML documents
  * If they all import the same external style sheet, they will all adhere to the same styling rules
  * If we change the stylesheet once, it will affect all documents that link to it!
* The `​<link>`​ HTML tag is used to import the external styling
  * Attributes required:
    * `​rel=“stylesheet”`​ specifies the relationship between this document and the external one, in this case, we want to link to a stylesheet
    * `​type=“text/css`​`​“`​ just like how we specified with `​<style type=“text/css”>`​
    * `​href=“style.css”`​ is the hyperlink reference to the external document
* Example: `​\<link rel=“stylesheet” type=“text/css” href=“style.css"\>`​
* See: `​external_styles.html`

**CSS Comments**

* `​/* This is a CSS comment. start with /* and end with */ */`

**
**

**CSS Units**

* Used to control sizing.
* `​#em`​ amount relative to the normal size
* `​#cm`​ amount in centimeters
* `​#px`​ amount in pixels
* `​#pt`​ amount in points
* Keep these in mind when looking at CSS

**Positioning**

* `​position`​ property controls the location of document elements
  * Basic idea: answers the question: where should this element be relative to other elements?
  * Corresponding attributes: `​left: value;`​ and `​top: value;`​ which control the amount of positioning to apply
    * “left” corresponds to how much to move from left
    * “top” corresponds to how much to move from the top
    * See: [http://www.w3schools.com/cssref/pr\_pos\_left.asp](http://www.w3schools.com/cssref/pr_pos_left.asp) for values
    * Keep these mind when considering the various positioning types
  * `​position: absolute;`​ sepcifies this elements position **relative to it’s first positioned (not static) ancestor element**
    * “Ancestor” refers to the parents of this HTML element (nesting establishes parent-child relationships)
  * `​position: relative;`​ specifies the element’s position **relative to its normal positioning**
    * So if we move 5px from the left and 10px from the top, the element is positioned right 5px and down 10px
  * `​position: fixed;`​ specifies the element’s position **relative to the browser window**
  * `​position: static;`​ the default behavior, positioning is determined by document flow/ordering
  * Property values: [http://www.w3schools.com/cssref/pr\_class\_position.asp](http://www.w3schools.com/cssref/pr_class_position.asp)
* See: `​positioning.html`​

**Element Dimensions**

* These allow us to specify the actual dimensions of each page element.
* Benefits: helps control the size of elements, which can be useful for positioning
* Two main properties:
  * `​width: value;` to specify width
  * `​height: value;`​ to specify height
* `​overflow`​ property defines what to do if the content of an element goes over the specified dimensions
  * Possible values:
    * `​overflow: visible;`​ overflow will still be rendered (overflowing into over elements)
    * `​overflow: hidden;`​ overflow will be clipped (overflowing content will be invisible)
    * `​overflow: scroll;`​ scroll bars are used to view the rest of the content
    * `​overflow: auto;`​ if the overflow is clipped, a scroll bar will appear
* See: `​positioning.html`​

**The Box Model**

* We’ve loosely discussed the notion of boxes with html elements (like `​p, div, h1-h6, section`​`​`​), but let’s formalize it
* Key terms:
  * Content: the area the actual content makes up
  * Padding: area between the content and the border
  * Margin: area between the border and other elements

![Screenshot 2016-09-27 22.16.20.png](resources/A729A9B3B7FE1CD2F7D82F2312ED2CB7.png)

* **A critical note:** border defines the “end” of the element box in some sense
  * Margin is a means to enforce a **minimum distance between two elements’ borders**
  * **READ THE LAST SENTENCE CAREFULLY**
  * What this means: margins **do not sum**
    * Think of it as a “max” (which ever element has the largest margin will be enforcing the margin)
  * Quiz:
    * If you have an element with a margin of 5 pixels next to an element with a margin of 10 pixels, what will be the number of pixels **between the borders?** (this is the effective margine)
    * If you have an element with a margin of 500 pixels next to an element with a margin of 10 pixels, what will be the number of pixels **between the borders?** (this is the effective margine)
* Controlling borders
  * `​`​`​border-width`​ property
    * [http://www.w3schools.com/cssref/pr\_border-width.asp](http://www.w3schools.com/cssref/pr_border-width.asp)
  * `​border-style`​ property
    * [http://www.w3schools.com/cssref/pr\_border-style.asp](http://www.w3schools.com/cssref/pr_border-style.asp)
  * `​border-color`​ property
    * [http://www.w3schools.com/cssref/pr\_border-color.asp](http://www.w3schools.com/cssref/pr_border-color.asp)
  * Shorthand: `​border: width style color;`​
* See: `​box_model.html`​

**Floating Elements**

* Allows you to move an element to one side of the screen while other content flows around it
* This “breaks” our notion of block elements (such as `​p, div, section, h1-h6`​) to fill the width of the screen.
* When used with element dimensions, page layout becomes very controllable
* Three property values:
  * `​float: none;`​ default, element is not floated
  * `​float: right;`​ element is floated to the right. Other content can flow on the left side
  * `​float: left;`​ element is floated to the left. Other content can flow on the right side
* `​clear`​ allows you to specify that an element should not flow with a float (e.g. will not flow with an element on right/left; it will start below the floated element)
  * `​clear: left;`​ do not allow floating to the left
  * `​clear: right;`​ do not allow floating to the right
  * `​clear: both;`​ do not allow floating to the light or right
* See: `​floating.html`​

**Margin and Padding**

* `**​**margin`​ property specifies the required space between the border and the next element (see box model above)
  * Value is a length (px, pt, cm, etc) or a % of the page
  * The `​margin`​ attribute is shorthand for `​margin-top`​, `​margin-right`​, `​margin-bottom`​, `​margin-left`​
    * See [http://www.w3schools.com/css/css\_margin.asp](http://www.w3schools.com/css/css_margin.asp) for margin variations
  * Example: `​margin: 50px 40px 100px 25px`​ (what does this mean?)
  * Example: `​margin-top: 100px`​
* `​padding`​ property specifies the amount of space between the content and the border (see box model above)
  * Value is a length (px, pt, cm, etc) or a % of the page
  * The `​padding`​ attribute is shorthand for `​padding-top`​, `​padding``-right`​, `​padding``-bottom`​, `​padding-left`​
    * See [http://www.w3schools.com/css/css\_padding.asp](http://www.w3schools.com/css/css_padding.asp) for padding variations
  * Example: `​padding: 50px 40px 100px 25px`​ (what does this mean?)
  * Example: `​padding-top: 100px`​
* See: `​`media\_types\_queries.html or `​positioning.html`

**Media Types and Media Queries**

* Media Types
  * Allow you to specify what the page should look like on different media.
  * Standarad media type is `​screen`​, which stands for computer screen
  * Other options: `​handheld`​ (cell phone/mobile)​, `​speech`​ (read out old)​, `​print`​ (printers)​.
  * Basic example:

```css
@media all {
  body { background-color: black; }
}
@media print{
  body { background-color: white; }
}
```

* Media Queries
  * Allow you to query the user’s device and use different CSS rules based on the media
  * `​height`​ - height of display area (the browser)
  * `​width`​ - width of display area (the browser)
  * `​resolution`​ - resolution of the output device
  * `​orientation`​ - landscape or portrait
* CSS Syntax grammar:

```css
@media not|only mediatype and (media feature) {
    CSS-Code;
}
```

* `​not`​ negates the media query
  * `​only`​ applies the style only if the query matches
  * Note: you may omit the `​mediatype`​ and only specify a `​(media feature)`​ if you wish
* See: `media_types_queries.html`

**Drop-Down Menus**

* Excellent way to control navigation panes without using screen space
* Utilized through the `​display`​ property:
  * Controls how the element is displayed; e.g. `​block`​ (like `​p, section`​ etc) or `​inline`​ (like `​span, em`​ etc)
  * `​display: none;`​ element is not displayed
  * `​display: block;`​ displays a block level element
  * `​display: inline;`​ displays as an inline element
  * `​display: inline-block;`​ display is like an inline element, but can have a specified height and width
* See: `​drop_down_menu.html`