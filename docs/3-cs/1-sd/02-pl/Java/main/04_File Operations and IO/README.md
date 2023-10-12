# README

1.  **文件读写：**
    -   打开和关闭文件
    -   读取文件内容（文本和二进制文件）
    -   写入文件内容
    -   处理文件路径和文件名
    -   使用BufferedReader和BufferedWriter提高读写效率
2.  **流（InputStream 和 OutputStream）：**
    -   学习InputStream和OutputStream类及其子类，如FileInputStream、FileOutputStream
    -   字节流和字符流的区别
    -   使用字节流处理二进制数据
    -   使用字符流处理文本数据
    -   缓冲流（BufferedInputStream和BufferedOutputStream）的使用
    -   处理文件末尾和异常
3.  **序列化和反序列化：**
    -   了解序列化的概念和用途
    -   实现Serializable接口
    -   使用ObjectInputStream和ObjectOutputStream进行对象的序列化和反序列化
    -   处理版本控制和兼容性
    -   自定义序列化和反序列化行为
4.  **NIO（New I/O）：**
    -   学习Java的NIO库，包括通道（Channel）和缓冲区（Buffer）
    -   非阻塞IO
    -   通道和缓冲区的读写操作
    -   使用Selector实现多路复用
    -   文件锁定和内存映射
5.  **异常处理和资源管理：**
    -   处理文件操作中的异常，如文件不存在、权限问题等
    -   使用try-with-resources来管理文件流的关闭
    -   处理流操作的异常
6.  **文件操作最佳实践：**
    -   了解最佳的文件操作实践，如避免硬编码文件路径、处理异常情况、关闭文件流等
7.  **使用外部库：**
    -   学习如何使用外部库，如Apache Commons IO，以简化文件操作任务

---

``` sh title="生成文件夹目录的 sh 脚本"
#!/bin/bash

# Define an array of learning aspects
aspects=("File-Reading-and-Writing" "Streams-InputStream-and-OutputStream" "Serialization-and-Deserialization" "NIO" "Exception-Handling-and-Resource-Management" "Best-Practices-for-File-Operations" "Using-External-Libraries")

# Loop to create folders
for i in {1..7}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

