# 获取用户输入的整数
a = int(input("请输入一个整数："))

# 计算平方根
sqrt_a = (a ** 0.5)

# 格式化输出
formatted_output = f"{sqrt_a:+30.3f}"

print("平方根格式化输出：", formatted_output)