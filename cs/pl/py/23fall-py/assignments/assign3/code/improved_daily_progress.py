# A 君每天进步1%
a_progress_rate = 0.01

# B 君每周工作5天，休息2天，休息日退步1%
b_workday_progress_rate = 0.01
b_weekend_regress_rate = 0.01

# 模拟
days_in_year = 365
a_total_progress = 0
b_total_progress = 0
b_progress = 0.01

while b_total_progress < a_total_progress:
    a_total_progress += initial_value * a_progress_rate
    for day in range(days_in_year):
        if day % 7 < 5:
            b_total_progress += initial_value * b_workday_progress_rate
        else:
            b_total_progress -= initial_value * b_weekend_regress_rate
    b_progress += 0.001

print("B 君每天工作日进步1%，休息日退步1%，需要的工作日进步值：", b_progress)