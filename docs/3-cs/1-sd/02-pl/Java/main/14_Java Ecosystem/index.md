# 14. Java Ecosystem

1.  **Spring框架：**
    -   Spring核心容器（IoC容器和Bean工厂）
    -   依赖注入（DI）和控制反转（IoC）
    -   AOP（面向切面编程）
    -   Spring MVC（模型-视图-控制器）框架
    -   Spring Boot和自动配置
2.  **Hibernate：**
    -   ORM（对象关系映射）的基本概念
    -   Hibernate的配置和映射
    -   持久性和数据库访问
    -   Hibernate查询语言（HQL）和标准SQL查询
    -   Hibernate的缓存和性能优化

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of Java ecosystem aspects
aspects=("Spring-Framework" "Hibernate-ORM")

# Loop to create folders
for i in {1..2}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```