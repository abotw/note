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