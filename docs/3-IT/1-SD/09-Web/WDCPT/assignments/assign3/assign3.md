# Assignment 3.

## 3-1 Bootstrap Carousel & Modal

*参见：<https://getbootstrap.com/docs/3.4/javascript/#carousel>*

*参见：<https://getbootstrap.com/docs/3.4/javascript/#modals>*

![Snipaste_2023-09-18_08-47-29](./assets/Snipaste_2023-09-18_08-47-29.png)

![Snipaste_2023-09-18_08-47-39](./assets/Snipaste_2023-09-18_08-47-39.png)

### Codes

``` html linenums="1"
<head>
    <style>
        body {
            padding-top: 50px;
        }

        #myCarousel img {
            width: 100%;
        }
    </style>
</head>
```

``` html linenums="1" hl_lines="6"
<body>
<!-- nav start -->
<nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <div class="collapse navbar-collapse" id="example-navbar-collapse">
            <ul class="nav navbar-nav navbar-right">
                <li><a href="#" data-toggle="modal" data-target="#login-modal">
                  <span class="glyphicon glyphicon-log-in"></span> 登录</a></li>
            </ul>
        </div>
    </div>
</nav>
<!-- nav end -->
<!-- carousel start -->
<div id="myCarousel" class="carousel slide">
    <!-- 轮播（Carousel）指标 -->
    <ol class="carousel-indicators">
        <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
        <li data-target="#myCarousel" data-slide-to="1"></li>
        <li data-target="#myCarousel" data-slide-to="2"></li>
        <li data-target="#myCarousel" data-slide-to="3"></li>
        <li data-target="#myCarousel" data-slide-to="4"></li>
    </ol>
    <!-- 轮播（Carousel）项目 -->
    <div class="carousel-inner">
        <div class="item active">
            <img decoding="async" src="images/banner1.jpg" alt="First slide">
            <div class="carousel-caption">Banner 1</div>
        </div>
        <div class="item">
            <img decoding="async" src="images/banner2.jpg" alt="Second slide">
            <div class="carousel-caption">Banner 2</div>
        </div>
        <div class="item">
            <img decoding="async" src="images/banner3.jpg" alt="Third slide">
            <div class="carousel-caption">Banner 3</div>
        </div>
        <div class="item">
            <img decoding="async" src="images/banner4.jpg" alt="Fourth slide">
            <div class="carousel-caption">Banner 4</div>
        </div>
        <div class="item">
            <img decoding="async" src="images/banner5.jpg" alt="Fifth slide">
            <div class="carousel-caption">Banner 5</div>
        </div>
    </div>
    <!-- 轮播（Carousel）导航 -->
    <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
    </a>
    <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
    </a>
</div>
<!-- carousel end -->
<!-- modal start -->
<!-- 模态框（Modal） -->
<div class="modal fade" id="login-modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                    &times;
                </button>
                <h4 class="modal-title" id="myModalLabel">
                    用户登录
                </h4>
            </div>
            <div class="modal-body">
                <!-- login-form start -->
                <form class="form-horizontal" role="form" action="login" method="post">
                    <div class="form-group">
                        <label for="name" class="col-sm-2 control-label">账号: </label>
                        <div class="col-sm-10">
                            <input type="text" class="form-control" id="name" placeholder="请输入账号..."
                                   value="${cookieNameString}">
                        </div>
                    </div>
                    <div class="form-group">
                        <label for="password" class="col-sm-2 control-label">密码: </label>
                        <div class="col-sm-10">
                            <input type="password" class="form-control" id="password" placeholder="请输入密码..."
                                   value="${cookiePasswordString}">
                        </div>
                    </div>
                    <div class="form-group">
                        <div class="col-sm-offset-2 col-sm-10">
                            <div class="checkbox">
                                <label>
                                    <input type="checkbox">请记住我
                                </label>
                            </div>
                        </div>
                    </div>
                </form>
                <!-- login-form end -->
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-default" data-dismiss="modal">关闭
                </button>
                <button type="submit" class="btn btn-primary">
                    登录
                </button>
            </div>
        </div><!-- /.modal-content -->
    </div><!-- /.modal -->
</div>
<!-- modal end-->
</body>
```

## 3-2

-   数据库连接类 DB
-   文件名：DB.java
-   所属包：`cn.network.shop.util.DB`

`src`



文件名：User.java

cn.network.shop.user.User
