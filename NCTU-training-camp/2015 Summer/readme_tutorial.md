# This is an H1
## This is an H2
### This is an H3
#### This is an H4
##### This is an H5
###### This is an H6

#Paragraphs

Each paragraph begins on a new line. Simply press <return> for a new line.

You'll need an empty line between a paragraph and any following markdown construct,
such as an ordered or unordered list, for that to be rendered.

# Character styles

*Italic characters*

_Italic characters_

**bold characters**

__bold characters__

~~strikethrough text~~

#Unordered list

* Item 1
* Item 2
* Item 3
    * Item 3a
    * Item 3b
    * Item 3c

#Ordered list

1. Step 1
2. Step 2
3. Step 3
    a. Step 3a
    b. Step 3b
    c. Step 3c

List in list
1. Step 1
2. Step 2
3. Step 3
    * Item 3a
    * Item 3b
    * Item 3c

#Quotes or citations

Introducing my quote:

> Neque porro quisquam est qui
dolorem ipsum quia dolor sit amet,
consectetur, adipisci velit...
Inline code characters
Use the backtick to refer to a `function()`.

There is a literal ``backtick (`)`` here.

#Code blocks

Indent every line of the block by at least 4 spaces or 1 tab.

This is a normal paragraph:

    This is a code block.
    With multiple lines.

Alternatively, you can use 3 backtick quote marks before and after the block, like this:

```
This is a code block
```

To add syntax highlighting to a code block, add the name of the language immediately
after the backticks:

```javascript
var oldUnload = window.onbeforeunload;
window.onbeforeunload = function() {
    saveCoverage();
    if (oldUnload) {
        return oldUnload.apply(this, arguments);
    }
};
```

Within a code block, ampersands (&) and angle brackets (< and >) are automatically converted into HTML entities.

#Links to external websites

This is [an example](http://www.slate.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.
Linking issue keys to JIRA
When you use JIRA issue keys (of the default format) in comments and pull request descriptions Stash automatically links them to the JIRA instance.

The default JIRA issue key format is two or more uppercase letters ([A-Z][A-Z]+), followed by a hyphen and the issue number, for example STASH-123.

#Images
Inline image syntax looks like this:

![Fail to load](/path/to/image.jpg)
![Fail to load](/2015-NCTU-training-camp/Screenshot.png)
![Alt text](/2015-NCTU-training-camp/Screenshot.png "Hello World")
![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/a/aa/Logo_Google_2013_Official.svg/250px-Logo_Google_2013_Official.svg.png)

# Tables

| Day     | Meal    | Price |
| --------|---------|-------|
| Monday  | pasta   | $6    |
| Tuesday | chicken | $8    |

#Backslash escapes

Certain characters can be escaped with a preceding backslash to preserve the literal display of a character instead of its special Markdown meaning. This applies to the following characters:

\  backslash

`  backtick

*  asterisk

_  underscore

{} curly braces

[] square brackets

() parentheses

#  hash mark

>  greater than

+  plus sign

-  minus sign (hyphen)

.  dot

!  exclamation mark
