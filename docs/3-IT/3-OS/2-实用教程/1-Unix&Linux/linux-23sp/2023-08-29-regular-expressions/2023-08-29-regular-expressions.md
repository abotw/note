# Regular Expressions

![](https://imgs.xkcd.com/comics/regular_expressions.png)

## 0. Definitions

In formal language theory, a regular expression (a.k.a. regex, regexp, or r.e.), is a string that represents a [regular (type-3) language](http://en.wikipedia.org/wiki/Regular_language).

Huh??

Okay, in many programming languages, a regular expression is a **pattern** that **matches** strings or pieces of strings. *The set of strings they are capable of matching goes way beyond what regular expressions from language theory can describe.*

---

-   a sophisticated language to describe different *patterns of text*.
-   special 'patterns' which describe text

When we are matching text, we match a set of characters a number of times.

## 1. Basic Examples

## Using Regular Expressions

!!! abstract

    -   **Validate**, validation
    -   **Find**
    -   **Extract**, extraction
    -   **Replace**, replacement

Many languages allow programmers to define regexes and then use them to:

-   **Validate** that a piece of text (or a portion of that text) matches some pattern
-   **Find** fragments of some text that match some pattern
-   **Extract** fragments of some text
-   **Replace** fragments of text with other text

Generally a regex is first **compiled** into some internal form that can be used for super fast validation, extraction, and replacing. Sometimes there is an explicit `compile` function or method, and sometimes special syntax is used to compile, such as the very common form `/.../`.

### Validation

**Example: find `"color"` or `"colour"` in a given string.**

=== "js"

    ``` js
    // JavaScript
    const p = /colou?r/;
    "The color green".search(p);        // returns 4
    "abc".search(p);                    // returns -1
    ```

=== "python"

    ``` py
    # Python
    p = re.compile("colou?r")
    m = p.search("The color green")
    m.start()                           # returns 4
    m = p.search("abc")                 # returns None
    ```

=== "java"

    ``` java
    // Java
    Pattern p = Pattern.compile("colou?r");
    Matcher m = p.matcher("The color green");
    m.find();                           // returns true
    m.start();                          // returns 4
    m.end();                            // returns 9
    m = p.matcher("abc");
    m.find();                           // returns false
    ```

### Extraction

=== "Javascript"

    ``` javascript
    > const pattern = /weighs (\d+(\.\d+)?) (\w+)/
    > pattern.exec('The thing weighs 2.5 kilograms or so.')
    [ 'weighs 2.5 kilograms',
      '2.5',
      '.5',
      'kilograms',
      index: 10,
      input: 'The thing weighs 2.5 kilograms or so.' ]
    ```

---

=== "Javascript"

    ``` javascript
    > const r = /((\d{3})(?:\.|-))?(\d{3})(?:\.|-)(\d{4})/g;
    > const m = r.exec("Call 1.800.555-1212 for info");
    > m.index
    7
    > JSON.stringify(m);
    ["800.555-1212","800.","800","555","1212"]
    ```



### Substitution, Replacement 替换

=== "js"

  ``` js
  alert("Rascally Rabbit".replace(/[RrLl]/g, "w"));
  ```

## Components of Regexes

### Character Classes

!!! abstract

    -   metacharacter - 元字符序列
    -   character set - 字符集
    -   POSIX character set - POSIX 字符集
    -   特殊字符序列



| Notation              | Meaning                                                      | Example                                                     |
| --------------------- | ------------------------------------------------------------ | ----------------------------------------------------------- |
| `[ ]` square brackets | means exactly one character                                  | `[abc]` - a or b or c                                       |
| `^`                   | a leading `^` negates                                        | `[^abc]` - any character _except_ a, b, or c (negation)     |
| `-`                   | a non-leading, non-terminal `-` defines a range              | `[a-zA-Z]` -  a through z or A through Z, inclusive (range) |
| `\`                   | If you have a `]` in your set, put it first. Use `\` to escape | -                                                           |

---



-   the character range

A metacharacter is a special character which is used to represent a range of characters. 

| Quantifier | Meaning                                       |
| ---------- | --------------------------------------------- |
| `.`        | Any character except for a line break.        |
| `\w`       | Any 'word' character, `[a-zA-Z0-9_]`.         |
| `\W`       | Any non 'word' character.                     |
| `\s`       | Any 'whitespace' character (space, tab, etc). |
| `\S`       | Any non 'whitespace' character.               |
| `\d`       | Any 'digit' character `[0-9]`.                |
| `\D`       | Any non 'digit' character.                    |

---

#### 逻辑关系

`^`

a whitespace character

 none-whitespace character

-   special characters
    -   square brackets
    -   the circumflex symbol
    -   the plus sign

If there is ever a point at which you need to use a special character in a regular expression as a *literal* character, escape it by putting a slash in front of it.

### Groups 分组

-   Capture Groups

### Quantifiers 量词

| Eager                       | Reluctant | Possessive |          |
| --------------------------- | --------- | ---------- | -------- |
| Zero or one                 | `?`       | `??`       | `?+`     |
| Zero or more                | `*`       | `*?`       | `*+`     |
| One or more                 | `+`       | `+?`       | `++`     |
| m times                     | `{m}`     | `{m}?`     | `{m}+`   |
| At least m times            | `{m,}`    | `{m,}?`    | `{m,}+`  |
| At least m, at most n times | `{m,n}`   | `{m,n}?`   | `{m,n}+` |

| Quantifier | Meaning                                              |
| ---------- | ---------------------------------------------------- |
| `*`        | Any number of characters.                            |
| `+`        | At least one character.                              |
| `?`        | Between zero and one character.                      |
| `{10}`     | Exactly ten occurrences of the character.            |
| `{10,}`    | Ten or more occurrences of the character.            |
| `{10,20}`  | Between ten and twenty occurrences of the character. |

#### Lazy and Greedy Expressions

``` sh
<.+>
<.+?> = <[^>]+>
```

### Backreferences

### Anchors, Boundaries, Delimiters 边界

Some regex tokens do not consume characters! They just assert the matching engine is at a particular place, so to speak.

-   `\A`: Beginning of string
-   `\z`: End of string
-   `\Z`: Varies a lot depending on the engine, so be careful with it

Also, the lookarounds (up next!) don’t consume any characters either!

| 符号             | Meaning 描述                                                 | 例子     | 能匹配   | 不能匹配 |
| :--------------- | :----------------------------------------------------------- | :------- | :------- | :------- |
| `^` (circumflex) | Beginning of string (or line, depending on the mode)<br />字符串首或行首 | `^yo`    | yo       | ayo      |
| `$` (dollar)     | End of string (or line, depending on the mode)<br />字符串尾或行尾 | `yo$`    | yo       | yop      |
| `\b`             | Word boundary<br />单词边界                                  | `\byo\b` | mu yo mu | muyomu   |
| `\B`             | Not a word boundary<br />非单词边界                          | `\Byo\B` | muyomu   | mu yo mu |

---

-   [ ] [Regex Anchors @ RexEgg](https://www.rexegg.com/regex-anchors.html)

### Lookarounds

### Modifiers 模式修饰符

| Modifier | Meaning                                                      |
| -------- | ------------------------------------------------------------ |
| `g`      | global                                                       |
| `i`      | ignore case                                                  |
| `m`      | multiple line                                                |
| `s`      | single line (DOTALL): Means that the dot matches any character at all. Without this modifier, the dot matches any character except a newline. |
| `x`      | ignore whitespace in the pattern                             |
| `d`      | Unix line mode: Considers only U+000A as a line separator, rather than U+000D or the U+000D/U+000A combo or even U+2028. |
| `u`      | Unicode case: in this mode the case-insensitive modifier respects Unicode cases; outside of this mode that modifier only consolidates cases of US-ASCII characters. |

## Miscellaneous Language-Specific Notes

=== "Javascript"

	-   [正则表达式 @ javascript.info](https://zh.javascript.info/regular-expressions)

## Study & Practice, Supplemental materials

**Cheatsheets**

-   [正则表达式速查卡](https://twitter.com/linuxtoy/status/1597754607697948673?s=20&t=8Zw319a3CXTFSMzMZr5Xxw) @ [selfhostedserver.com](https://selfhostedserver.com/)

-   [ ] https://biaoyansu.com/28.cheatsheet


**tools**

-   [regex101.com](https://regex101.com/)
-   [regexr.com](https://regexr.com/)
-   [iHateRegex](https://ihateregex.io/)

可视化工具

-   [regexper](https://regexper.com/)
-   [debuggex.com](https://www.debuggex.com/)

**posts**

-   [ ] [Regular Expressions @ cs.lmu.edu](https://cs.lmu.edu/~ray/notes/regex/)
-   [ ] [Regex Essentials @ effective-shell.com](https://effective-shell.com/part-3-manipulating-text/regex-essentials/)
-   [ ] [Regex cheatsheet](https://remram44.github.io/regex-cheatsheet/regex.html)
-   [ ] https://www.regular-expressions.info/quickstart.html
-   [ ] https://abotw.notion.site/CheatSheet-e6aa0e71db93461680d1bf311498a00b?pvs=4

**The matching engine, 正则引擎**