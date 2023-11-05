---
Date: Tue Oct 10 07:42:41 CST 2023
---

# Note 5. 

set -> dict {}

el -> key-value

sequence: string, tuple, list

general operator: `in`, `not in`, `*`, `+` slice, index

general functions: `len()`, `max()`, `min()`, `s.index(el)`, `s.count(el)`

排序

``` py
list.sort()
sorted(iteralble, , reverse=true)
```

## dict

Dictionaries are great for storing **key-value mappings** or **pairs**.

键值对的集合，而非序列，即强调其无序性

反映一种对应关系。

集合的唯一性体现在键的唯一性，以及键的不可变性质。

key: num, string, tuple, not list

item: key, value

curd

``` python
# general
len(dict)
k in d

# create
{}
dict()
d.fromkeys(list, <value>)

# update
d[key] = value # 某个 key-value
d.update(dict) # 某个 dict

# read
d.get(k, <default>) # value
d.keys() # keys
d.values() # values
d.items() # key-value pairs

# del
del d(k)
d.pop(key, <default>)
d.popitem() # randomly
d.clear()
```

### 利用推导式来创建字典

``` python
# Dictionary Comprehension
{key_expression: value_expression for item in iterable if condition}

# Set Comprehension
{expression for item in iterable if condition}

# List Comprehension
[expression for item in iterable if condition]

# example
d = {'6102009' + f'{i:03}': '123456' for i in range(1, 101)}

# '6102009{0:03d}'.format(i)

for _ in range(65, )
```

Populate two lists into a dict.

``` python
list1
list2
dict = {key: value for key, value in zip(list1, list2)}
```



zip





### 应用场景

反映映射关系

``` python linenums="1"
# File Name: morse_code_converter.py

def text_to_morse(text):
    morse_code_dict = {
        'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 
        'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 
        'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
        '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...',
        '8': '---..', '9': '----.', ' ': ' '
    }

    text = text.upper()  # Convert text to uppercase for consistency
    morse_code = ''
    
    for char in text:
        if char in morse_code_dict:
            morse_code += morse_code_dict[char] + ' '  # Add a space between Morse Code representations of letters
        else:
            morse_code += char  # Keep unsupported characters as is

    return morse_code

# Example usage:
input_text = "Hello World"
morse_code_result = text_to_morse(input_text)
print(morse_code_result)

```



### 字典的排序

dict -> list -> sort

## jieba

-   [jieba](https://github.com/fxsjy/jieba) - 结巴中文分词

### 安装

``` python
pip3 install jieba
```

对文章进行分词，进行词频的统计。

``` python
import jieba

with open("", "r", encoding="utf-8") as file:
    txt = file.read()

d = dict()
words = jieba.lcut(txt)
excludes = ['', '', '', '']
for word in words:
    if len(word) < 2 || len(word) > 4:
        continue
    elif word in ['', '']
        rword = '诸葛亮'
    else:
        rword = word
    d[word] = d.get(word, 0) + 1
    
lst = list(d.items())
lst.sort(keys = lambda x: x[1], reverse: True)
```



## worldcloud

https://amueller.github.io/word_cloud/index.html

https://github.com/amueller/word_cloud
