# 06. Exception Handling and Debugging

1.  **异常的类型和处理机制：**
    -   了解Java中的异常分类，如受检查异常和非受检查异常
    -   学习异常处理的基本语法，包括try、catch、finally块
    -   理解异常处理机制，如异常传播和异常链
2.  **调试工具和技巧：**
    -   学习如何使用集成开发环境（IDE）的调试工具
    -   掌握断点的设置和调试会话的管理
    -   使用日志记录工具和技巧，如Log4j
    -   掌握常见的调试技巧，如打印调试信息、观察变量和堆栈跟踪

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of exception handling and debugging aspects
aspects=("Exception-Types-and-Handling-Mechanisms" "Debugging-Tools-and-Techniques")

# Loop to create folders
for i in {1..2}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

