# Navicat Premium

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