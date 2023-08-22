# Chapter 01

``` c title="The first C program"
#include <stdio.h> /* (1) */

main() /* (2) */
{ /* (3) */
    printf("hello, world\n"); /* (4) */
}
```

1.   include information about standard library
2.   define a function called `main` that received no argument values
3.   statements of main are enclosed in braces
4.   `main` calls library function `printf` to print this sequence of characters, `\n` represents the newline character

``` sh
cc hello.c
```

??? note "cc"

    ``` sh
    $ curl cheat.sh/cc
    # cc
    # This command is an alias of `gcc`.
    # More information: <https://gcc.gnu.org>.
    
    # View documentation for the original command:
    tldr gcc
    
    $
    ```

``` c title="Temperature Converter 1st Edition - Temperature conversion program"
#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
main()
{
  	int fahr, celsius;
  	int lower, upper, step;
  
  	lower = 0;			/* lower limit of temperature scale */
  	upper = 300;		/* upper limit */
  	step = 20;			/* step size */
  
  	fahr = lower;
  	while (fahr <= upper) {
      	celsius = 5 * (fahr - 32) / 9;
      	printf("%d\t%d\n", fahr, celsius);
     		fahr = fahr + step;
    }
}
```

``` c title="Temperature Converter 2nd Edition - Temperature conversion program"
#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version */
main()
{
		float fahr, celsius;
		float lower, upper, step;
  
		lower = 0; 			/* lower limit of temperatuire scale */
		upper = 300; 		/* upper limit */
		step = 20; 			/* step size */
  
		fahr = lower;
		while (fahr <= upper) {
				celsius = (5.0 / 9.0) * (fahr - 32.0);
				printf("%3.0f %6.1f\n", fahr, celsius);
				fahr = fahr + step;
		}
}
```

``` c title="The for statement"
#include <stdio.h>

/* print Fahrenheit-Celsius table */
main()
{
  	int fahr;
  	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
      	printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```

``` c
#include <stdio.h>

#define		LOWER		0			/* lower limit of table */
#define		UPPER		300		/* upper limit */
#define		STEP		20		/* step size */

/* print Fahrenheit-Celsius table */
main()
{
  	int fahr;
  	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
      	printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```



### functions & variables

-   ***function*** (subroutine, procedure)
    
    -   *statements* - specify **the computing operations** to be done.
        
        Individual statements are terminated by semicolons.
        The statements of a function are enclosed in braces `{ }`.
        A single statement without braces.
        
        -   *assignment statements* - which set the *variables* to their initial values
-   ***variable*** - store values used during the computation

---

>   A C program, whatever its size, consists of ***functions*** and ***variables***. A function contains ***statements*** that specify **the computing operations** to be done, and variables store values used during the computation. C functions are like the **subroutines** and functions in Fortran or the **procedures** and functions of Pascal. 

---

>   A ***function*** is called by naming it, followed by a parenthesized list of ***arguments***.

---

>   The ***condition*** in parentheses is tested.
>
>   ***The body of the loop*** (the statements enclosed in braces)

#### Variables 变量

>   In C, all ***variables*** must be declared before they are used, usually at the beginning of the *function* before any executable *statements*. 

#### 函数间数据通信

`the calling function`
: 主调用函数

`the function it calls`
: 被调用函数

`argument`
: 参数

>   One method of communicating data between functions is for **the calling function** to provide a list of values, called ***arguments***, to **the function it calls**.

#### `main`

>   Our example is a function named main. Normally you are at liberty to give functions whatever names you like, but `main` is special - **your program begins executing at the beginning of main. This means that every program must have a main somewhere.**

#### `printf`

>   `printf` is **a library function** that prints output.

>   `printf` never supplies a *newline character* automatically.

>   `printf` is a general-purpose **output formatting function**. Its first argument is *a string of characters* to be printed, with each `%` indicating where one of the other (second, third, ...) arguments is to be substituted, and in what form it is to be printed. For instance, `%d` specifies an integer argument, so the statement `printf("%d\t%d\n", fahr, celsius);` causes the values of the two integers `fahr` and `celsius` to be printed, with a tab (`\t`) between them.

`%`

: Each `%` **construction** in the first *argument* of `printf` is paired with the corresponding second *argument*, third *argument*, etc.; they must match up properly by number and type, or you will get wrong answers.

`3`

: Augmenting with a width, three digits wide, the numbers printed will be right-justified in their fields.

`d`

: decimal

>   `printf` also recognizes `%o` for **octal**, `%x` for **hexadecimal**, `%c` for **character**, `%s` for **character string** and `%%` for itself.

>   The `printf` **conversion specification** `%3.0f` says that a floating-point number (here `fahr`) is to be printed at least **three characters wide**, with **no decimal point** and no **fraction digits**. `%6.1f` describes another number (`celsius`) that is to be printed **at least six characters wide**, with 1 digit after the decimal point.

>   *Width* and *precision* may be omitted from a *specification*: `%6f` says that the number is to be at least six characters wide; `%.2f ` specifies two characters after the decimal point, but the width is not **constrained**; and `%f` merely says to print the number as floating point. 

|         |                                                              |
| ------- | ------------------------------------------------------------ |
| `%d`    | print as **d**ecimal integer                                 |
| `%6d`   | print as decimal integer, at least 6 characters wide         |
| `%f`    | print as floating point                                      |
| `%6f`   | print as floating point, at least 6 characters wide          |
| `%.2f`  | print as floating point, 2 characters after decimal point    |
| `%6.2f` | print as floating point, at least 6 wide and 2 after decimal point |

### The standard library (Chapter 7 & Appendix B)

-   `<stdio>` - The **st**an**d**ard **i**nput/**o**utput library.
    -   `printf` -  A function from **the standard library of functions** that are normally accessible to C programs.

---

`character string`

: 字符串

`string constant`

: 字符串常量

>   A sequence of characters in double quotes, like `"hello, world\n"`, is called a ***character string*** or ***string constant***.

---

### C notation

#### escape sequence 转义字符序列

>   Notice that `\n` represents only a single character. An ***escape sequence*** like `\n` provides a general and extensible mechanism **for representing hard-to-type or invisible characters**. Among the others that C provides are `\t` for tab, `\b` for backspace, `\"` for the double quote and `\\` for the backslash itself. 

#### newline character

>   The sequence `\n` in the string is **C notation** for the ***newline character***, **which when printed advances the output to the left margin on the next line.**

There is a complete list in Section 2.3.

### Arithmetic Expressions

Formula: $Celsius = (5 / 9) (Fahrenheit - 32)$

-   Fahrenheit temperatures
-   centigrade or Celsius equivalents

### Comment

>   A ***comment***, which explains briefly what the program does. Any characters between `/*` and `*/` are ignored by the compiler; they may be used freely to make a program easier to understand. 
>
>   Comments may appear anywhere where a blank, tab or newline can.

### Declaration

>   A ***declaration*** announces the properties of variables; it consists of a name and a list of variables.

### Data Types 数据类型

>   The type `int` means that the variables listed are **integers**; by contrast with `float`, which means **floating point**, i.e., numbers that may have a fractional part.
>
>   The range of both `int` and `float` depends on the machine you are using.
>
>   The size of these objects is also machine-dependent.

| `int`s  | range                                            |
| ------- | ------------------------------------------------ |
| 16-bits | [-32768, +32767], [2^16/2, 2^16/2 - 1]           |
| 32-bits | [-2147483648, +2147483647], [2^32/2, 2^32/2 - 1] |

>   A ***float*** number is typically a 32-bit quantity, with at least six **significant digits 有效数字** and **magnitude** generally between about $10^{-38}$ and $10^{+38}$.

| Date type | Explanation                     |
| --------- | ------------------------------- |
| `char`    | character - a single byte       |
| `short`   | short integer                   |
| `long`    | long integer                    |
| `double`  | double-precision floating point |

>   There are also ***arrays***, ***structures*** and ***unions*** of these basic types, ***pointers*** to them, and ***functions*** that return them, all of which we will meet in due course.

### Computation

### Indentation

>   The ***indentation*** emphasizes **the logical structure of the program.**
>
>   Although C *compilers* do not care about how a program looks, proper *indentation* and spacing are critical in making programs **easy for people to read**.

### Style

>   We recommend **writing only one statement per line**, and using blanks around operators to clarify grouping.

---

### truncate 舍位

>   **Integer division** ***truncates***: any fractional part is discarded.

>   If an **arithmetic operator** has **integer operands**, an **integer operation** is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the integer will be converted to floating point before the operation is done.

>   Writing **floating-point constants** with **explicit decimal points** even when they have **integral values** emphasizes their floating-point nature for human readers.

### Standard

-   the **ANSI standard**

### the for statement

>   *The `for` statement* is a *loop*, a **generalization** of the `while`. If you compare it to the earlier `while`, its operation should be clear. 
>
>   Within the parentheses, there are three parts, separated by semicolons. 
>
>   -   The first part, the initialization `fahr = 0` is done once, before the *loop* proper is entered. 
>
>   -   The second part is the test or condition that controls the *loop*: `fahr <= 300.` This condition is evaluated; if it is true, the body of the *loop* (here a single `ptintf`) is executed. 
>
>   -   Then the increment step `fahr = fahr + 20` is executed, and the condition re-evaluated. The *loop* terminates if the condition has become false. As with the while, the body of the *loop* can be a single statement or a group of statements enclosed in braces. 
>
>   The *initialization*, *condition* and *increment* can be any expressions.

## 1.4 Symbolic Constants

One way to deal with ***magic numbers*** is to give them meaningful names. A **`#define` line** defines a ***symbolic name*** or ***symbolic constant*** to be a particular string of characters:

``` c
#define name replacement list
```

**Thereafter**, any **occurrence** of ***name*** (not in quotes and not part of another name) will be replaced by the corresponding ***replacement text***. 

-   The ***name*** has the same form as a variable name: a sequence of letters and digits that begins with a letter. 
-   The ***replacement text*** can be any sequence of characters; it is not limited to numbers.

Symbolic constant names are conventionally written in upper case so they can be readily distinguished from lower case variable names. Notice that there is no semicolon at the end of a **`#define` line**.

## 1.5 Character Input and Output

We are going to consider <u>a family of related programs</u> for **processing character data**. You will find that many programs are just <u>expanded versions of the prototypes</u> that we discuss here.

The model of input and output supported by *the standard library* is very simple. Text input or output, <u>regardless of</u> where it originates or where it goes to, is dealt with as <u>streams of characters</u>. A ***text stream*** is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character. It is the responsibility of the library to make each input or output stream <u>confirm this model</u>; the C programmer using the library need not worry about how lines are represented outside the program.

![The standard streams for input, output, and error](https://upload.wikimedia.org/wikipedia/commons/7/70/Stdstreams-notitle.svg)

*The standard library* provides several functions for reading or writing one character <u>at a time</u>, of which `getchar` and `putchar `are the simplest. Each time it is called, `getchar` reads the ***next input character*** from a *text stream* and returns that as its value. That is, after

``` c
c = getchar();
```

the variable `c` contains the next character of input. The characters normally come from the keyboard; input from files is discussed in Chapter 7.

The function `putchar` prints a character each time it is called:

``` c
putchar(c);
```

prints the contents of the <u>integer variable</u> `c` as a character, usually on the screen. Calls to `putchar` and `printf` may be <u>interleaved</u>; the output will appear in the order in which the calls are made.

---

-   [ ] [EOF是什么？](https://www.ruanyifeng.com/blog/2011/11/eof.html)

### 1.5.1 File Copying

Given `getchar` and `putchar`, you can write a surprising amount of useful code without knowing anything more about input and output. The simplest example is a program that copies its input to its output one character at a time:

```
read a character
	while (charater is not end-of-file indicator)
		output the character just read
		read a character
```

Converting this into C gives:

``` c
#include <stdio.h>

/* copy input to output; 1st version */
main()
{
  	int c;
  
  	c = getchar();
  	while (c != EOF) {
      	putchar(c);
      	c = getchar();
    }
}
```

The ***relational operator*** `!=` means "not equal to".

What <u>appears to be a character</u> on the keyboard or screen is of course, like everything else, stored internally just as a <u>bit pattern</u>. The type `char` is specifically meant for storing such character data, but any integer type can be used. We used `int` for a <u>subtle</u> but important reason.

The problem is distinguishing the end of input from valid data. The solution is that `getchar` returns a <u>distinctive</u> value when there is no more input, a value that cannot be confused with any real character. **This value is called `EOF`, for "end of file".** We must declare `c` to be a type big enough to hold any value that `getchar` returns. We can't use `char` since `c` must be big enough to hold `EOF` <u>in addition to any possible `char` 除了能存储任何可能的字符外</u>. Therefore we use `int`.

{==`EOF` is an integer defined in `<stdio.h>, but the specific numeric value doesn't matter as long as it is not the same as any char value.==} By using the ***symbolic constant***, we are <u>assured that</u> nothing in the program depends on the specific numeric value.

The program for copying would be written more concisely by experienced C programmers. {==In C, any assignment, such as `c = getchar();` is an expression and has a value, which is the value of the <u>left hand side</u> after the assignment.==}

This means that a assignment can appear as part of a larger expression. If the assignment of a character to `c` is put inside the test part of a while loop, the copy program can be written this way:

``` c
#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
  	int c;
  	while((c = getchar()) != EOF)
      	putchar(c);
}
```

The `while` gets a character, assigns it to `c`, and then tests whether the character was ***the end- of-file signal***. If it was not, the body of the `while` is executed, printing the character. The `while` then repeats. When the end of the input is finally reached, the `while` terminates and so does `main`.

This version <u>centralizes the input</u> - there is now only one reference to `getchar` - and <u>shrinks the program</u>. The resulting program is more compact, and, once <u>the idiom is mastered</u>, easier to read. You'll see this style often. (It's possible to <u>get carried away</u> and create <u>impenetrable code</u>, however, a <u>tendency</u> that we will try to <u>curb</u>.)

The parentheses around the assignment, within the condition are necessary. The ***precedence*** of `!=` is higher than that of `=`, which means that in the absence of parentheses the relational test `!=` would be done before the assignment `=`. So the statement `c = getchar() != EOF` is equivalent to `c = (getchar() != EOF)`.

This has the undesired effect of setting `c` to 0 or 1, depending on whether or not the call of `getchar` returned end of file. (More on this in Chapter 2.)

### 1.5.2 Character Counting

The next program <u>counts characters</u>; it is similar to the copy program.

``` c title="Character Counting"
#include <stdio.h>

/* count characters in input; 1st version */
main()
{
  	long nc;
  
  	nc = 0;
  	while (getchar() != EOF)
      	++nc;
  	printf("%ld\n", nc);
}
```

The statement

``` c
++nc;
```

presents a new *operator*, `++`, which means ***increment by one***. You could instead write `nc = nc + 1` but `++nc` is more concise and often more efficient. There is a corresponding operator `--` to ***decrement by 1***. The operators `++` and `--` can be either ***prefix operators*** (`++nc`) or ***postfix operators*** (`nc++`); these two forms have different values in expressions, as will be shown in Chapter 2, but `++nc` and `nc++` both increment `nc`. For the moment we will will stick to the prefix form.

The character counting program <u>accumulates</u> its count in a long variable instead of an `int`. long integers are at least 32 bits. Although on some machines, `int` and `long` are the same size, on others an `int` is 16 bits, with a maximum value of 32767, and <u>it would take relatively little input to overflow an `int` counter</u>. The *conversion specification* `%ld` tells `printf` that the corresponding argument is a long integer.

It may be possible to cope with even bigger numbers by using a `double` (double precision float). We will also use a `for `statement instead of a `while`, to illustrate another way to write the loop.

``` c
#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
		double nc;
  	for (nc = 0; gechar() != EOF; ++nc)
      	;
  	printf("%.0f\n", nc);
}
```

**`printf` uses `%f` for both float and double**; `%.0f` <u>suppresses</u> the printing of the decimal point and the fraction part, which is zero.

The body of this `for` loop is empty, because all the work is done in the test and increment parts. But the grammatical rules of C require that a `for` statement have a body. The <u>isolated</u> semicolon, called a ***null statement***, is there to satisfy that requirement. We put it on a separate line to make it visible.

Before we leave the character counting program, observe that if the input contains no characters, the `while` or `for` test fails on the very first call to `getchar`, and the program produces zero, the right answer. This is important. One of the nice things about `while` and `for` is that they test at the top of the loop, before <u>proceeding with</u> the body. If there is nothing to do, nothing is done, even if that means never going through the loop body. Programs should act intelligently when given zero-length input. The `while` and `for` statements help ensure that programs do reasonable things with <u>boundary conditions</u>.

### 1.5.3 Line Counting

The next program counts **input lines**. As we mentioned above, *the standard library* ensures that an *input text stream* appears as a sequence of lines, each terminated by a newline. Hence, counting lines is just counting newlines:

``` c
#include <stdio>

/* count lines in input */
main()
{
  	int c, nl;
  
  	nl = 0;
  	while ((c = getchar()) != EOF)
      	if (c == '\n')
          	++nl;
  	printf("%d\n", nl);
}
```

The body of the `while` now consists of an `if`, which <u>in turn</u> controls the increment `++nl`. The `if` statement tests the <u>parenthesized</u> condition, and if the condition is true, executes the statement (or group of statements in braces) that follows. We have again indented to show what is controlled by what.

The ***double equals sign*** `==` is the ***C notation*** for "is equal to" (like Pascal's single = or Fortran's .EQ.). This symbol is used to distinguish the <u>equality test</u> from the single `=` that C uses for assignment. <u>A word of caution</u>: newcomers to C occasionally write `=`  when they mean `==`. As we will see in Chapter 2, the result is usually a <u>legal expression</u>, so you will get no warning.

A character written between single quotes represents an integer value equal to the numerical value of the character in the ***machine's character set***. This is called a ***character constant***, although it is just another way to write a small integer. So, for example, 'A' is a *character constant*; in the ***ASCII character set*** its value is 65, the internal representation of the character A. Of course, 'A' is to <u>be preferred over</u> 65: its meaning is obvious, and it is independent of a particular character set.

The escape sequences used in string constants are also legal in character constants, so '\n' stands for the value of the newline character, which is 10 in ASCII. You should note carefully that '\n' is a single character, and in expressions is just an integer; on the other hand, '\n' is a string constant that happens to contain only one character. The topic of strings <u>versus</u> characters is discussed further in Chapter 2.

### 1.5.4 Word Counting

**The fourth** in our series of useful programs counts lines, words, and characters, with the loose definition that a word is any sequence of characters that does not contain a blank, tab or newline. This is <u>a bare-bones version</u> of the UNIX program `wc`.

??? note "wc"

    ``` sh
     tldr:wc 
    # wc
    # Count lines, words, and bytes.
    # More information: <https://www.gnu.org/software/coreutils/wc>.
    
    # Count all lines in a file:
    wc --lines path/to/file
    
    # Count all words in a file:
    wc --words path/to/file
    
    # Count all bytes in a file:
    wc --bytes path/to/file
    
    # Count all characters in a file (taking multi-byte characters into account):
    wc --chars path/to/file
    
    # Count all lines, words and bytes from `stdin`:
    find . | wc
    
    # Count the length of the longest line in number of characters:
    wc --max-line-length path/to/file
    ```

``` c
#include <stdio.h>

#define IN 1		/* inside a word */
#define OUT 0		/* outside a word */

/* count lines, words, and characters in input */
main()
{
  	int c, nl, nw, nc, state;
  
  	state = OUT;
  	nl = nw = nc = 0;
  	while ((c = getchar()) != EOF) {
      	++nc;
      	if (c == '\n')
          	++nl;
      	if (c == ' ' || c == '\n' || c = '\t')
          	state = OUT;
      	else if (state == OUT) {
          	state = IN;
          	++nw;
        }
    }
  	printf("%d %d %d\n", nl, nw, nc);
}
```

Every time the program encounters the first character of a word, it counts one more word. The variable `state` records whether the program is currently in a word or not; initially it is "not in a word", which is assigned the value `OUT`. We prefer the ***symbolic constants*** `IN` and `OUT` to the ***literal values*** 1 and 0 because they make the program more readable. In a program as tiny as this, it makes little difference, but in larger programs, the increase in clarity is well worth the <u>modest extra effort</u> to write it this <u>way from the beginning</u>. You'll also find that it's easier to make extensive changes in programs where ***magic numbers*** appear only as ***symbolic constants***.

The line

``` c
nl = nw = nc = 0;
```

sets all three variables to zero. This is not a special case, but <u>a consequence of the fact</u> that an assignment is an expression with the value and assignments associated from right to left. It's as if we had written

``` c
nl = (nw = (nc = 0));
```

The operator `||` means OR, so the line

``` c
if (c == ' ' || c == '\n' || c = '\t')
```

says "if `c` is a blank *or* `c` is a newline *or* `c` is a tab". (Recall that the escape sequence `\t` is a visible representation of the tab character.) **There is a corresponding operator `&&` for AND; its precedence is just higher than `||`**. Expressions connected by `&&`or `||` are evaluated left to right, and it is guaranteed that evaluation will stop as soon as the truth or <u>falsehood</u> is known.

If `c` is a blank, there is no need to test whether it is a newline or tab, so these tests are not made. This isn't particularly important here, but is significant in more complicated situations, as we will soon see.

<u>The example also shows an else</u>, which specifies an alternative action if the condition part of an if statement is false. The general form is

``` c
if (expression)
		statement1
else
  	statement2
```

One and only one of the two statements associated with an if-else is performed. If the *expression* is true, *$statement_1$* is executed; if not, *$statement_2$* is executed. Each *statement* can be a single statement or several in braces. In the word count program, the one after the else is an if that controls two statements in braces.

## 1.6 Arrays

Let us write a program to count the number of occurrences <u>of each digit</u>, <u>of **white space characters (blank, tab, newline)**</u>, and <u>of all other characters</u>. This is <u>artificial</u>, but it permits us to illustrate several aspects of C in one program.

-   white space characters
    -   blank
    -   tap
    -   newline

There are twelve categories of input, so it is convenient to use an array to hold the number of occurrences of each digit, rather than ten individual variables. Here is one version of the program:

``` c
#include <stdio.h>

/* count digits, white space, others */
main()
{
  	int c, i, nwhite, nother;
  	int ndigit[10];
  
  	nwhite = nother = 0;
  	for (i = 0； i < 10; ++ i)
      	ndigit[i] = 0;
  
  	while ((c = getchar()) != EOF)
      	if (c >= '0' && c <= '9')
          	++ ndigit[c - '0'];
  			else if (c == '' || c == '\n' || c == '\t')
          	++ nwhite;
  			else
          	++ nother;
  	
  	printf("digits =");
  	for (i = 0; i < 10; ++ i)
      	printf(" %d", ndigit[i]);
  	printf(", white space = %d, other = %d\n", nwhite, nother);
}
```

The output of this program on itself is

```
digits = 9 3 0 0 0 0 0 0 0 1, white space = 123, other = 345
```

The declaration

``` c
int ndigit[10];
```

declares `ndigit` to be an array of 10 integers. Array subscripts always start at zero in C, so the

elements are ndigit[0], ndigit[1], ..., ndigit[9]. This is reflected in the for loops

that initialize and print the array.

!!! note

		array subscripts = indexes, indices
		
		1D array, 2D array, 3D array
		one-dimensional array, multi dimensional array

A subscript can be any integer expression, which includes integer variables like i, and integer

constants.

This particular program relies on the properties of the character representation of the digits.

For example, the test

if (c >= '0' && c <= '9')

determines whether the character in c is a digit. If it is, the numeric value of that digit is

c - '0'

This works only if '0', '1', ..., '9' have consecutive increasing values. Fortunately, this

is true for all character sets.

By definition, chars are just small integers, so char variables and constants are identical to

ints in arithmetic expressions. This is natural and convenient; for example c-'0' is an integer

expression with a value between 0 and 9 corresponding to the character '0' to '9' stored in c,

and thus a valid subscript for the array ndigit.

The decision as to whether a character is a digit, white space, or something else is made with

the sequence

if (c >= '0' && c <= '9')

++ndigit[c-'0'];

else if (c == ' ' || c == '\n' || c == '\t')

++nwhite;25

else

++nother;

The pattern

if (*condition**1*)

*statement**1*

else if (*condition**2*)

*statement**2*

...

...

else

*statement**n*

occurs frequently in programs as a way to express a multi-way decision. The *conditions* are

evaluated in order from the top until some *condition* is satisfied; at that point the

corresponding *statement* part is executed, and the entire construction is finished. (Any

*statement* can be several statements enclosed in braces.) If none of the conditions is satisfied,

the *statement* after the final else is executed if it is present. If the final else and *statement* are

omitted, as in the word count program, no action takes place. There can be any number of

else if(*condition*)

*statement*

groups between the initial if and the final else.

As a matter of style, it is advisable to format this construction as we have shown; if each if

were indented past the previous else, a long sequence of decisions would march off the right

side of the page.

The switch statement, to be discussed in Chapter 4, provides another way to write a multi-

way branch that is particulary suitable when the condition is whether some integer or character

expression matches one of a set of constants. For contrast, we will present a switch version of

this program in Section 3.4.

**Exercise 1-13.** Write a program to print a histogram of the lengths of words in its input. It is

easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

**Exercise 1-14.** Write a program to print a histogram of the frequencies of different characters

in its input.

## 1.7 Functions

## 1.8 Arguments - Call by Value

## 1.9 Character Arrays

## 1.10 External Variables and Scope

---

## Exercise

**Exercise 1-1.** Run the `hello, world` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.

**Exercise 1-2.** Experiment to find out what happens when `printf`'s *argument string* contains`\c`, where `\c` is some character not listed above.

**Exercise 1-3.** Modify the temperature conversion program to print a heading above the table.

**Exercise 1-4.** Write a program to print the corresponding Celsius to Fahrenheit table.

**Exercise 1-5.** Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

**Exercsise 1-6.** Verify that the expression `getchar() != EOF` is 0 or 1.

**Exercise 1-7.** Write a program to print the value of `EOF`.

**Exercise 1-8.** Write a program to count blanks, tabs, and newlines.

**Exercise 1-9.** Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

**Exercise 1-10.** Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`. This makes tabs and backspaces visible in an <u>unambiguous</u> way.

**Exercise 1-11.** How would you test the word count program? What kinds of input are most likely to <u>uncover bugs</u> if there are any?

**Exercise 1-12.** Write a program that prints its input one word per line.

---

-   [x] [Floating Point Definition](https://www.freecodecamp.org/news/floating-point-definition/), https://www.freecodecamp.org/news/floating-point-definition/
-   [ ] [你所不知道的 C 語言: 浮點數運算](https://hackmd.io/@sysprog/c-prog/https%3A%2F%2Fhackmd.io%2F%40sysprog%2Fc-floating-point)



