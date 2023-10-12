# 03. Collection Framework and Data Structures

1.  **列表、集合、映射：**
    -   理解列表（List）、集合（Set）、映射（Map）等集合框架的概念
    -   学习各种集合框架的特性和用途
    -   了解集合的存储方式和数据结构
2.  **ArrayList, HashMap等：**
    -   学习使用ArrayList来管理列表
    -   使用HashMap实现映射
    -   了解不同集合框架之间的差异
    -   使用其他集合，如LinkedList、HashSet等
3.  **迭代器和foreach循环：**
    -   使用迭代器来遍历集合
    -   学习for-each循环的使用
    -   理解迭代器和for-each循环的性能和适用性

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of collection framework and data structure aspects
aspects=("Lists-Sets-Maps" "ArrayLists-HashMaps-and-More" "Iterators-and-Foreach-Loops")

# Loop to create folders
for i in {1..3}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

