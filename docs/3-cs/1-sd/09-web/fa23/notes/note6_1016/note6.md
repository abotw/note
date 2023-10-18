---
Date: Mon Oct 16 08:07:57 CST 2023
---

# 第 3 章：分类模块

## 3.1 新建分类实体类 Category

-   文件：`cn.network.shop.category.Category`

-   成员变量

    -   `int id ` 分类编号

    -   `String name` 分类名称

- 方法：所有成员变量的 getter 和 setter 方法

```


```

## 3.2 新建分类业务类 CategoryService

-   文件：`cn.network.shop.category.CategoryService`
-   方法：
    -   ` public static List<Category> getCategories()` 获得所有的分类对象

## 3.3 修改首页

在首页”index.jsp”中的导航栏中显示所有的分类。

### 3.3.1 添加 Java 脚本

提示:<% %>内添加

```jsp
List<Category> categories = CategoryService.getCategories();
request.setAttribute("categories",categories);
```



```jsp
<%
    // 读取分类数据
    List<Category> categories = CategoryService.getCategories();
    request.setAttribute("categories", categories);
%>
```



### 3.3.2 在导航栏中添加标签

提示:在“首页”所在的 li 标签下面添加

```html
<c:forEach var="category" items="${categories}">
<li><a href="#">
${category.name}
</a></li>
</c:forEach>
```



```html
商品分类导航
<li><a href="#">男装 <span class="glyphicon glyphicon-plus"></span></a></li>
<li><a href="#">女装 <span class="glyphicon glyphicon-plus"></span></a></li>
<li><a href="#">童装 <span class="glyphicon glyphicon-plus"></span></a></li>
```

