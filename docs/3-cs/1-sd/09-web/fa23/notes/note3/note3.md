---
date: 2023/09/18
---

# Note 3.

```
.
└── shop
    ├── user
    │   ├── ServletLogin.java
    │   ├── ServletLogout.java
    │   ├── User.java
    │   └── UserService.java
    └── util
        ├── DB.java
        └── DBTest.java
```



1.   新建用户服务类
2.   新建用户登录控制器

---

## 1. `src/util/DB.java`

常用工具类 / 数据库连接类

| Element            | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| Class              | DB                                                           |
| Filename           | DB.java                                                      |
| Package            | cn.network.shop.util                                         |
| Method             | getConnection()                                              |
| Description        | **Returns a Connection object for database connectivity.**   |
| Imports            | - java.sql.Connection                                        |
|                    | - java.sql.DriverManager                                     |
|                    | - java.sql.SQLException                                      |
| Database Driver    | com.mysql.jdbc.Driver // 5.x<br />com.mysql.cj.jdbc.Driver // 8.x |
| Database URL       | jdbc:mysql://localhost:3306/shop?useSSL=false                |
| Database Username  | root                                                         |
| Database Password  | root                                                         |
| Connection Status  | Displays a message when a database connection is made.       |
| Exception Handling | Catches ClassNotFoundException and SQLException.             |

```java title="original code"
package cn.network.shop.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

// 数据库连接类
public class DB {
    public static Connection getConnection() {
        Connection connection = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/shop?useSSL=false", "root", "root");
            System.out.println("已连接数据库...");
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }
}
```

**备注：**

``` java title="for mysql 5.x"
//5.x
Class.forName("com.mysql.jdbc.Driver");
connection= DriverManager.getConnection("jdbc:mysql://localhost:3306/shop", "root", "12345678");
```

``` java title="for mysql 8.x"
//8.x
Class.forName("com.mysql.cj.jdbc.Driver");
connection= DriverManager.getConnection("jdbc:mysql://localhost:3306/shop?useSSL=false&serverTi mezone=Asia/Shanghai&useUnicode=true&characterEncoding=utf-8", "root", "12345678");
```



``` java title="optimized code"
package cn.network.shop.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * A utility class for establishing database connections.
 */
public class DB {
    /**
     * Returns a Connection object for database connectivity.
     *
     * @return A Connection object to interact with the database.
     * @throws SQLException if a database access error occurs.
     */
    public static Connection getConnection() throws SQLException {
        Connection connection = null;
        try {
            // Load the MySQL JDBC driver
            Class.forName("com.mysql.jdbc.Driver");

            // Establish a database connection
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/shop?useSSL=false", "root", "root");

            // Display a message indicating a successful database connection
            System.out.println("Connected to the database...");
        } catch (ClassNotFoundException e) {
            // Handle ClassNotFoundException
            e.printStackTrace();
        }
        return connection;
    }
}
```

## 2. `src/shop/user/User.java`

实体类 / 用户实体类

TODO：利用 IDEA 自动生成所有成员变量对应的 getter 和 setter 方法

| Element          | Description                    |
| ---------------- | ------------------------------ |
| Class            | User                           |
| Filename         | User.java                      |
| Package          | cn.network.shop.user           |
| Member Variables | - id                           |
|                  | - name                         |
|                  | - password                     |
|                  | - role                         |
|                  | - realName                     |
|                  | - address                      |
| Methods          | - getId()                      |
|                  | - setId(int id)                |
|                  | - getName()                    |
|                  | - setName(String name)         |
|                  | - getPassword()                |
|                  | - setPassword(String password) |
|                  | - getRole()                    |
|                  | - setRole(int role)            |
|                  | - getRealName()                |
|                  | - setRealName(String realName) |
|                  | - getAddress()                 |
|                  | - setAddress(String address)   |

## `shop/user/UserService.java`

用户服务类

| Element        | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Class          | UserService                                                  |
| Filename       | UserService.java                                             |
| Package        | cn.network.shop.user                                         |
| Method         | - loginCheck(String name, String password)                   |
| Description    | Performs a login check by retrieving user data from the database based on the provided username (name) and password. If a match is found, it returns a complete User object; otherwise, it returns null. |
| Parameters     | - name: Account username                                     |
|                | - password: Account password                                 |
| Return Value   | User object if a match is found, otherwise null.             |
| Method Details | - Establishes a database connection using `DB.getConnection()`. |
|                | - Prepares a SQL query with placeholders for username and password. |
|                | - Sets the username and password values in the query.        |
|                | - Executes the query and retrieves the result set.           |
|                | - Reads data from the result set and populates a User object. |
|                | - Closes the result set, prepared statement, and database connection. |
|                | - Handles potential SQLExceptions by printing the stack trace. |

``` java title="optimized code"
package cn.network.shop.user;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import cn.network.shop.util.DB;

/**
 * A service class for user-related operations.
 */
public class UserService {
    /**
     * Performs a login check by retrieving user data from the database based on the provided username and password.
     *
     * @param name     The account username.
     * @param password The account password.
     * @return User object if a match is found, otherwise null.
     */
    public static User loginCheck(String name, String password) {
        User user = null;
        try {
            // 1. Establish a database connection
            Connection connection = DB.getConnection();

            // 2. Create a prepared statement
            String sql = "SELECT * FROM user WHERE name=? AND password=md5(?)";
            PreparedStatement ps = connection.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, password);

            // 3. Execute the SQL query
            ResultSet rs = ps.executeQuery();

            // 4. Read and populate user data
            if (rs.next()) {
                user = new User();
                user.setId(rs.getInt("id"));
                user.setName(rs.getString("name"));
                user.setPassword(rs.getString("password"));
                user.setRole(rs.getInt("role"));
                user.setRealName(rs.getString("realname"));
                user.setAddress(rs.getString("address"));
            }

            // 5. Close resources
            rs.close();
            ps.close();
            connection.close();
        } catch (SQLException e) {
            // Handle SQLException by printing the stack trace
            e.printStackTrace();
        }

        return user;
    }
}
```



*[JDBC]: Java DataBase Connectivity

