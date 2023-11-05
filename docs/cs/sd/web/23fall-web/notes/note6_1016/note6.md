---
Date: Mon Oct 16 08:07:57 CST 2023
---

# 第 3 章：分类模块

## 3.1 新建分类实体类 Category

### 成员变量及其 getter & setter 方法

| 成员变量 | 数据类型 | 描述     |
| -------- | -------- | -------- |
| `id`     | 整型     | 分类编号 |
| `name`   | 字符串   | 分类名称 |

```java title="src/cn/network/shop/category/Category.java"
package cn.network.shop.category;

/**
 * 商品分类实体模型，用于表示商城中的商品分类信息。
 * This class represents a category of products in the online shop.
 *
 * @author Monty
 * @version 1.0
 * @since 2023-10-30
 */
public class Category {
    private int id;     // 分类的唯一标识符 (Category ID)
    private String name; // 分类的名称 (Category Name)

    // 获取分类的唯一标识符
    public int getId() {
        return id;
    }

    // 设置分类的唯一标识符
    public void setId(int id) {
        this.id = id;
    }

    // 获取分类的名称
    public String getName() {
        return name;
    }

    // 设置分类的名称
    public void setName(String name) {
        this.name = name;
    }
}

```

## 3.2 新建分类业务类 CategoryService

```java title="src/cn/network/shop/category/CategoryService.java"
package cn.network.shop.category;

import cn.network.shop.util.DB;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 * 商品分类服务类，处理与商品分类相关的业务逻辑。
 * This class provides services to handle business logic related to product categories.
 *
 * @author Monty
 * @version 1.0
 * @since 2023-10-30
 */
public class CategoryService {
    /**
     * 获取所有商品分类的信息。
     * Retrieve all product category information.
     * 从数据库中的分类表中查询数据，将每条记录封装为Category对象，并存储在一个列表中。
     * Query data from the category table in the database, encapsulate each record as a Category object, and store them in a list.
     *
     * @return 包含所有商品分类信息的列表，如果没有分类数据则返回null。
     * A list containing all product category information, or null if there is no category data.
     */
    public static List<Category> getCategories() {
        List<Category> categories = null;
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // 1. 建立数据库连接
            connection = DB.getConnection();

            // 2. 创建SQL语句
            String sql = "SELECT * FROM category";
            statement = connection.createStatement();

            // 3. 执行SQL查询
            resultSet = statement.executeQuery(sql);

            // 4. 遍历查询结果
            while (resultSet.next()) {
                // 4.0 初始化分类列表
                if (categories == null) {
                    categories = new ArrayList<>();
                }

                // 4.1 创建分类对象并填充数据
                Category category = new Category();
                category.setId(resultSet.getInt("id"));
                category.setName(resultSet.getString("name"));

                // 4.2 添加到分类列表
                categories.add(category);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // 5. 释放数据库资源
            try {
                if (resultSet != null) {
                    resultSet.close();
                }
                if (statement != null) {
                    statement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        return categories;
    }
}

```

## 3.3 修改首页

在首页”index.jsp”中的导航栏中显示所有的分类。

### 在首页获取商品分类列表数据

```jsp
<%-- 开始：获取商品分类列表并存储在请求属性中 --%>
<%
    // 调用 CategoryService 类的 getCategories 方法获取商品分类列表
    List<Category> categories = CategoryService.getCategories();
    // 将商品分类列表存储在请求属性中，以便在首页访问
    request.setAttribute("categories", categories);
%>
<%-- 结束：获取商品分类列表并存储在请求属性中 --%>
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

