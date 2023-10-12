---
Date: Mon Oct  9 07:53:40 CST 2023
---

# Note 5. 

## 2.1 添加注册模态框

## 2.2 添加注册方法

UserService.java

public static void add(User user)

public static void register(User user)

0.   使用 try catch 捕捉异常
     1.   Exception e
     2.   e.printStackTrace()

1.   连接数据库

2.   编写 sql 语句：`insert into user(name, password, relaname, address) values(?, md5(?), ?, ?);`

     1.   约定俗称，db 字段命名为小写字母

     2.   创建**预编译对象**：`PrepareStatement ps  = connection.prepareStatement()`

     3.   赋值：`ps.setString(parameterIndex: 1, user.getName())`

          1.   getPassword()
          2.   getRealName()
          3.   getAddress()

     4.   执行 sql 语句：`ps.executeUpdate()`

     5.   释放所有资源

          1.   `ps.close()`
          2.   `connection.close()`

          

## 2.3 新建用户注册控制器

处理对应的 HTTP 请求



## 2.4 修改首页

注册成功后，激活登录模态框，在登录模态框上添加注册成功的提示信息，提示用户进行登录。

``` jsp
<%

// Display login error message in a modal if it exists
if (request.getAttribute("loginErrorText") != null) {
    out.print(" <script>$('#loginModal').modal('show');</script> ");
}

// Display registration success message in a modal if it exists
if (request.getAttribute("registerSuccessText") != null) {
    out.print(" <script>$('#loginModal').modal('show');</script> ");
}

%>
```





## 2.5 注册表单数据验证

1.   账号要求 4-12 个字母、数字和下划线的组合。
2.   密码要求 6-14 个字母、数字和下划线的组合。
3.   重复密码要求 6~14 个字母、数字和下划线的组合。 
4.   两次输入的密码要一致。
5.   姓名至少 2 个汉字。



1.  账号要求 4-12 个字母、数字和下划线的组合： 正则表达式：

    `^[a-zA-Z0-9_]{4,12}$`

2.  密码要求 6-14 个字母、数字和下划线的组合： 正则表达式：`^[a-zA-Z0-9_]{6,14}$`

3.  重复密码要求 6~14 个字母、数字和下划线的组合： 正则表达式：`^[a-zA-Z0-9_]{6,14}$`

4.  `^[\u4e00-\u9fa5]{2,}$`





```
$(document).ready(function () {
$("#name1").blur(function() {
	if (//.test($(name1).val()) == false)
		alert("")
	if (//.test($(password1).val()) == false)
	 	alert()
})
})
```



```
$(function () {

})
```

``` js
<script>
    $(document).ready(function () {
        $("#name1").blur(function () {
            if (/^[a-zA-Z0-9_]{4,12}$/.test($("#name1").val()) == false)
                alert("账号要求 4-12 个字母、数字和下划线的组合。")
        })
        $("#password1").blur(function () {
            if (/^[a-zA-Z0-9_]{6,14}$/.test($("#password1").val()) == false)
                alert("密码要求 6-14 个字母、数字和下划线的组合。")
        })
        $("#password2").blur(function () {
            if (/^[a-zA-Z0-9_]{6,14}$/.test($("#password2").val()) == false)
                alert("密码要求 6-14 个字母、数字和下划线的组合。")
            if ($("#password1").val() != $("#password2").val())
                alert("两次输入的密码要一致。")
        })
        $("#realName").blur(function () {
            if (/^[\u4e00-\u9fa5]{2,}$/.test($("#realName").val()) == false)
                alert("姓名至少 2 个汉字。")
        })
    })
</script>
```

