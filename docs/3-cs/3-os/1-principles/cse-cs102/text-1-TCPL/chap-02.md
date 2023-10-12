# Chapter 02 - Types, Operators and Expressions

*Variables* and *constants* are the basic ***data objects*** manipulated in a program. {==***Declarations*** list the variables to be used, and state what type they have and perhaps what their initial values are.==}

***Operators*** specify what is to be done to them. *Expressions* combine *variables* and *constants* to produce new values. {==**The type of an object** determines the set of values it can have and what operations can be performed on it.==} These building blocks are the topics of this chapter.

The ANSI standard has made many small changes and additions to basic *types* and *expressions*. There are now ***`signed`*** and ***`unsigned`*** forms of all integer types, and notations for **unsigned constants** and **hexadecimal character constants**. Floating-point operations may be done in single precision; there is also a long double type for extended precision. String constants may be concatenated at compile time. Enumerations have become part of the language, <u>formalizing a feature of long standing</u>. Objects may be declared `const`, which prevents them from being changed. The rules for automatic <u>coercions</u> among arithmetic types have been augmented to handle the richer set of types.

-   [x] [2.1 Variable Names](#21-variable-names)
-   [x] 2.2 Data Types and Sizes
-   [ ] 2.3 Constants
-   [ ] 2.4 Declarations
-   [ ] 2.5 Arithmetic Operators
-   [ ] 2.7 Type Conversions

## 2.1 Variable Names

!!! abstract

    -   letters, digits, underscore
    -   the first character must be a letter
    -   case-sensitive

Although we didn't say so in Chapter 1, there are some restrictions on the names of *variables* and *symbolic constants*. {==Names are made up of letters and digits; the first character must be a letter. The **underscore** `_` counts as a letter; it is sometimes useful for improving the readability of long variable names. Don't begin variable names with underscore, however, since library routines[^1] often use such names.==} {==Upper and lower case letters are distinct, so `x` and `X` are two different names.==} Traditional C practice is to use lower case for *variable* names, and all upper case for *symbolic constants*.

At least the first 31 characters of an internal name are significant. For function names and external variables, the number may be less than 31, because external names may be used by assemblers and loaders over which the language has no control. {++For external names, the standard guarantees uniqueness only for 6 characters and a single case.++} Keywords like `if`,`else`, `int`, `float`, etc., are reserved: you can't use them as variable names. They must be in lower case.

It's wise to choose variable names that are related to the purpose of the variable, and that are unlikely to get mixed up typographically. We tend to use short names for local variables, especially **loop indices**, and longer names for external variables.

## 2.2 Data Types and Sizes

!!! abstract

    -   data types: `char`, `int`, `float`, `double`
    
    -   qualifiers: `short`,`long`, `signed`, `unsigned`

There are only a few basic data types in C:

`char`

: a single byte, capable of holding one character in the local character set

`int`

: an integer, typically reflecting the natural size of integers on the host machine

`float`

: single-precision floating point

`double`

: double-precision floating point

In addition, there are a number of ***qualifiers*** that can be applied to these basic types. `short` and `long` apply to integers:

``` c
short int sh;
long int counter;
```

The word `int` can be omitted in such declarations, and typically it is.

The intent is that `short` and `long` should provide different lengths of integers where practical; `int` will normally be the natural size for a particular machine. `short` is often 16 bits long, and `int` either 16 or 32 bits. Each compiler is free to choose appropriate sizes for its own hardware, subject only to the the restriction that `short`s and `int`s are at least 16 bits, `long`s are at least 32 bits, and `short` is no longer than `int`, which is no longer than `long`.

The *qualifier* `signed` or `unsigned` may be applied to `char` or any integer. unsigned numbers are always positive or zero, and obey the laws of arithmetic modulo $2^n$, where *n* is the number of bits in the type. So, for instance, if `char`s are 8 bits, `unsigned char` variables have values between 0 and 255, while `signed char`s have values between -128 and 127 ({++in a two's complement machine.++}) Whether plain `char`s are `signed` or `unsigned` is machine-dependent, but printable characters are always positive.

The type `long double` specifies extended-precision floating point. As with integers, the sizes of floating-point objects are implementation-defined; `float`, `double` and `long double` could represent one, two or three distinct sizes.

***The standard headers*** `<limits.h>` and `<float.h>` contain *symbolic constants* for all of these sizes, along with other properties of the machine and compiler. These are discussed in Appendix B.

**Exercise 2-1.** Write a program to determine the ranges of `char`, `short`, `int`, and `long` variables, both `signed` and `unsigned`, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

## 2.3 Constants

**An integer *constant***: `l`, `L`, `u`, `U`

An integer *constant* like `1234` is an `int`. A `long` *constant* is written with a terminal `l` (ell) or `L`, as in `123456789L`; an integer *constant* too big to fit into an `int` will also be taken as a `long`. Unsigned *constants* are written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates `unsigned long`.

**Floating-point *constants***：`f`, `F`, `l`, `L`

Floating-point *constants* contain a decimal point (123.4) or an exponent (1e-2) or both; their type is `double`, unless suffixed. The suffixes `f` or `F` indicate a `float` *constant*; `l` or `L` indicate a `long double`.

***Octal* & *hexadecimal* constants**:

| decimal | octal | hex, hexadecimal   |
| ------- | ----- | ------------------ |
| `31`    | `037` | `0x1f` *OR* `0X1F` |

The value of an integer can be specified in *octal* or *hexadecimal* instead of *decimal*. {==A leading 0 (zero) on an integer *constant* means *octal*; a leading `0x` or `0X` means *hexadecimal*.==} For example, *decimal* 31 can be written as 037 in *octal* and `0x1f` or `0x1F` in *hex*. *Octal* and *hexadecimal* constants may also be followed by `L` to make them `long` and `U` to make them `unsigned`: `0XFUL` is an *unsigned long* constant with value 15 decimal.

**A character *constant***

A character *constant* is an integer, written as one character within single quotes, such as `'x'`. The value of a character *constant* is the numeric value of the character in the machine's character set. For example, in the [ASCII character set](https://www.ascii-code.com/) the character constant `'0'` has the value 48, which is unrelated to the numeric value 0. If we write `'0'` instead of a numeric value like 48 that depends on the character set, the program is independent of the particular value and easier to read. Character *constant*s participate in numeric operations just as any other integers, although they are most often used in comparisons with other characters.

**String *constants***

Certain characters can be represented in character and string *constants* by ***escape sequences*** like `\n` (newline); these sequences look like two characters, but represent only one. In addition, <u>an arbitrary byte-sized bit pattern can be specified by `'\ooo'`</u> where `ooo` is one to three octal digits (0...7) or by

``` c
'\xhh'
```

where `hh` is one or more hexadecimal digits (0...9, a...f, A...F). So we might write

``` c
#define VTAB '\013' /* ASCII vertical tab */
#define BELL '\007' /* ASCII bell character */
```

or, in hexadecimal,

``` c
#define VTAB '\xb' /* ASCII vertical tab */
#define BELL '\x7' /* ASCII bell character */
```

The complete set of ***escape sequences*** is

| escape sequence | explanation            | escape sequence | explanation        |
| --------------- | ---------------------- | --------------- | ------------------ |
| `\a`            | alert (bell) character | `\\`            | backslash          |
| `\b`            | backspace              | `\?`            | question mark      |
| `\f`            | formfeed               | ` \'`           | single quote       |
| `\n`            | newline                | ` \"`           | double quote       |
| `\r`            | carriage return        | ` \ooo`         | octal number       |
| `\t`            | horizontal tab         | ` \xhh`         | hexadecimal number |
| `\v`            | vertical tab           |                 |                    |

The *character constant* `'\0'` represents the character with value zero, the ***null character***. `'\0'` is often written instead of `0 `to emphasize the character nature of some expression, but the numeric value is just 0.

A ***constant expression*** is an expression that involves only constants. Such expressions may be evaluated at during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in

``` c
#define MAXLINE 1000
char line[MAXLINE+1];
```

or

``` c
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
```

A ***string constant***, or ***string literal***, is a sequence of zero or more characters surrounded by double quotes, as in

``` c
"I am a string"
```

or

``` c
"" /* the empty string */
```

The quotes are not part of the string, but serve only to <u>delimit</u> it. The same ***escape sequences*** used in *character constants* apply in strings; `\"` represents the double-quote character. String constants can be concatenated at compile time:

``` c
"hello, " "world"
```

is equivalent to

``` c
"hello, world"
```

This is useful for splitting up long strings across several source lines.

Technically, a *string constant* is an array of characters. The internal representation of a string has a *null character* `'\0'` at the end, so the physical storage required is one more than the number of characters written between the quotes. This representation means that there is no limit to how long a string can be, but programs must scan a string completely to determine its length. The standard library function `strlen(s)` returns the length of its character string argument `s`, excluding the terminal `'\0'`. Here is our version:

``` c
/* strlen: return length of s */
int strlen(char s[])
{
  	int i;
  
  	while (s[i] != '\0')
      	++i;
  	return i;
}
```

`strlen` and other string functions are declared in the standard header `<string.h>`.

Be careful to distinguish between a *character constant* and a string that contains a single character: 'x' is not the same as "x". The former is an integer, used to produce the numeric value of the letter `x` in the machine's character set. The latter is an array of characters that contains one character (the letter `x`) and a '\0'.

There is one other kind of *constant*, the ***enumeration constant***. An enumeration is a list of constant integer values, as in

``` c
enum boolean { NO, YES };
```

The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the <u>progression</u> from the last specified value, as the second of these examples:

``` c
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB = 2, MAR = 3, etc. */
```

Names in different enumerations must be distinct. Values need not be distinct in the same enumeration.

Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that the values can be generated for you. Although variables of `enum` types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration. Nevertheless, enumeration variables offer the chance of checking and so are often better than `#defines`. In addition, a debugger may be able to print values of enumeration variables in their symbolic form.

## 2.4 Declarations

All *variables* must be declared before use, although certain ***declarations*** can be made implicitly by content. A *declaration* specifies a type, and contains a list of one or more *variables* of that type, as in

``` c
int lower, upper, step;
char c, line[1000];
```

*Variables* can be distributed among *declarations* in any fashion; the lists above could well be written as

``` c
int lower;
int upper;
int step;
char c;
char line[1000];
```

The latter form takes more space, but is convenient for adding a *comment* to each *declaration* for subsequent modifications.

A *variable* may also be initialized in its *declaration*. If the name is followed by ***an equals sign*** and an *expression*, the *expression* serves as an initializer, as in

``` c
char esc = '\\';
int i = 0;
int limit = MAXLINE+1;
float eps = 1.0e-5;
```

If the *variable* in question is not automatic, the initialization is done once only, <u>conceptionally</u> before the program starts executing, and the initializer must be a ***constant expression***. An explicitly initialized automatic variable is initialized each time the function or block it is in is entered; the initializer may be any expression. {==External and static *variables* are initialized to zero by default.==} Automatic variables for which is no explicit initializer have undefined (i.e., garbage) values.

The *qualifier* `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the `const` qualifier says that the elements will not be altered.

``` c
const double e = 2.71828182845905;
const char msg[] = "warning: ";
```

The `const` declaration can also be used with array arguments, to indicate that the function does not change that array:

``` c
int strlen(const char[]);
```

The result is implementation-defined if an attempt is made to change a `const`.

## 2.5 Arithmetic Operators

The <u>binary arithmetic operators</u> are `+`, `-`, `*`, `/`, and the ***modulus operator*** `%`. Integer division truncates any fractional part. The expression

``` c
x % y
```

produces the remainder when `x` is divided by `y`, and thus is zero when `y` divides `x` exactly. For example, a year is a leap year if it is divisible by 4 but not by 100, except that years divisible by 400 *are* leap years. Therefore

``` c
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  	printf("%d is a leap year\n", year);
else
  	printf("%d is not a leap year\n", year);
```

The `%` operator cannot be applied to a `float` or `double`. The direction of truncation for `/` and the sign of the result for `%` are machine-dependent for negative operands, as is the action taken on overflow or <u>underflow</u>.

The binary `+` and `-` operators have the same precedence, which is lower than the precedence of `*`, `/` and `%`, which is in turn lower than <u>unary</u> `+` and `-`. Arithmetic operators <u>associate</u> left to right.

Table 2.1 at the end of this chapter summarizes precedence and associativity for all operators.

## 2.7 Type Conversions

When an operator has operands of different types, they are converted to a common type according to ***a small number of rules***. In general, the only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as converting an integer into floating point in an expression like `f + i`. Expressions that don't make sense, like using a float as a subscript, are disallowed. Expressions that might lose information, like assigning a longer integer type to a shorter, or a floating-point type to an integer, may draw a warning, but they are not illegal.

A `char` is just a small integer, so `char`s may be freely used in arithmetic expressions. This permits considerable flexibility in certain kinds of character transformations. One is exemplified by this naive implementation of the function `atoi`, which converts a string of digits into its numeric equivalent.

``` c title="atoi"
/* atoi: convert s to integer */
int atoi(char s[])
{
  	int i, n;
  
  	n = 0;
  	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
      	n = 10 * n + (s[i] - '0');
  	return n;
}
```

As we discussed in Chapter 1, the expression

``` c
s[i] - '0'
```

gives the numeric value of the character stored in `s[i]`, because the values of `'0'`, `'1'`, etc., form a contiguous increasing sequence.

Another example of `char` to `int` conversion is the function `lower`, which maps a single character to lower case *for the ASCII character set*. If the character is not an upper case letter, lower returns it unchanged.

``` c title="lower"
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  	if (c >= 'A' && c <= 'Z')
      	return c + 'a' - 'A';
  	else
      	return c;
}
```

This works for ASCII because corresponding upper case and lower case letters are a fixed distance apart as numeric values and each alphabet is contiguous -- there is nothing but letters between A and Z. This latter observation is not true of [the EBCDIC character set](https://en.wikipedia.org/wiki/EBCDIC), however, so this code would convert more than just letters in [EBCDIC](https://en.wikipedia.org/wiki/EBCDIC).

The standard header `<ctype.h>`, described in Appendix B, defines a family of functions that provide tests and conversions that are independent of character set. For example, the function `tolower` is a portable replacement for the function `lower` shown above. Similarly, the test

``` c
c >= '0' && c <= '9'
```

can be replaced by

``` c
isdigit(c)
```

We will use the `<ctype.h>` functions from now on.

There is one subtle point about the conversion of characters to integers. The language does not specify whether variables of type `char` are `signed` or `unsigned` quantities. When a `char` is converted to an `int`, can it ever produce a negative integer? The answer varies from machine to machine, reflecting differences in architecture. On some machines a `char` whose leftmost bit is 1 will be converted to a negative integer ("sign extension"). On others, a `char` is promoted to an `int` by adding zeros at the left end, and thus is always positive.

The definition of C guarantees that any character in the machine's standard printing character set will never be negative, so these characters will always be positive quantities in expressions.

But arbitrary bit patterns stored in character variables may appear to be negative on some machines, yet positive on others. For portability, specify `signed` or `unsigned` if non-character data is to be stored in `char` variables.

Relational expressions like `i > j` and logical expressions connected by `&&` and `||` are defined to have value 1 if true, and 0 if false. Thus the assignment

``` c
d = c >= '0' && c <= '9'
```

sets `d` to 1 if `c` is a digit, and 0 if not. However, functions like isdigit may return any non-zero value for true. In the test part of `if`, `while`, for, etc., "true" just means "non-zero", so this makes no difference.

Implicit arithmetic conversions work much as expected. In general, if an operator like `+` or `*` that takes two operands (a binary operator) has operands of different types, the "lower" type is *promoted* to the "higher" type before the operation proceeds. The result is of the integer type.

Section 6 of Appendix A states the conversion rules precisely. If there are no `unsigned` operands, however, the following informal set of rules will suffice:

-   If either operand is `long double`, convert the other to `long double`.
-   Otherwise, if either operand is `double`, convert the other to `double`.
-   Otherwise, if either operand is `float`, convert the other to `float`.
-   Otherwise, convert `char` and `short` to `int`.
-   Then, if either operand is `long`, convert the other to `long`.

Notice that `float`s in an expression are not automatically converted to double; this is a change from the original definition. In general, mathematical functions like those in `<math.h>` will use double precision. The main reason for using `float` is to save storage in large arrays, or, less often, to save time on machines where double-precision arithmetic is particularly expensive.

Conversion rules are more complicated when `unsigned` operands are involved. The problem is that comparisons between `signed` and `unsigned` values are machine-dependent, because they depend on the sizes of the various integer types. For example, suppose that `int` is 16 bits and `long` is 32 bits. Then `-1L < 1U`, because `1U`, which is an `unsigned int`, is promoted to a `signed long`. But `-1L > 1UL` because `-1L` is promoted to `unsigned long` and thus appears to be a large positive number.

Conversions take place across assignments; the value of the right side is converted to the type

of the left, which is the type of the result.

A character is converted to an integer, either by sign extension or not, as described above.

Longer integers are converted to shorter ones or to chars by dropping the excess high-order

bits. Thus in

int i;

char c;

i = c;

c = i;

the value of c is unchanged. This is true whether or not sign extension is involved. Reversing

the order of assignments might lose information, however.

If x is float and i is int, then x = i and i = x both cause conversions; float to int causes

truncation of any fractional part. When a double is converted to float, whether the value is

rounded or truncated is implementation dependent.

Since an argument of a function call is an expression, type conversion also takes place when

arguments are passed to functions. In the absence of a function prototype, char and short

become int, and float becomes double. This is why we have declared function arguments to

be int and double even when the function is called with char and float.

Finally, explicit type conversions can be forced (``coerced'') in any expression, with a unary

operator called a cast. In the construction

(*type name*) *expression*43

the *expression* is converted to the named type by the conversion rules above. The precise

meaning of a cast is as if the *expression* were assigned to a variable of the specified type, which

is then used in place of the whole construction. For example, the library routine sqrt expects a

double argument, and will produce nonsense if inadvertently handled something else. (sqrt is

declared in <math.h>.) So if n is an integer, we can use

sqrt((double) n)

to convert the value of n to double before passing it to sqrt. Note that the cast produces the

*value* of n in the proper type; n itself is not altered. The cast operator has the same high

precedence as other unary operators, as summarized in the table at the end of this chapter.

If arguments are declared by a function prototype, as the normally should be, the declaration

causes automatic coercion of any arguments when the function is called. Thus, given a function

prototype for sqrt:

double sqrt(double)

the call

root2 = sqrt(2)

coerces the integer 2 into the double value 2.0 without any need for a cast.

The standard library includes a portable implementation of a pseudo-random number generator

and a function for initializing the seed; the former illustrates a cast:

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */

int rand(void)

{

next = next * 1103515245 + 12345;

return (unsigned int)(next/65536) % 32768;

}

/* srand: set seed for rand() */

void srand(unsigned int seed)

{

next = seed;

}

**Exercise 2-3.** Write a function htoi(s), which converts a string of hexadecimal digits

(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0

through 9, a through f, and A through F.

## Appendix B

### B.11 Implementation-defined Limits: <limits.h> and <float.h>

The header **<limits.h>** defines *constants* for the sizes of <u>integral types</u>.

The values below are acceptable minimum <u>magnitudes</u>; larger values may be used.

|           |                          |                                 |
| --------- | ------------------------ | ------------------------------- |
| CHAR_BIT  | 8 bits                   | in a char                       |
| CHAR_MAX  | UCHAR_MAX *or* SCHAR_MAX | maximum value of char           |
| CHAR_MIN  | 0 *or* SCHAR_MIN         | maximum value of char           |
| INT_MAX   | 32767                    | maximum value of int            |
| INT_MIN   | -32767                   | minimum value of int            |
| LONG_MAX  | 2147483647               | maximum value of long           |
| LONG_MIN  | -2147483647              | minimum value of long           |
| SCHAR_MAX | +127                     | maximum value of signed char    |
| SCHAR_MIN | -127                     | minimum value of signed char    |
| SHRT_MAX  | +32767                   | maximum value of short          |
| SHRT_MIN  | -32767                   | minimum value of short          |
| UCHAR_MAX | 255                      | maximum value of unsigned char  |
| UINT_MAX  | 65535                    | maximum value of unsigned int   |
| ULONG_MAX | 4294967295               | maximum value of unsigned long  |
| USHRT_MAX | 65535                    | maximum value of unsigned short |

The names in the table below, a subset of `<float.h>`, are *constants* related to floating-point arithmetic. When a value is given, it represents the minimum magnitude for the corresponding quantity. Each implementation defines appropriate values.

|              |       |                                                            |
| ------------ | ----- | ---------------------------------------------------------- |
| FLT_RADIX    | 2     | radix of exponent, representation, e.g., 2, 16             |
| FLT_ROUNDS   |       | floating-point rounding mode for addition                  |
| FLT_DIG      | 6     | decimal digits of precision                                |
| FLT_EPSILON  | 1E-5  | smallest number *x* such that 1.0+x != 1.0                 |
| FLT_MANT_DIG |       | number of base FLT_RADIX in mantissa                       |
| FLT_MAX      | 1E+37 | maximum floating-point number                              |
| FLT_MAX_EXP  |       | maximum *n* such that ${FLT_RADIX}^{n-1}$ is representable |
| FLT_MIN      | 1E-37 | minimum normalized floating-point number                   |
| FLT_MIN_EXP  |       | minimum *n* such that $10^n$ is a normalized number        |
| DBL_DIG      | 10    | decimal digits of precision                                |
| DBL_EPSILON  | 1E-9  | smallest number *x* such that 1.0+x != 1.0                 |
| DBL_MANT_DIG |       | number of base FLT_RADIX in mantissa                       |
| DBL_MAX      | 1E+37 | maximum double floating-point number                       |
| DBL_MAX_EXP  |       | maximum *n* such that $FLT_RADIX^{n-1}$ is representable   |
| DBL_MIN      | 1E-37 | minimum normalized double floating-point number            |
| DBL_MIN_EXP  |       | minimum *n* such that $10^n$ is a normalized number        |

## References

### [ASCII@b0rk](https://twitter.com/b0rk/status/1661066796156305433)

![ASCII](https://pbs.twimg.com/media/Fw1LcT8XwCQMOQr?format=jpg&name=large)

-   **a string is an array of bytes** - 
    ASCII is the simplest string encoding: 1 character = 1 byte.
    (We usually use [UTF-8](https://en.wikipedia.org/wiki/UTF-8), which is WAY more complicated)
-   **every printable ASCII character** - 
    There are no accents because it's an English encoding: the "A" is for "American".
-   **there are 128 ASCII characters** - 
    Only the bytes 0 to 127 are defined.
    It's very limited: you can really see why we need more powerful encodings like UTF-8!
-   **how bytes map to characters: 33-48-65-97** - 
    Here's a pratical list, look up "ASCII table" for the full list.
    Bytes (in base 10) are on the left, characters are on the right.
-   **a trick to translate from lowercase to uppercase: 32 = 2 * 16 **- 
    In ASCII, the lowercase letters are 32 more than the uppercase letters. So you can just subtract 32!
    -   {==lowercase (97) = capital (65) + space (32)==}


[^1]: Library routines are pre-written code that can be used in programs to perform specific tasks.

*[ANSI]: 

*[ASCII]:

*[EBCDIC]: Extended Binary Coded Decimal Interchange Code

*[UTF-8]: 8-bit Unicode Transformation Format