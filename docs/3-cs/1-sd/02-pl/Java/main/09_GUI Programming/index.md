# 09. GUI Programming

1.  **Swing或JavaFX选择：**
    -   了解Swing和JavaFX的特点和适用场景
    -   选择适合你项目的GUI工具包
2.  **Swing GUI编程：**
    -   创建Swing窗体和组件
    -   布局管理
    -   事件处理
    -   自定义绘图和外观
3.  **JavaFX GUI编程：**
    -   创建JavaFX应用程序
    -   JavaFX组件和控件
    -   布局管理器
    -   图形和动画
    -   事件处理

---

``` sh title="生成对应文件目录的 sh 脚本"
#!/bin/bash

# Define an array of GUI programming aspects
aspects=("Swing-or-JavaFX-Selection" "Swing-GUI-Programming" "JavaFX-GUI-Programming")

# Loop to create folders
for i in {1..3}
do
    folder_name="${i}_${aspects[$i-1]}"
    mkdir "$folder_name"
done

```

