# JSP

-   [ ] [JAVASERVER PAGES™ (JSP™) SYNTAX version 1.1](https://www.oracle.com/technetwork/java/card11-150221.pdf)
-   [ ] [JavaWeb学习速查表](https://ns96.com/2017/09/21/jsp-Cheat-sheet)
-   [ ] [JSP入门基础知识详细版（通俗易懂）](https://www.cnblogs.com/ideal-20/p/11475803.html)
-   [ ] [JSP简介](http://www.monkey1024.com/javaweb/941)

**Include Directive**

Includes a static file, parsing the file’s JSP elements.

``` jsp
<%@ include file="relativeURL" %>
```

**Page Directive**

Defines attributes that apply to an entire JSP page.

``` jsp
<%@ page [ language="java" ] [ extends="package.class" ] [ import="{package.class | package.*} , ... " ]
[ session="true|false" ] [ buffer="none|8kb|sizekb" ] [ autoFlush="true|false" ]
[ isThreadSafe="true|false" ] [ info="text" ] [ errorPage="relativeURL" ]
[ contentType="{mimeType [ ; charset=characterSet ] | text/html ; charset=ISO-8859-1}" ]
[ isErrorPage="true|false" ] %>
```

**Expression**

Contains an expression valid in the page scripting language.

``` jsp
<%= expression %>
```

**Scriptlet**

Contains a *code fragment* valid in the page scripting language.

``` jsp
<% code fragment of one or more lines %>
```