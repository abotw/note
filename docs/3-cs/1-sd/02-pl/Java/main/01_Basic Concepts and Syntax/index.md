# Basic Concepts and Syntax

1.  **数据类型：**
    -   基本数据类型（int, double, boolean, char等）
    -   引用数据类型（类、数组、接口等）
    -   类型转换和类型转换操作符
2.  **变量和数据存储：**
    -   声明和初始化变量
    -   变量的作用域
    -   内存管理和垃圾回收
3.  **运算符和表达式：**
    -   算术运算符（+、-、*、/等）
    -   比较运算符（==、!=、<、>等）
    -   逻辑运算符（&&、||、！等）
    -   条件运算符（三元运算符）
    -   位运算符
4.  **控制流程：**
    -   条件语句（if、else、switch）
    -   循环结构（for、while、do-while）
    -   跳出循环（break、continue）
    -   循环控制（标签和标签语句）
5.  **数组和集合：**
    -   创建和操作数组
    -   数组的多维数组
    -   使用集合框架（ArrayList、HashMap等）
    -   集合的迭代
6.  **类和对象：**
    -   创建类和对象
    -   访问修饰符（public、private、protected、default）
    -   构造函数（构造方法）和实例变量
    -   静态成员
7.  **方法和函数：**
    -   创建和调用方法
    -   方法参数和返回值
    -   重载方法
    -   递归方法

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of basic concepts and syntax aspects
aspects=("Data-Types" "Variables-and-Data-Storage" "Operators-and-Expressions" "Control-Flow" "Arrays-and-Collections" "Classes-and-Objects" "Methods-and-Functions")

# Loop to create folders
for i in {1..7}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

