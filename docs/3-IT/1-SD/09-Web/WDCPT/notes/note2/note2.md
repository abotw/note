# Note 2. 230911

zoom it , windows

## 《网上商城》讲义

### 一、分析

1.   普通会员
     1.   前台功能模块
          1.   商品展示
          2.   商品购物
          3.   用户个人信息管理
          4.   订单查询
2.   管理员
     1.   后台功能模块
          1.   用户管理
          2.   类别管理
          3.   商品管理
          4.   订单管理

### 二、设计

#### 1. 数据库设计

**用户表**



**分类表**

**商品表**

**订单表**

**订单项**

### 三、编码

### 1. 登录模块

https://www.runoob.com/bootstrap/bootstrap-environment-setup.html

https://www.runoob.com/bootstrap/bootstrap-glyphicons.html

https://www.runoob.com/bootstrap/bootstrap-navigation-elements.html



*[ORM]: Object Relational Model

## Navicat Premium

文件 -> 新建连接 -> MySQL -> 

链接名：mysql57

用户名：root

密码：root

端口：3306

主机名或IP地址：localhost



新建数据库：

数据库名：shop

字符集：utf8 -- UTF-8 Unicode

排序规则：utf8_general_ci



新建表：

栏位，添加栏位

id int 自增 不是 null

name varchar 20

role int 默认 0

real_name  20

address 100



查询 - 新建查询 - 查询编辑器 - 运行 - 右键，运行已选择的

``` sql
use shop;
create table category(
  id int auto_increment primary key,
  `name` varchar(20) unique not null
)
```

``` sql
#
--
```



索引：

idx_name - 栏位 - 索引类型：unique







``` sql title="数据库设计"
-- 创建用户表
CREATE TABLE user (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(20) UNIQUE NOT NULL,
    password VARCHAR(100) NOT NULL,
    role INT DEFAULT 0,
    realname VARCHAR(20),
    address VARCHAR(100)
);

-- 创建分类表
CREATE TABLE category (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(20) UNIQUE NOT NULL
);

-- 创建商品表
CREATE TABLE product (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) UNIQUE NOT NULL,
    price DOUBLE,
    image VARCHAR(255),
    categoryid INT,
    FOREIGN KEY (categoryid) REFERENCES category(id)
);

-- 创建订单表
CREATE TABLE saleorder (
    id INT AUTO_INCREMENT PRIMARY KEY,
    userid INT,
    odate DATETIME DEFAULT CURRENT_TIMESTAMP,
    status INT,
    FOREIGN KEY (userid) REFERENCES user(id)
);

-- 创建订单项表
CREATE TABLE orderitem (
    id INT AUTO_INCREMENT PRIMARY KEY,
    productid INT,
    count INT NOT NULL,
    orderid INT,
    FOREIGN KEY (productid) REFERENCES product(id),
    FOREIGN KEY (orderid) REFERENCES saleorder(id)
);

```



数据库 - 右键，转储 SQL 文件

``` sql
-- 创建数据库
DROP DATABASE IF EXISTS `shop`;
CREATE DATABASE shop CHARACTER SET utf8;
USE shop;
```

恢复数据库

数据库  - 右键，运行 sql 文件

## 打包



## MySQL

mysql: root

```
==> Caveats
==> mysql@5.7
We've installed your MySQL database without a root password. To secure it run:
    mysql_secure_installation

MySQL is configured to only allow connections from localhost by default

To connect run:
    mysql -uroot

mysql@5.7 is keg-only, which means it was not symlinked into /opt/homebrew,
because this is an alternate version of another formula.

If you need to have mysql@5.7 first in your PATH, run:
  echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc

For compilers to find mysql@5.7 you may need to set:
  export LDFLAGS="-L/opt/homebrew/opt/mysql@5.7/lib"
  export CPPFLAGS="-I/opt/homebrew/opt/mysql@5.7/include"

To restart mysql@5.7 after an upgrade:
  brew services restart mysql@5.7
Or, if you don't want/need a background service you can just run:
  /opt/homebrew/opt/mysql@5.7/bin/mysqld_safe --datadir\=/opt/homebrew/var/mysql
```

``` sh
$ mysql_secure_installation
zsh: command not found: mysql_secure_installation
$ echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc # If you need to have mysql@5.7 first in your PATH
$ mysql_secure_installation

Securing the MySQL server deployment.

Enter password for user root:
Error: Can't connect to local MySQL server through socket '/tmp/mysql.sock' (2)
$ systemctl status mysql
zsh: command not found: systemctl
$ sudo brew services start mysql
$ brew services list
$ mysql.server start

```

``` sh
brew install mysql@5.7
brew services restart mysql@5.7
/opt/homebrew/opt/mysql@5.7/bin/mysqld_safe --datadir=/opt/homebrew/var/mysql
echo 'export PATH="/opt/homebrew/opt/mysql@5.7/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
which mysql
/opt/homebrew/opt/mysql@5.7/bin/mysql
mysql --version
mysql  Ver 14.14 Distrib 5.7.43, for osx10.18 (x86_64) using  EditLine wrapper
mysql.server
Usage: mysql.server  {start|stop|restart|reload|force-reload|status}  [ MySQL server options ]
```

2023-09-11T01:55:14.588724Z 1 [Note] A temporary password is generated for root@localhost: rcx2Ga5Pkw*W

If you lose this password, please consult the section How to Reset the Root Password in the MySQL reference manual.

``` sh
alias mysql=/usr/local/mysql/bin/mysql

echo 'export PATH="/usr/local/mysql/bin/:$PATH"' >> ~/.zshrc
```

---

