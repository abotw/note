# 初始值
initial_value = 1.0

# 每天进步或退步千分之一
progress_rate = 0.001

# 计算一年内的累计进步或退步
days_in_year = 365
total_progress = initial_value * ((1 + progress_rate) ** days_in_year - 1)

print("一年每天进步或退步千分之一，累计进步或退步：", total_progress)