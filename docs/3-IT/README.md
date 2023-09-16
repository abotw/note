# IT

## ToDos

**课程**

-   [CSE-CS102](./3-OS/1-%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%8E%9F%E7%90%86/CSE-CS102/)

-   [Web 开发综合实训](./1-SD/09-Web/WDCPT/)
-   [Python 程序设计](./1-SD/02-PL/Python/python-programming/)

## `Hello, world!`

-   [Hello World @Github](https://github.com/leachim6/hello-world) - Hello world in every computer language.
-   [The Hello World Collection](http://helloworldcollection.de/)
-   [Hello World In Many Programming Languages](https://wiki.c2.com/?HelloWorldInManyProgrammingLanguages)
-   [Hello world/Text](https://rosettacode.org/wiki/Hello_world/Text)

=== "C"

    ``` c linenums="1" hl_lines="4"
    #include <stdio.h>
    
    int main(void) {
      printf("Hello World!\n");
      return 0;
    }
    ```
    
    1.  `#include <stdio.h>`:
        -   This line is {==***a preprocessor directive***==} that tells the C compiler to include the standard input/output library (stdio.h) in your program. This library provides functions for input and output operations.
    2.  `int main(void) {`:
        -   This line is the start of the `main`  function, which is {==***the entry point***==} for every C program. Here's what each part of this line means:
            -   `int`: This is {==***the return type***==} of the `main` function. It specifies that the function will return an integer.
            -   `main`: This is the name of the function.
            -   `void`: This specifies that the `main` function takes no arguments. It means it doesn't expect any input values from the command line.
    3.  `{` and `}`:
        -   These curly braces define the beginning and end of the `main` function's body. All the code inside these braces belongs to the `main` function.
    4.  `printf("Hello World!\n");`:
        -   This line is a function call to `printf`, which is used for formatted output. It prints the text "Hello World!" to the console.
        -   `"Hello World!\n"` is a string literal enclosed in double quotes. It represents the text you want to print.
        -   `"\n"` is {==***an escape sequence***==} representing a newline character, which adds a line break after "Hello World!".
    5.  `return 0;`:
        -   This line is used to exit the `main` function and return a value to the operating system. In this case, it returns an integer value of 0.
        -   A return value of 0 conventionally indicates that the program executed without errors.
    
    Here's how the program works:
    
    -   The `#include <stdio.h>` *directive* includes the standard input/output library.
    -   The `main` function is defined, which is the entry point of the program.
    -   Inside the `main` function, `printf` is called to print "Hello World!" to the console.
    -   The `return 0;` statement exits the `main` function, and the program terminates.
    
    When you compile and run this program, you will see "Hello World!" displayed on the screen, followed by a newline, and the program will exit with a return code of 0.

=== "C++"

    ``` cpp linenums="1" hl_lines="4"
    #include <iostream>
    
    int main(void) {
      std::cout << "Hello World!" << std::endl;
      return 0;
    }
    ```

=== "C#"

    ``` csharp linenums="1" hl_lines="1"
    ```

=== "Python3" 

    ``` py linenums="1" hl_lines="2"
    #!/usr/bin/env python3
    print("Hello World")
    ```
    
    1.  **Shebang Line**:
    
        ```python
        #!/usr/bin/env python3
        ```
    
        -   This is called the {==***"shebang" line***==} or {==***"hashbang" line***==}, and it is used in Unix-like operating systems (such as Linux and macOS) to specify the interpreter that should be used to run the script.
        -   In this case, `#!/usr/bin/env python3` indicates that the script should be executed using the Python 3 interpreter. The `env` command is used to locate the Python 3 interpreter in the system, making the script more portable.
    
    2.  **Comments**:
    
        ```python
        # This is a comment
        ```
    
        -   Comments in Python start with the `#` symbol. They are ignored by the Python interpreter and are used to provide human-readable explanations or documentation within the code.
    
    3.  **Main Code**:
    
        ```python
        print("Hello World")
        ```
    
        -   This is the main part of the code.
        -   `print("Hello World")` is a Python statement that instructs the interpreter to display the text "Hello World" on the standard output (usually the terminal or console).
        -   `print()` is a built-in Python function used for printing text or values to the screen.
        -   `"Hello World"` is a string literal, enclosed in double quotes, representing the text to be printed.
    
    Here's a summary of the keywords and elements used in the code:
    
    -   `#!/usr/bin/env python3`: Shebang line specifying the Python 3 interpreter.
    -   `print()`: A Python built-in function used for displaying text or values.
    -   `"Hello World"`: A string literal, which is the text to be printed.
    -   `#`: Used to indicate comments in the code.

=== "Javascript"

    ``` javascript linenums="1"
    console.log("Hello World");
    document.writeln("Hello, World"); // -- Paul Gresham, 07NOV1999
    alert("Hello, World"); // Pop up
    ```
    
    1.  `console.log("Hello World");`
    
        This line of code uses the `console.log()` {==***method***==} to print the text "Hello World" to the browser's console. The console is a developer tool that allows you to display messages, errors, and other information for debugging purposes. In this case, it simply outputs the text "Hello World" to the console, which can be viewed in the browser's developer tools. This is often used for debugging and logging purposes.
    
    2.  `document.writeln("Hello, World"); // -- Paul Gresham, 07NOV1999`
    
        This line of code uses the `document.writeln()` method to write the text "Hello, World" to the HTML document. The text is added to the document at the current position of the document's content. Additionally, there is a comment included in the code, which is preceded by "//". Comments are not executed by the JavaScript engine and are used for adding explanatory notes to the code. In this case, it mentions the author's name and a date (Paul Gresham, 07NOV1999) as a comment.
    
    3.  `alert("Hello, World"); // Pop up`
    
        This line of code uses the `alert()` function to display a pop-up dialog box with the message "Hello, World." When this line is executed, it will cause a small window to appear in the user's web browser with the specified message. The user typically needs to click an "OK" button to dismiss the dialog. This is often used for providing important messages or alerts to the user.
    
    In summary, the code provided combines three different ways to display the message "Hello, World" in a web browser:
    
    1.  It logs the message to the browser's console for debugging purposes using `console.log()`.
    2.  It writes the message directly to the HTML document using `document.writeln()`.
    3.  It displays a pop-up alert dialog with the message using `alert()`.

=== "Java"

    ``` java title="" linenums="1" hl_lines="3"
    public class Java {
    	public static void main(String[] args) {
    		System.out.println("Hello World");
    	}
    }
    ```
    
    1. `public`: This is {==***an access modifier***==}, which specifies that the class Java can be accessed from anywhere. In Java, there are four access modifiers: `public`, `private`, `protected`, and package-private (default). Here, `public` means that the class is accessible from any other class.
    
    	1. `public`
    	2. `private`
    	3. `protected`
    	4. package-private (default)
    
    2. `class`: This {==***keyword***==} is used to declare a class. In Java, a class is a blueprint for creating objects. The name of the class in this code is "Java."
    
    	1. The program consists of {==***a class declaration***==}, which is declared using the keywords public class. In Java, all code lives inside of classes.
    
    3. `Java`: This is the name of the class. {++Class names in Java should start with an uppercase letter by convention.++}
    
    4. `{ }`: These curly braces define the scope of the class. Everything related to the Java class is enclosed within these curly braces.
    
    5. `public static void main(String[] args) { }`: This is the main method in Java. It is {==***the entry point***==} for the program, and it must be present in every Java application. Let's break down the components of the main method:
    
    	1. `public`: This is *an access modifier*, specifying that the main method can be accessed from anywhere.
    	2. `static`: {++This keyword indicates that the main method belongs to the class itself and not to instances of the class.++}
    	3. `void`: This is {==***the return type***==} of the main method, which means it doesn't return any value.
    	4. `main`: This is the name of the {==***method***==}.
    	5. `String[] args`: This is {==***the parameter list***==} of the main method. It accepts an array of strings as arguments. This is a mechanism for passing command-line arguments to the program.
    
    6. `System.out.println("Hello World");`: This line of code is inside the main method and is responsible for printing "Hello World" to the console.
    
    	1. `System`: This is a built-in class in Java that provides access to the standard input, output, and error streams.
    	2. `out`: This is {==***a static member (object)***==} of the System class that represents the standard output stream.
    	3. `println`: This is {==***a method***==} of the out object that is used to print a line of text to the console.
    	4. `"Hello World"`: This is the string that will be printed to the console. It's enclosed in double quotes to indicate that it's a string literal.
    	
    So, in summary, this Java code defines a class named Java with a main method. When the program is executed, it prints "Hello World" to the console. This is a basic "Hello World" program, often used as the first example when learning a new programming language to ensure that the development environment is set up correctly.

---

=== "JSP"

    ``` jsp linenums="1" hl_lines="6"
    <%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title>Hello World JSP</title>
    </head>
    <body>
        <h1>Hello, World!</h1>
    </body>
    </html>
    ```
    
    1.  `<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>`: This is a JSP {==***directive***==}. It tells {==***the JSP engine***==} that you're using Java as {==***the scripting language***==}, sets the content type to HTML with UTF-8 encoding, and specifies the character encoding for the page.
    2.  `<!DOCTYPE html>`: This is {==***the document type declaration***==} for an HTML5 document. It defines the document type and version.
    3.  `<html>`: This is {==***the opening tag***==} for the HTML document.
        `</html>`: This closes the HTML document.
    4.  `<head>`: This is the head section of the HTML document, where you typically include metadata and links to external resources like stylesheets or scripts.
        `</head>`: This closes the head section.
    5.  `<meta charset="UTF-8">`: This {==***meta tag***==} specifies the character encoding of the document, which is set to UTF-8 to support a wide range of characters.
    6.  `<title>Hello World JSP</title>`: This is the title of the HTML document, which appears in the browser's title bar or tab.
    7.  `<body>`: This is the body section of the HTML document, where you put the visible content of your web page.
        `</body>`: This closes the body section.
    8.  `<h1>Hello, World!</h1>`: This is an HTML heading element (`<h1>`) containing the text "Hello, World!" It's the main content of your web page.

## Hello Numbers

=== "Java"

    ``` java title="HelloNumbers.java" linenums="1"
    public class HelloNumbers {
        public static void main(String[] args) {
            int x = 0;
            while (x < 10) {
                System.out.print(x + " ");
                x = x + 1;
            }
        }
    }
    ```
    
    ``` sh title="output"
    $ javac HelloNumbers.java
    $ java HelloNumbers
    $ 0 1 2 3 4 5 6 7 8 9 %
    ```
    
    Some interesting features of this program that might jump out at you:
    
    -   Our variable x must be declared before it is used, *and it must be given a type!*
    -   Our loop definition is contained inside of curly braces, and the boolean expression that is tested is contained inside of parentheses.
    -   Our print statement is just `System.out.print` instead of `System.out.println`. This means we should not include a newline (a return).
    -   Our print statement adds a number to a space. This makes sure the numbers don't run into each other. Try removing the space to see what happens.
    -   When we run it, our prompt ends up on the same line as the numbers (which you can fix in the following exercise if you'd like).

## FizzBuzz

-   [FizzBuzz @Github](https://github.com/zenware/FizzBuzz) - FizzBuzz in every programming language.

## one-two-three...infinity

-   [one-two-three...infinity @Github](https://github.com/clarkzjw/one-two-three...infinity) - Calculating the **sum** from one to a billion in different programming languages.

## Running a Program

=== "Java"

    ![java_compilation_figure](https://joshhug.gitbooks.io/hug61b/content/assets/compilation_figure.svg)
    
    ``` sh
    $ javac HelloWorld.java
    $ java HelloWorld
    Hello World! 
    ```
    
    -   [Java bytecode](https://en.wikipedia.org/wiki/Java_bytecode)

## Comments

=== "Java"

    -   Line comments in Java: the `//` delimiter. 
    -   Block (a.k.a. multi-line comments) comments use `/*` and `*/`.

-   [Javadoc](https://docs.oracle.com/javase/8/docs/technotes/tools/windows/javadoc.html), [the Javadoc format @wikipedia](https://en.wikipedia.org/wiki/Javadoc)
    In a Javadoc comment, the block comment starts with an extra asterisk, e.g. `/**`, and the comment often (but not always) contains descriptive tags.

## Code Style

=== "Java"

		-   [ ] [Style Guide @CS61B](https://sp19.datastructur.es/materials/guides/style-guide.html)
