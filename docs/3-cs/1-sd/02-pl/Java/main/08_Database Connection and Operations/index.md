# 08. Database Connection and Operations

1.  **JDBC（Java Database Connectivity）：**
    -   连接数据库
    -   执行SQL查询
    -   处理结果集
    -   事务管理
    -   使用连接池
2.  **数据库查询和更新：**
    -   SQL语句编写
    -   查询数据库数据
    -   更新数据库数据
    -   处理事务
    -   处理异常和错误

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of database connection and operations aspects
aspects=("JDBC-Java-Database-Connectivity" "Database-Query-and-Updates")

# Loop to create folders
for i in {1..2}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

