# 05. Multithreading

1.  **线程的创建和管理：**
    -   创建线程的不同方式（继承Thread类、实现Runnable接口、使用线程池）
    -   线程的生命周期和状态管理
    -   线程的优先级和调度
2.  **同步和互斥：**
    -   使用关键字synchronized实现同步
    -   使用Lock接口和ReentrantLock类实现互斥
    -   避免线程冲突和竞态条件
3.  **线程池：**
    -   创建和管理线程池
    -   线程池的参数配置
    -   提交和执行任务
    -   监控和管理线程池

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of multithreading aspects
aspects=("Thread-Creation-and-Management" "Synchronization-and-Mutual-Exclusion" "Thread-Pools")

# Loop to create folders
for i in {1..3}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```