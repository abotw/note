# 13. Design Patterns

1.  **设计模式选择：**
    -   了解各种设计模式的特点和适用场景
    -   选择适合你项目的设计模式
2.  **常见设计模式：**
    -   学习一些常见的设计模式，如工厂模式、单例模式、观察者模式、策略模式等
    -   掌握这些设计模式的概念、结构和应用方法
    -   实践这些设计模式以解决实际问题

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of design pattern aspects
aspects=("Design-Pattern-Selection" "Common-Design-Patterns")

# Loop to create folders
for i in {1..2}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```