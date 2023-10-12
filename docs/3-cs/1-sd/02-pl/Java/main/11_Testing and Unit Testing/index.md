# 11. Testing and Unit Testing

1.  **JUnit或TestNG选择：**
    -   了解JUnit和TestNG的特点和适用场景
    -   选择适合你项目的测试框架
2.  **单元测试编写：**
    -   编写测试用例
    -   执行测试用例
    -   断言（Assertions）的使用
    -   针对不同场景的单元测试
3.  **测试套件（Test Suites）：**
    -   创建测试套件
    -   将多个测试类组织在一起
    -   批量执行测试
4.  **Mocking和Stubbing：**
    -   使用模拟框架创建虚拟对象
    -   设置桩对象（Stubbing）的行为
    -   隔离测试对象

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of testing and unit testing aspects
aspects=("JUnit-or-TestNG-Selection" "Unit-Test-Writing" "Test-Suites" "Mocking-and-Stubbing")

# Loop to create folders
for i in {1..4}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

