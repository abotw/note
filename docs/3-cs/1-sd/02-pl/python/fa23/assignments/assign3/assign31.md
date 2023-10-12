# Assign 3: 通关攻略
## H1 天天向上的力量

一年 365，每天进步千分之一，累计能进步多少？
一年 365，每天退步千分之一，累计能退步多少？

``` python title="daily_progress.py" linenums="1"
# 初始值
initial_value = 1.0

# 每天进步或退步千分之一
progress_rate = 0.001

# 计算一年内的累计进步或退步
days_in_year = 365
total_progress = initial_value * ((1 + progress_rate) ** days_in_year - 1)

print("一年每天进步或退步千分之一，累计进步或退步：", total_progress)
```
输出：

``` sh
一年每天进步或退步千分之一，累计进步或退步： 0.4402513134295205
```

## H2 工作日的力量

---抛弃的数学思维，引入的计算思维(是抽象和自动化思维)

一年 365 天，一周 5 个工作日，每天进步 1%; 一年 365 天，一周 2 个休息日，每天退步 1%; 这种工作日的力量，如何哪? 将过程抽象，用计算机模拟这个工作，即计算思维。

``` python title="workday_power.py" linenums="1"
# 初始值
initial_value = 1.0

# 每天进步千分之一
workday_progress_rate = 0.01

# 每天退步千分之一
weekend_regress_rate = 0.01

# 一年365天，一周5个工作日，2个休息日
days_in_year = 365
workdays_per_week = 5
weekend_days_per_week = 2

# 计算一年内的累计进步
total_progress = 0

for day in range(days_in_year):
    if day % 7 < workdays_per_week:
        total_progress += initial_value * workday_progress_rate
    else:
        total_progress -= initial_value * weekend_regress_rate

print("一年工作日进步1%，休息日退步1%，累计进步：", total_progress)
```
## H3 天天向上的力量改进

工作日模式要努力到什么水平，才能与每天努力 1%一样呢？

A 君：一年 365 天，每天进步 1%，不停歇

B 君：一年 365 天，每周工作 5 天，休息 2 天，休息日下降 1%，那么工作日要努力多少才能达到 A 君努力的水平? 因为计算机的运算速度快，可以采用“笨办法”——试错。

设 B 君工作日的努力值为 X (初始值可以从 1%)，计算出来看是否达到 A 君的努力值，如果没有达到，继续增加努力值(每次增加千分之一)，直到达到 A 君的努力值。

``` python title="improved_daily_progress.py" linenums="1"
# 初始值和增长率的设置
a_initial_value = 1.0          # a的初始值
a_progress_rate = 0.01         # a的增长率
days_in_year = 365             # 一年的天数

# 使用复利计算a的总进展
a_total_progress = a_initial_value * ((1 + a_progress_rate) ** days_in_year)

# 输出a的总进展
# print(f"{a_total_progress}")

# 初始值和进展/退步率的设置
b_initial_value = 1.0          # b的初始值
b_progress_rate = 0.01         # b的进展率
b_regress_rate = 0.01          # b的退步率
b_total_progress = 0           # b的总进展初始化为0
day = 1                         # 初始化日期
increase = 0.001               # 增加b的进展率的增量

# 当b的总进展小于a的总进展时，执行循环
while b_total_progress < a_total_progress:
    b_total_progress = 0       # 重置b的总进展为0
    b_progress_rate += increase  # 增加b的进展率

    # 计算一年内的每一天
    for day in range(days_in_year + 1):
        if day % 7 <= 5:
            # 如果是工作日（星期一到星期五），增加b的总进展
            b_total_progress += b_initial_value * b_progress_rate
        else:
            # 如果是周末（星期六和星期日），减少b的总进展
            b_total_progress -= b_initial_value * b_regress_rate

# 输出最终的b的进展率，并以百分比形式显示
print(f"{b_progress_rate * 100:.2f}%")

```
输出：

```
0.1220000000000001
```



## H4 平方根格式化

4. 平方根格式化—格式化输出

获得用户输入的一个整数 a，计算 a 的平方根，保留小数点后 3 位，并打印 输出。输出结果采用宽度 30 个字符、右对齐输出、多余字符采用加号(+)填充。

```python title="square_root_formatting.py" linenums="1"
# 获取用户输入的整数
a = int(input("请输入一个整数："))

# 计算平方根
sqrt_a = (a ** 0.5)

# 格式化输出
formatted_output = f"{sqrt_a:+30.3f}"

print("平方根格式化输出：", formatted_output)
```

``` python
def calculate_effort_a(days, daily_increase_percentage):
    effort_a = 1.0
    for _ in range(days):
        effort_a *= (1 + daily_increase_percentage / 100)
    return effort_a

def calculate_effort_b(work_days_per_week, rest_days_per_week, work_day_increase_percentage, rest_day_decrease_percentage):
    days_per_year = 365
    work_days_per_year = (days_per_year // 7) * work_days_per_week
    rest_days_per_year = days_per_year - work_days_per_year

    effort_a = calculate_effort_a(days_per_year, 1)
    print(f"{effort_a}")
    effort_b = 1.0
    while True:
        for _ in range(work_days_per_year):
            effort_b *= (1 + work_day_increase_percentage / 100)
        for _ in range(rest_days_per_year):
            effort_b *= (1 - rest_day_decrease_percentage / 100)

        if effort_b >= effort_a:
            break
        else:
            effort_b = 1.0  # 重置B君的努力值
            work_day_increase_percentage += 0.001  # 增加工作日的努力值

    return work_day_increase_percentage

result = calculate_effort_b(5, 2, 1, 1)

print(f"B君工作日的努力值 X 为: {result:.3f}%")

```

