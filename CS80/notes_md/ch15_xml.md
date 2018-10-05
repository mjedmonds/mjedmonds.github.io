---
apple-mobile-web-app-capable: yes
apple-mobile-web-app-status-bar-style: 'black-translucent'
author: Mark Edmonds
description: Chapter 15, XMl
title: XML
---

## Chapter 15: XML

CS 80: Internet Programming

Instructor: Mark Edmonds

## XML describes data

- Remember the above!
- Stands for \"Extensible Markup Language\"
  - XML is a *meta-language* meaning it is not a lanugage itself, but rather a language for building languages

## XML describes data

- HTML is a sort of \"variation\" of XML, though it technically is not XML
  - XHTML is a version of HTML that does adhere to actual XML rules
  - So, we\'ve seen something very similar before

## XML describes data

- What\'s the point?
  - XML allows us to describe data in a strict, organized, but flexible manner
  - This means we can create specific markup languages for any sort of data
    - We\'d need to parse the data for it to be meaningful, but XML is a building block

## XML describes data

- Consider we have the following data:
  - `John 10 Bill 15 Judy 25`
  - What does this data mean?
    - I have no idea from just the above
    - If I put this on the internet, no one else will know what it means either

## XML describes data

- XML allows us to share data efficiently
- Consider the following

  ```xml
  <!-- XML representing a family - notice the explicit structure -->
  <family>
    <member>
      <name>John</name>
      <age>10</age>
    </member>
    <member>
      <name>Bill</name>
      <age>15</age>
    </member>
    <member>
      <name>Judy</name>
      <age>25</age>
    </member>
  </family>
  ```

## XML describes data

- This data makes a lot more sense!
  - The initial data had a lot of implicit information that we have made explicit through XML

## XML Concepts

- Why care?
  - XML makes data formats portable and application independent
    - Which makes them a very good idea for the internet!
    - Application independent means I don\'t need the application using the data to understand the data (contrast a format like Word document to a .txt)

## XML Concepts

- Specify the document\'s structure
- Consist of the element\'s name in angle brackets
- Example: `<data>`

## XML Concepts

- XML elements have start and end tags
  - Start tag proceeds as above, e.g. `<data>`
  - End tag has a backslash (`\` after the `<`, e.g. `</data>`
    - End tags can be shorthanded in the starting tag by place a forward slash `/` before the closing `<` of the opening tag. e.g. with `<data/>` as the start tag
  - Looks familiar!

## XML Concepts

- Every XML document contains one root element, which contains all other elements
  - Similar to `<html>`

## XML Concepts

- XML-based markup languages are called **XML vocbaularies**
  - Provide a mechanism to describe data in a standardized, structured way.
  - Examples: XHTML, MathML (math), VoiceXML (speech), XBRL (financial data)
  - Why do XML vocabularies matter?
    - Large companies often employ their own XML vocabulary to describe their data internally
    - They provide a standard for data markup using a standard data format (e.g. if you can read XML, a XML vocabulary will be easier to understand than a proprietary data format)

## XML Concepts

- XML documents have the extension `.xml` and are readable by any text editor
- XML is just a data format; it does not contain styling
  - Devices are responsible for how a XML is rendered
  - However, Extensible Stylesheet Language allows you specify rendering on different platforms

## XML Parsing

- Because we are specifying a data markup, we need a way to understand the format
- XML parsers read XML
  - Now that we have covered DOM, think about what your browser does to load a `.html` file into the DOM tree (it has to parse it!)

## XML Parsing

- Basic XML Rules:
  1. Single root element
  2. A start and end tag for each element
  3. Properly nested tags
  4. Case sensitive
  - Following these rules means the document is **well-formed**

## XML Parsing

- Basic XML Rules:
  1. Single root element
  2. A start and end tag for each element
  3. Properly nested tags
  4. Case sensitive

- Which of these rules does HTML break?
  - 2, 3, and 4

## XML Validation

- Some parsers can also validate the XML\'s adhere to a particular markup
- Relies on a Document Type Definition (DTD) or a Schema
  - These documents describe the proper document structure
  - Think of these like a grammar for what forms a valid XML document using this data markup

## XML Validation

- A validating parser reads the XML and makes sure that it follows the structure defined in the DTD or Schema
  - If the document is well-formed XML and adheres to the DTD/Schema, then it is valid
  - Otherwise, the document is invalid
  - Note that a document may be well-formed XML but may not be a valid document

## Example: [`article.xml`](../examples/ch15_xml/article.xml)

```{include=../examples/ch15_xml/article.xml}
```

## Writing XML

- The first line, `<?xml version="1.0"?>` declares the document as a XML document
  - Similar to `<!DOCTYPE HTML>`
  - NO characters must be before the XML declaration
- XML Comments are identical to HTML comments
- The first XML element is the root node; it\'s closing tag should be the last tag in the document

## Writing XML

- XML Element Names
  - Can contain letters, digits, underscores, hyphens, and periods.
  - Must start with an underscore or letter
  - Must not being with any case-combination of \"xml\" as these are reserved for XML
- Nesting XML elements is identical to nesting HTML elements
  - Must still be careful about proper nesting

## XML Namespaces

- Suppose we want to use the use \"subject\" in multiple ways: one for subjects in high school, the other for subjects in medical schools

  ```xml
  <subject>Geometry</subject>
  <subject>Radiology</subject>
  ```

- We have an ambiguity in our data format as we probably don\'t want to mix high school and medical school subjects!
  - So we need a way to add additional categorical/hierarchical information

## XML Namespaces

- Namespaces allow us to give more specific scope to an XML element
  - The namespace itself is called a **namespace prefix** and is followed by a colon (`:`) before the XML element name
- For our example

  ```xml
  <highschool:subject>Geometry</highschool:subject>
  <medicalschool:subject>Radiology</medicalschool:subject>
  ```

## XML Namespaces

- The `xmlns` defines a namespace
  - Syntax `xmlns:prefix="URI"`
  - URI can be anything, it is just supposed to be a uniform resource identifier
  - Can be Uniform Resource Name (URN) or Uniform Resource Locator (URL)
    - URN\'s are a series of names separated with colons
      - E.g. `urn:schooltypes`
  - No namespace prefix should begin with `xml` (it is reserved)

## Example: [`namespaces.xml`](../examples/ch15_xml/namespaces.xml)

```{include=../examples/ch15_xml/namespaces.xml}
```

## Default Namespaces

- Specifying `xmlns = "URI"` specifies a default namespace for the entire document

## Example: [`default_namespaces.xml`](../examples/ch15_xml/default_namespaces.xml)

```{include=../examples/ch15_xml/default_namespaces.xml}
```

## Default Namespaces

- Notice the difference between the two versions
  - They have the same semantic meaning, but one contains significantly less manual tagging of elements!
  - Use a default namespace if want every element to be in a namespace and have a namespace that is particularly common

## DTD

- A method for defining a grammar for validating XML
- Reasonably simple to follow, but it\'s an aging implementation. Schema is more powerful and more intuitive once you know XML
- Follows Extended Backus-Naur Form (EBNF) grammar

## DTD

- Follows Extended Backus-Naur Form (EBNF) grammar
  - Basically a lis of production rules for what makes up a valid document
  - E.g. a sentence is a `SUBJECT` followed by a `PREDICATE`, but also has many optional arguments
  - A *context-free grammar* (CGF) to recursively write rules to generate patterns
    - Technically, English is not a context-free grammar
    - For more about CFG\'s look into Alan Turing and Noam Chomsky\'s work, a branch of computer science called Automata Theory!

## XML Schema

- Allows us to validate an XML document
  - Why do we need to specify this?
    - XML is a meta-language, so there\'s nothing to validate by default. We define a language to validate, so we must define the validation as well
      - Think if you were writing your own programming language; you\'d have to write a \"syntax validator\" to validate that a program contained valid syntax

## XML Schema

- Used by validating parsers to validate documents
- Documents that conform the to schema are valid, documents that do not conform to the schema are invalid
- Schema documents have the extension `.xsd`
  - Can validate schema at [www.xmlforasp.net/SchemaValidator.aspx](www.xmlforasp.net/SchemaValidator.aspx)
- Let\'s start with an example

## Example: [`book.xml`](../examples/ch15_xml/book.xml)

```{include=../examples/ch15_xml/book.xml}
```

## Example: [`book.xsd`](../examples/ch15_xml/book.xsd)

```{include=../examples/ch15_xml/book.xsd}
```

## XML Schema

- In the schema, we have two namespaces
  - One for the schema itself, `xmlns`, which can be used to validate the schema
  - The second, `xmlns:deitel`, which is used to define names created by us
- Our `targetNamespace` is the URI of the XML vocabulary that this schema defines

## Schema Attributes

- Name corresponds to the element\'s name and type specifies the element\'s type
- Types:
  - XML has predefined types, or you can create user-defined types

## Schema Attributes

- There are two categories of types:
  1. **Simple types**: a basic type. Cannot contain attributes or child elements
  2. **Complex types**: a complex type. Can contain attributes or child elements
  - Complex types may have **simple content** or **complex content**. Both can contain attributes, but only complex content contain child elements. Simple content must extend or restrict a base user or XML type

## XML Types

![XML Types](images/ch15_xml_types-1.png)

## XML Types

![XML Types](images/ch15_xml_types-2.png)

## Example: [`laptop.xml`](../examples/ch15_xml/laptop.xml)

```{include=../examples/ch15_xml/laptop.xml}
```

## Example: [`laptop.xsd`](../examples/ch15_xml/laptop.xsd)

```{include=../examples/ch15_xml/laptop.xsd}
```