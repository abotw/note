# unordered_map

`unordered_map`是一个**无序**的**关联容器**，它提供了**常数时间复杂度**的平均插入、删除和查找操作。

* **C++11 支持**：C++11 supports the usage of `unordered_map`. 
* **基于哈希表的关联容器**：The `unordered_map` container is part of the C++ Standard Library and provides an implementation of a hash table-based associative container. 
* **常数时间复杂度的键值对存取**：It allows for efficient key-value pair storage and retrieval.
* **无序容器**：Similar to the `map` container, but with unordered keys.

* **使用前提**：To use `unordered_map` in C++11, you need to include the `<unordered_map>` header file. 

Please note that the order of elements in an `unordered_map` is not guaranteed, as it uses a hash-based storage mechanism. If you need the elements to be sorted, you may consider using the `map` container instead.

``` cpp linenums="1" hl_lines="1" title="an example of how to use `unordered_map` in C++11"
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // create an `unordered_map` called `myMap` with `string` keys and `int` values
    unordered_map<string, int> myMap;
    
    // Insert key-value pairs into the unordered_map using the square bracket notation
    myMap["apple"] = 10;
    myMap["banana"] = 5;
    myMap["orange"] = 15;
    
    // access the values using the keys
    cout << "Numbser of apples: " << myMap["apple"] << endl;
    cout << "Number of bananas: " << myMap["banana"] << endl;
    
    return 0;
}
```

``` cpp linenums="1" hl_lines="1" title="--"
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    // 创建一个 unordered_map, 用于存储学生的姓名和对应的年龄
    std::unordered_map<std::string, int> studentAgeMap;
    
    // 向 unordered_map 中添加元素，键是学生的姓名，值是学生的年龄
    studentAgeMap["Alice"] = 20;
    studentAgeMap["Bob"] = 21;
    studentAgeMap["Charlie"] = 19;
    
    // 遍历 unordered_map
    for (const auto& pair : studentAgeMap)
    {
        std::cout << "Name: " << pair.first << ", Age: " << pair.second << std::endl;
    }
    
    // 检查 unordered_map 中是否存在某个键
    std::string name = "Alice";
    if (studentAgeMap.count(name) > 0)
        std::cout << name << " is in the map." << std::endl;
    else
        std::cout << name << " is not in the map." << std::endl;
        
    // 寻找 unordered_map 中某个键对应的值
    name = "Bob";
    if (studentAgeMap.find(name) != studentAgeMap.end())
    {
        int age = studentAgeMap[name];
        std::cout << name << "'s age is " << age << std::endl;
    }
    else
        std::cout << "Cannot find the age for " << name << std::endl;
        
    // 删除 unordered_map 中的某个键值对
    name = "Charlie";
    if (studentAgeMap.erase(name) > 0)
        std::cout << name << " has been removed from the map." << std::endl;
    else
        std::cout << name << " is not in the map." << std::endl;
        
    // 清空 unordered_map
    studentAgeMap.clear();
    
    return 0;
}
```

# map

## 蓝桥杯中常见的使用`map`的具体例子

``` cpp linenums="1" hl_lines="10 17-18" title="Counting Character Occurences 统计字符出现次数"
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string str; // (1)
    std::cin >> str; // (2)
    
    std::map<char, int> countMap; // (3)
    
    // Iterate over each character in the 'str' string.
    for (char ch : str)
        countMap[ch] ++ ; // (4)
    
    // Iterate over each key-value pair in 'countMap'.
    for (const auto& pair : countMap) // (5), (6), (7), (8)
        std::cout << pair.first << ": " << pair.second << std::endl; // (9), (10)
  
    return 0; // (11)
}
```

1. Create a string variable named 'str'.
2. Read a string from the **standard input** and store it in the 'str' variable.
3. Create **a map container** named 'countMap' to store characters and their **occurrence counts**.
4. Increase the **occurrence count** of character 'ch'.
5. a range-based for loop
6. The `auto` keyword is used to automatically <u>deduce 推断</u> the type of the variable
7. `const` indicates that the pair is **read-only** and **cannot be modified**
8. The `&` symbol signifies that it is a reference to the pair, rather than a copy.
9. Print the character and its corresponding occurrence count.
10. `pair.first` represents the key (character) of the current pair, and `pair.second` represents the corresponding value (occurrence count).
11. `return 0` to indicate **successful program execution**.

``` cpp linenums="1" hl_lines="9 11 12 14" title="Word Count 单词计数"
#include <iostream> // Include the input/output stream library
#include <map> // Include the map library for using std::map
#include <sstream> // Include the string stream library for string operations
#include <string> // Include the string library for string manipulation

int main()
{
    std::string text;
    std::getline(std::cin, text); // (1)
    
    std::map<std::string, int> wordCount; // (2)
    std::stringstream ss(text); // (3)
    std::string word;
    while (ss >> word) // (4)
        wordCount[word] ++ ;
        
    for (const auto& pair : wordCount)
        std:cout << pair.first << ": " << pair.second << std::endl;
        
    return 0;
}
```

1. Read a line of input from the user and store it in 'text'
2. Declare a map to store word counts
3. Create a stringstream object initialized with 'text'
4. Extract words from the stringstream and store them in 'word'

``` cpp linenums="1" hl_lines="0" title="Finding a Missing Number"
#include <iostream>
#include <map>

int main()
{
    std::map<int, bool> numMap;
    
    int n;
    std::cin >> n;
    
    for (int i = 1; i <= n; i ++ )
    {
        int num;
        std::cin >> num;
        numMap[num] = true;
    }
    
    for (int i = 1; i < n; i ++ )
        if (!numMap[i])
        {
            std::cout << "Missing number: " << i << std::endl;
            break;
        }
        
    return 0;
}
```

