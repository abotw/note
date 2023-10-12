# 07. Advanced Topics

1.  **泛型（Generics）：**
    -   泛型类和方法的创建
    -   类型参数和类型擦除
    -   通配符和限定通配符
    -   泛型的使用场景
2.  **反射（Reflection）：**
    -   获取类的信息
    -   动态创建类的实例
    -   调用方法和访问字段
    -   处理注解和泛型类型
3.  **注解（Annotations）：**
    -   自定义注解
    -   注解处理器的创建
    -   内置注解（如@Deprecated、@Override）
    -   注解的使用场景
4.  **Lambda表达式：**
    -   Lambda表达式的语
    -   函数式接口（Functional Interface）
    -   Lambda表达式和方法引用的应用
    -   使用Stream API进行函数式编程

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of advanced topics
aspects=("Generics" "Reflection" "Annotations" "Lambda-Expressions")

# Loop to create folders
for i in {1..4}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

