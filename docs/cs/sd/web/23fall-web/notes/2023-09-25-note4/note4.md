---
Date: Mon Sep 25 07:49:14 CST 2023
---

# Note 4

!!! abstract

-   通过 sql 脚本快速恢复数据库环境
-   深入了解 session 的概念
-   什么是 servlet (控制器)?
-   什么是 JSTL？



```html title="index.jsp"
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
```

el 表达式？？



---

### 1.5 ServletLogin.java 用户登录控制器

| 属性           | 值                                                           |
| -------------- | ------------------------------------------------------------ |
| 文件名         | `ServletLogin.java`                                          |
| 所属包         | `cn.network.shop.user`                                       |
| 处理的请求路径 | `/login`                                                     |
| 重写方法       | `doPost()`                                                   |
| 参数获取       | 从登录表单获取参数 name 和 password                          |
| 调用方法       | UserService 的 loginCheck 方法                               |
| 登录成功处理   | 如果返回的 `User` 对象不为空，将其存入 `session`，然后跳转至首页 |
| 登录失败处理   | 如果返回的 `User` 对象为空，以键名 `loginErrorText` 存储登录失败信息至 `request`，然后转发至首页 |

``` java
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * This servlet handles user login.
 */
@WebServlet("/login")
public class ServletLogin extends HttpServlet {

    /**
     * Handles the POST request for user login.
     *
     * @param request  The HTTP request object.
     * @param response The HTTP response object.
     * @throws ServletException If a servlet-specific error occurs.
     * @throws IOException      If an I/O error occurs.
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 1. Retrieve parameters 'name' and 'password' from the login form.
        String name = request.getParameter("name");
        String password = request.getParameter("password");

        // 2. Call the loginCheck method of UserService.
        UserService userService = new UserService();
        User user = userService.loginCheck(name, password);

        if (user != null) {
            // Login successful
            // 3. If the returned User object is not null, store it in the session and redirect to the homepage.
            HttpSession session = request.getSession();
            session.setAttribute("user", user);
            response.sendRedirect("/index.jsp"); // Assuming the URL for the homepage is 'index.jsp'.
        } else {
            // Login failed
            // 3. If the returned User object is null, store the login error message in the request and forward to the homepage.
            request.setAttribute("loginErrorText", "Login failed. Please check your username and password.");
            request.getRequestDispatcher("/index.jsp").forward(request, response);
        }
    }
}
```

### 1.6 修改首页

1.   修改导航栏右侧导航信息
2.   

#### 1.6.1 修改右侧导航栏

-   如果已登录，则显示其 `realName` 值，此处设计一个下拉菜单，有菜单项“注销”，点击此项，将发出 `logout` 请求。
-   如果没有登录，则显示登录和注册按钮。
-   登录失败返回处理。

 ``` html title="index.jsp: navbar with dropdowns"
 <!-- navbar with dropdowns -->
 <ul class="nav navbar-nav navbar-right">
     <c:if test="${user eq null}">
         <li><a href="#"><span class="glyphicon glyphicon-user"></span> 注册</a></li>
         <li><a href="#" data-toggle="modal" data-target="#loginModal"><span
                 class="glyphicon glyphicon-log-in"></span> 登录</a></li>
     </c:if>
     <c:if test="${user ne null}">
         <li class="dropdown">
             <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true"
                aria-expanded="false"><span class="glyphicon glyphicon-user"></span> ${ user.realName } <span
                     class="caret"></span></a>
             <ul class="dropdown-menu">
                 <li><a href="logout"><span class="glyphicon glyphicon-log-out"></span> 注销</a></li>
             </ul>
         </li>
     </c:if>
 </ul>
 <!-- dropdowns end --> 
 ```

#### 1.6.2 模态框中显示登录失败的错误信息

在 `<div class="modal-body">` 标签内添加以下标签内容：

``` html
<div class="form-group">
    <div class="col-sm-offset-2 col-sm-10">
        <label style="color: red;">${ loginErrorText }</label>
    </div>
</div>
```

#### 1.6.3 弹出模态框

在 `</body>` 标签前添加 java 脚本

``` jsp
<!-- 弹出模态框 -->
<%
    if (request.getAttribute("loginErrorText") != null) {
        out.print("<script>$('#loginModal').modal('show');</script>");
    }
%>
```

*[JSTL]: Java Server Pages™ Standard Tag Library
