# Character Sets

### 空白字符

\s

[\t\n\f\r\p{Z}]

这里的 `\p{Z}` 匹配所有 Unicode 空白字符。

| DEC  | OCT  | HEX  | BIN  | Symbol | HTML Number | HTML Name | Description |
| :--: | :--: | :--: | :--: | :----: | :---------: | :-------: | :---------- |
|      |      |      |      |        |             |           |             |

### 数字

=== "中文"

		数字

=== "英文"

		digits, (numerals, numbers, figures)

=== "ASCII"

    48..57
    
    | 数字 | ASCII 字符 |
    | ---- | ---------- |
    | 0    | 48         |
    | 1    | 49         |
    | 2    | 50         |
    | 3    | 51         |
    | 4    | 52         |
    | 5    | 53         |
    | 6    | 54         |
    | 7    | 55         |
    | 8    | 56         |
    | 9    | 57         |

=== "Regex"

    ``` sh
    # the character range
    [0-9]
    
    # metacharacter
    \d
    \D
    ```

### 英文字母

=== "中文"

		英文字母

=== "英文"

		letters

=== "ASCII"

    65..90
    
    	97..122

=== "Regex"

    ``` sh
    [a-z]
    [A-Z]
    ```

### 下划线

=== "中文"

		下划线

=== "英文"

		underscore

=== "ASCII"

    95
    
    |                 DEC                 | OCT  | HEX  |   BIN    | Symbol | HTML Number | HTML Name  | Description |
    | :---------------------------------: | :--: | :--: | :------: | :----: | :---------: | :--------: | :---------- |
    | [95](https://www.ascii-code.com/95) | 137  |  5F  | 01011111 |   _    |   `&#95;`   | `&lowbar;` | Underscore  |

=== "Regex"

    ``` sh
    
    ```

### 单词

=== "中文"

​		单词

=== "英文"

​		word

=== "Regex"

    ``` sh
    # the 'word' metacharacter
    
    \w
    \W
    
    # the character range
    [a-zA-Z0-9_]
    [^a-zA-Z0-9]
    ```

