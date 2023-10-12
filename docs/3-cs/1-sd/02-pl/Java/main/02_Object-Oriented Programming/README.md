# Object-Oriented Programming

1.  **封装、继承和多态：**
    -   理解封装（Encapsulation）的概念
    -   学习如何创建和使用类
    -   掌握继承（Inheritance）的原理和用法
    -   实现多态（Polymorphism）和方法的重写
2.  **抽象类和接口：**
    -   创建抽象类和方法
    -   实现接口（Interface）并了解接口的作用
    -   掌握抽象类和接口之间的区别
3.  **构造函数和析构函数：**
    -   编写构造函数（Constructor）来初始化对象
    -   学习如何销毁对象和资源的析构函数（Destructor）
4.  **异常处理（try-catch）：**
    -   处理异常情况
    -   使用try-catch块来捕获和处理异常
    -   自定义异常类
    -   学习异常处理的最佳实践

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of OOP aspects
aspects=("Encapsulation-Inheritance-Polymorphism" "Abstract-Classes-and-Interfaces" "Constructors-and-Destructors" "Exception-Handling")

# Loop to create folders
for i in {1..4}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

