# Assign 2. 通关攻略

## 1. 🐍 蟒蛇

``` python title="python.py" linenums="1"
import turtle as t
t.setup(.5, .5, None, None)
t.title("蟒蛇")
t.pensize(20)
t.pencolor("red")
t.pu()
t.bk(300)
t.pd()
t.seth(-40)
for _ in range(4):
    t.circle(40, 80)
    t.circle(-40, 80)
t.circle(40, 40)
t.fd(40)
t.circle(16, 180)
t.fd(40 * 2/3)
t.done()
```

![image-20230916215811483](./assets/image-20230916215811483.png)

## 2. 🌞 太阳花 🌻

``` python title="star.py" linenums="1"
from turtle import *

length = 400
angle = 170
speed(0)

setup(.5, .5, None, None)
title("🌻 太阳花 | 🌞 | ✨ 星星")
color("green", "red")
begin_fill()
while True:
    fd(length)
    lt(angle)
    if abs(pos()) < 1:
        break
end_fill()
done()
```

![image-20230916221709640](./assets/image-20230916221709640.png)

## 3. ❤️ 爱心

``` python title="heart.py" linenums="1"
from turtle import *

setup(.5, .5, None, None)
title("❤️ 爱心")
speed(0)
bgcolor('lightpink')
pensize(3)

def curve():
    for _ in range(200):
        rt(1)
        fd(1)
        
color('red', 'red2')
begin_fill()

lt(140)
fd(111.65)
curve()
lt(120)
curve()
fd(111.65)
end_fill()

hideturtle()
done()
```

![image-20230916224326323](./assets/image-20230916224326323.png)

## 4. 风轮

使用 turtle 库，绘制一个风轮效果，其中，每个风轮内角为 45 度，风轮边长 150 像素。

---

``` python title="WindMill.py" linenums="1"
from turtle import *

radius = 200
angle = 45

setup(.5, .5, None, None)
title("风轮")

lt(angle)

for _ in range(4):
    fd(radius)
    lt(90)
    circle(radius, angle)
    lt(90)
    fd(radius)
    rt(180 - angle)

done()

```

![image-20230916222204272](./assets/image-20230916222204272.png)
