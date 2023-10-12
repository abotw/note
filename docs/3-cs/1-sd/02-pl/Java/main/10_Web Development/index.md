# 10. Web Development

1.  **Servlets：**
    -   创建Servlets
    -   处理HTTP请求和响应
    -   使用Servlet生命周期方法
    -   数据存储和共享
    -   会话管理和Cookie
2.  **JSP（JavaServer Pages）：**
    -   创建JSP页面
    -   JSP标签和表达式
    -   JSP的动态内容和脚本
    -   JSP的自定义标签
    -   JSP和Servlet的整合

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of Web development aspects
aspects=("Servlets" "JSP-JavaServer-Pages")

# Loop to create folders
for i in {1..2}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

