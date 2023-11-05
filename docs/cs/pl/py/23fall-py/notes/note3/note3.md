# Note 3. 230919

``` 
Help on built-in function pow in module builtins:

pow(base, exp, mod=None)
    Equivalent to base**exp with 2 arguments or base**exp % mod with 3 arguments

    Some types, such as ints, are able to use a more efficient algorithm when
    invoked using the three argument form.
(END)
```

``` py
>>> round(0.1+0.2, 15) == 0.3
True
```

``` 

Help on built-in function round in module builtins:

round(number, ndigits=None)
    Round a number to a given precision in decimal digits.

    The return value is an integer if ndigits is omitted or None.  Otherwise
    the return value has the same type as the number.  ndigits may be negative.
```

整数，浮点数，复数

```
Help on built-in function divmod in module builtins:

divmod(x, y, /)
    Return the tuple (x//y, x%y).  Invariant: div*y + mod == x.
```

-   math 库
-   time 库
-   numpy
-   padas

``` py
Help on built-in function format in module builtins:

format(value, format_spec='', /)
    Return value.__format__(format_spec)

    format_spec defaults to the empty string.
    See the Format Specification Mini-Language section of help('FORMATTING') for
    details.
```

格式化字符串的方式

-   `"{}".format()`
-   `"%"%`

## 字符串处理

*参见：<https://cs.stanford.edu/people/nick/py/python-string.html>*

*参见：<https://web.stanford.edu/class/cs106a/>*

*参见：<https://sites.pitt.edu/~naraehan/python3/>*

*参见：<https://pythonnumericalmethods.berkeley.edu/notebooks/chapter02.02-Data-Structure-Strings.html>*

![alt: string 'Python' shown with index numbers 0..5](./assets/python-str-index.svg)

![alt: divide chars into alpha (lower/upper), digit, space, and misc leftovers](./assets/python-charclass.svg)

### 表示

-   单行
-   多行
-   原始

``` py
''
""
''''''
""""""
r""
f""
```

### 操作符

```
+
*
str[i]
str[start:end:step]

```

### 方法

```
Help on built-in function chr in module builtins:

chr(i, /)
    Return a Unicode string of one character with ordinal i; 0 <= i <= 0x10ffff.
```

``` 
Help on built-in function ord in module builtins:

ord(c, /)
    Return the Unicode code point for a one-character string.
```

## 正则表达式

`re.sub()`

`re.replace()`

如何将一个字符串中所有的非数字去掉呢？

## Time

<https://docs.python.org/3/library/time.html>

<https://docs.python.org/3/library/time.html#time.time>

<https://docs.python.org/3/library/time.html#time.ctime>

<https://docs.python.org/3/library/time.html#time.gmtime>

<https://docs.python.org/3/library/time.html#time.localtime>

<https://docs.python.org/3/library/time.html#time.strftime>

<https://docs.python.org/3/library/time.html#time.strptime>

<https://docs.python.org/3/library/time.html#time.perf_counter>

<https://docs.python.org/3/library/time.html#time.sleep>