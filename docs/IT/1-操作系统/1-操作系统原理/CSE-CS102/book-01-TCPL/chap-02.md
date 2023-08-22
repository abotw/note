# Chapter 02 - Types, Operators and Expressions

*Variables* and *constants* are the basic ***data objects*** manipulated in a program. {==***Declarations*** list the variables to be used, and state what type they have and perhaps what their initial values are.==}

***Operators*** specify what is to be done to them. *Expressions* combine *variables* and *constants* to produce new values. {==**The type of an object** determines the set of values it can have and what operations can be performed on it.==} These building blocks are the topics of this chapter.

The ANSI standard has made many small changes and additions to basic *types* and *expressions*. There are now ***`signed`*** and ***`unsigned`*** forms of all integer types, and notations for **unsigned constants** and **hexadecimal character constants**. Floating-point operations may be done in single precision; there is also a long double type for extended precision. String constants may be concatenated at compile time. Enumerations have become part of the language, <u>formalizing a feature of long standing</u>. Objects may be declared `const`, which prevents them from being changed. The rules for automatic <u>coercions</u> among arithmetic types have been augmented to handle the richer set of types.

-   [x] [2.1 Variable Names](#21-variable-names)
-   [x] 2.2 Data Types and Sizes
-   [ ] 2.3 Constants

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

### 2.3 Constants

An integer *constant* like `1234` is an `int`. A `long` *constant* is written with a terminal `l` (ell) or `L`, as in `123456789L`; an integer *constant* too big to fit into an `int` will also be taken as a `long`. Unsigned *constants* are written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates `unsigned long`.

Floating-point *constants* contain a decimal point (123.4) or an exponent (1e-2) or both; their type is `double`, <u>unless suffixed</u>. The suffixes `f` or `F` indicate a `float` *constant*; `l` or `L` indicate a `long double`.

The value of an integer can be specified in *octal* or *hexadecimal* instead of *decimal*. A leading 0 (zero) on an integer constant means *octal*; a leading `0x` or `0X` means *hexadecimal*. For example, *decimal* 31 can be written as 037 in *octal* and `0x1f` or `0x1F` in *hex*. *Octal* and *hexadecimal* constants may also be followed by `L` to make them long and `U` to make them unsigned: `0XFUL` is an *unsigned long* constant with value 15 decimal.

A character *constant* is an integer, written as one character within single quotes, such as `'x'`. The value of a character *constant* is the numeric value of the character in the machine's character set. For example, in the ASCII character set the character constant `'0'` has the value 48, which is unrelated to the numeric value 0. If we write `'0'` instead of a numeric value like 48 that depends on the character set, the program is independent of the particular value and easier to read. Character constants participate in numeric operations just as any other integers, although they are most often used in comparisons with other characters.

Certain characters can be represented in character and string *constants* by ***escape sequences*** like `\n` (newline); these sequences look like two characters, but represent only one. In addition, <u>an arbitrary byte-sized bit pattern can be specified by `'\ooo'`</u>



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

[^1]: Library routines are pre-written code that can be used in programs to perform specific tasks.

*[ANSI]: 

*[ASCII]: