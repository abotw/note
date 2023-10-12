# Bootstrap 3.4.1

-   [Bootstrap](https://getbootstrap.com/)
    -   [v3.4.1](https://getbootstrap.com/docs/3.4/)

---

## 1. Getting started

-   **Ref**: [Bootstrap 环境安装 @runoob.com](https://www.runoob.com/bootstrap/bootstrap-environment-setup.html)

``` html title="配置 Bootstrap 环境"
<head>
  
    <%--设置显示宽度为设备的屏幕的宽度--%>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <%--引入样式表--%>
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">

    <%--引入 jQuery，必须位于引 bootstrap.min.js 之前--%>
    <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>

    <%--引入 bootstrap 脚本--%>
    <script src="bootstrap/js/bootstrap.min.js"></script>
      
</head>
```

### Download

-   [Download Bootstrap-3.4.1-dist.zip](https://github.com/twbs/bootstrap/releases/download/v3.4.1/bootstrap-3.4.1-dist.zip)

### What's included

!!! Warning "jQuery required"

    Please note that **all JavaScript plugins require jQuery** to be included, as shown in the [starter template](https://getbootstrap.com/docs/3.4/getting-started/#template). [Consult our `bower.json`](https://github.com/twbs/bootstrap/blob/v3-dev/bower.json) to see which versions of jQuery are supported.
    
    ``` json
    {
      "dependencies": {
        "jquery": "1.9.1 - 3"
      }
    }
    ```

#### Precompiled Bootstrap

>   We provide compiled CSS and JS (`bootstrap.*`), as well as compiled and minified CSS and JS (`bootstrap.min.*`).

```
bootstrap/
├── css/
│   ├── bootstrap.css
│   ├── bootstrap.css.map
│   ├── bootstrap.min.css
│   ├── bootstrap.min.css.map
│   ├── bootstrap-theme.css
│   ├── bootstrap-theme.css.map
│   ├── bootstrap-theme.min.css
│   └── bootstrap-theme.min.css.map
├── js/
│   ├── bootstrap.js
│   └── bootstrap.min.js
└── fonts/
    ├── glyphicons-halflings-regular.eot
    ├── glyphicons-halflings-regular.svg
    ├── glyphicons-halflings-regular.ttf
    ├── glyphicons-halflings-regular.woff
    └── glyphicons-halflings-regular.woff2
```

### Basic Template

``` html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <title>Bootstrap 101 Template</title>

    <!-- Bootstrap -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/css/bootstrap.min.css" integrity="sha384-HSMxcRTRxnN+Bdg0JdbxYKrThecOKuH5zCYotlSAcp1+c8xmyTe9GYg1l9a69psu" crossorigin="anonymous">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://cdn.jsdelivr.net/npm/html5shiv@3.7.3/dist/html5shiv.min.js"></script>
      <script src="https://cdn.jsdelivr.net/npm/respond.js@1.4.2/dest/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>
    <h1>Hello, world!</h1>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://code.jquery.com/jquery-1.12.4.min.js" integrity="sha384-nvAa0+6Qg9clwYCGGPpDQLVpLNn0fRaROjHqs13t4Ggj3Ez50XnGQqc/r8MhnRDZ" crossorigin="anonymous"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.min.js" integrity="sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd" crossorigin="anonymous"></script>
  </body>
</html>
```



---

## 2. Components

-   [Components](https://getbootstrap.com/docs/3.4/components/)
    -   [Glyphicons](https://getbootstrap.com/docs/3.4/components/#glyphicons)
        -   glyphicon glyphicon-plus
        -   glyphicon glyphicon-user
        -   glyphicon glyphicon-log-in
        -   glyphicon glyphicon-log-out

    -   [Navbar](https://getbootstrap.com/docs/3.4/components/#navbar)
        -   [Bootstrap 导航栏 @ruboob.com](https://www.runoob.com/bootstrap/bootstrap-navbar.html): 1. 响应式的导航栏 2. 结合图标的导航链接
        -   [Default navbar](https://getbootstrap.com/docs/3.4/components/#navbar-default)
        -   [Component alignment](https://getbootstrap.com/docs/3.4/components/#navbar-component-alignment)
        -   [Inverted navbar](https://getbootstrap.com/docs/3.4/components/#navbar-inverted)
        -   [Fixed to top](https://getbootstrap.com/docs/3.4/components/#navbar-fixed-top)
    -   [Dropdowns](https://getbootstrap.com/docs/3.4/components/#dropdowns)
-   [JavaScript](https://getbootstrap.com/docs/3.4/javascript/)
    -   [Modal](https://getbootstrap.com/docs/3.4/javascript/#modals)
    -   [Carousel](https://getbootstrap.com/docs/3.4/javascript/#carousel)

---

## Appendix

### 1. 在 Java Web 中使用 Bootstrap 框架

1.   下载并解压 `bootstrap-x.x.x-dist.zip`.
2.   将解压后的文件夹复制到 `project/web/` 下.
