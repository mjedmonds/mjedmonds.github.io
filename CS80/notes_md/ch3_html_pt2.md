---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: |
    A course on the world\'s fastest growing machine learning library,
    TensorFlow
title: 'Introduction to HTML: Part II'
---

::: {.reveal}
::: {.slides}
::: {.section}
Chapter 3: Introduction to HTML Part 2
--------------------------------------

CS 80: Internet Programming

Instructor: Mark Edmonds
:::

::: {.section}
### HTML5 Forms

HTML5 introduces new input types for forms

These input types are self-validating

-   No need for javascript validation!

However, the input data should be verified server-side
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

Each is part of a `<input type="type">` tag

`color`: allows user to input a RGB, many browsers have color picker.

-   input must be a hexadecimal value (color code)

`date`: calendar date input, many browsers have a calendar-style picker
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`datetime`: date and time input

-   yyyy-mm-ddThh:mm+ff in UTC (English time)

`datetime-local`:  date and time input

-   yyyy-mm-ddThh:mm+ff
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`email`: email input

-   address\@domain.com
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`month`: month input

-   yyyy-mm

`number`: any number input

-   min and max attributes set the min and max possible valid values
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`range`: range slider between particular values - no validation required

-   min and max attributes set the min and max possible values

-   all values are valid
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

-   `search`: search field, behaves like a text input

-   `tel`: telephone number input, **HTML5 does not validate this
    input!**
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`time`: time input

-   hh:mm

`url`: valid URL input

-   [http://domain.com](http://domain.com/)
:::

::: {.section}
### HTML5 Forms

New HTML5 form input types

`week: `input a specific week (nn is a week number, between 01 and 53

-   yyyy-Wnn

If a browser does not support the specified input type, the type will be
treated as \"text\".

-   Means you must *always* validate server-side!
:::

::: {.section}
### [Example: `new_forms.html`](../examples/ch3_html_pt2/new_forms.html)

              
:::

::: {.section}
### Input Focusing

Input `tabindex` attribute

-   `tabindex` attribute enables controlling the order of input focus on
    TAB

-   Ordering starts at 1
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

`autofocus:` applied to input tag, automatically gives focus to this
element (e.g. user can type immediately)

-   Can only be used on one input element per document
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

`formnovalidate`: applied to input tag, allows a form to bypass
validation

-   Must be applied to an input type

-   Means you must validate server side!!

`novalidate:` applied to the form tag, allows a form to bypass
validation

-   Means you must validate server side!!
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

`placeholder`: applied to input tag, temporary text in an input field

Typically either the format of the input, or an example

Only applies to the following input types:

-   `text`, `search`, `url`, `tel`, `email`
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

`required:` applied to input tag, requires the user to input the form
element

-   Form cannot be submitted until they do

-   this is overridden by formnovalidate or novalidate
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

-   `pattern:` applied to input tag, requires the input match the
    specified regular expression
:::

::: {.section}
### Regular Expressions

A regular what?

What\'s a regular expression (regex)?

-   A pattern matching tool

-   Text is described through a pattern, rather than a full description
    outlining every character
:::

::: {.section}
### Regular Expressions

Telephone pattern explained

Pattern:

    \(\d{3}\) +\d{3}-\d{4}

Prelimnary note: `\` in regex is similar to `&` in HTML

`/` escapes the special character

-   Escaping means stripping it of its special meaning
:::

::: {.section}
### Regular Expressions

Telephone pattern explained

Pattern:

    \(\d{3}\) +\d{3}-\d{4}

`(` has a special meaning in regex, namely to start saving the matched
pattern to a *group*

`)` marks the end of the saved group

You can then reference it later with `\#` where `#` is the group number
used in the expression you wish to reference

-   E.g. to reference the first saved group, use `\1`

because of this special meaning, we have to escape it
:::

::: {.section}
### Regular Expressions

Telephone pattern explained

Pattern:

    \(\d{3}\) +\d{3}-\d{4}

`\d` says we want to look for a digit (\[0-9\])

-   In this case, the escape gives `d` a special meaning - namely a
    digit

{3} says we want to look for the previous pattern 3 times (3 digits)
:::

::: {.section}
### Regular Expressions

Telephone pattern explained

Pattern:

    \(\d{3}\) +\d{3}-\d{4}

\"` `\" is a literal space to look for

-   `+` means match the previous pattern 1 or more times

Then, we look for 3 more digits, followed by a `-` then 4 more digits
:::

::: {.section}
### HTML5 Forms

New HTML5 form attributes

`autocomplete`: added to form or input tag, allows user to use
previously submitted information when returning to the same form

You can turn autocomplete on or off for specific elements, overriding a
value already set

Allows you to protect sensitive information from being autocomplete
candidates

-   E.g. password, credit card info, etc.
:::

::: {.section}
### `datalist` element

Provides input options for a text form input

As the user starts typing, the list will narrow

-   how the list narrows depends on the browser

The datalist must be connected to an input through the `id` attribute

-   This is the glue between the list and the corresponding form input

-   Also means one list can be used on multiple form inputs
:::

::: {.section}
### [Example: `adv_new_forms.html`](../examples/ch3_html_pt2/adv_new_forms.html)

              
:::

::: {.section}
### [Example: `fig3_17.html`](../examples/ch3_html_pt2/fig3_17.html)

              
:::

::: {.section}
### Page structure elements

`header`: used to specify the header of the webpage, but can actually be
included multiple times

-   Used to give introductory content or navigational links

`footer`: used to specify the footer of the webpage, but can actually be
included multiple times

-   Used to give authorship information, copyright, contact, sitemap,
    etc
:::

::: {.section}
### Page structure elements

`time:` used to identify a date, a time, or both

`nav:` used to group navigational links

-   Do not place all links in the nav element, only the navigational
    ones (could be in the header or the footer typically)

`figure:` describes a figure, used to group a `figcaption` and the `img`
tag

`figcaption:` provides a caption for the corresponding figure
:::

::: {.section}
### Page structure elements

`article`: specifies independent, self-contained content

-   Can be nested

-   Intended for forum posts, blog posts, news story, commentary, etc

`details:` provides information about a specific topic

`summary:` displays summary of content inside of a `details` tag

-   The details of the summary are contained in a `details `tag
:::

::: {.section}
### Page structure elements

`section:` provides a section-based structure to a page; similar to
`article`, but more general

-   Can be nested

-   Used frequently with `id` attributes for internal linking

-   Typically also comes with a header of some kind

`aside:` describes content related to something, but not critical

-   Could be background history or related information
:::

::: {.section}
### Page structure elements

`meter`: shows an amount

-   Similar to a `range` (but is not input), or a loading bar (but does
    not animate)

`mark: `highlight enclosed text

`wbr:` controls when to break a word when text wrapping to the next line

-   Would this require a closing tag?
:::

::: {.section}
### [Example: `new_elements.html`](../examples/ch3_html_pt2/new_elements.html)

              
:::

::: {.section}
#### 

Remember, these are general guidelines. HTML is a like a toolbox; you
are free to use them as you see fit.

A hammer is better at nailing than a saw. In general, it\'s best to
stick to the convention.
:::

::: {.section}
### Advanced HTML5

Video

-   `controls` attribute (no arguments/assignment) allows you to add
    video control buttons, such as play, pause, volume

-   `height `and `width` can be added to control the size of the video

-   `muted `will start the video initially muted

-   `loop` will determine whether or not the video should loop after
    finishing
:::

::: {.section}
### Advanced HTML5

Video

`autoplay `will start the video as soon as it loads

The `video` tag is dissimilar from the `img` tag

You can use the video tag as a void tag (like an `img` tag) or you can
specify multiple `source` tags

`source` tags specify a video file and a type

-   A `video` tag can have multiple `source` tags; the browser will play
    the first type supported.

-   If no types are supported, the text in between the `video` tag will
    be displayed.
:::

::: {.section}
### Advanced HTML5

Audio

Extremely similar to playing video

-   Only difference with video is no `height` and `width` attribute

-   `controls`, `autoplay`, `loop`, `muted` are all the same

-   Must specify an audio file (like MP3) instead of video
:::

::: {.section}
### [Example: `audio.html`](../examples/ch3_html_pt2/audio.html)

              
:::

::: {.section}
### Advanced HTML5

Canvas

`canvas:` allows you to draw 2D and 3D drawings on the screen

-   This requires javascript, so just hold on, we will go over this
    later!
:::
:::
:::

::: {.statcounter}
[![Web Analytics Made Easy -
StatCounter](//c.statcounter.com/11819202/0/3d207e19/0/){.statcounter}](http://statcounter.com/ "Web Analytics Made Easy -
  StatCounter")
:::
