""" 
    Flow++ 实习生面试题
""" 
from functools import reduce

# 使用str的内置方法
def reverse1(num:int):
    # 保存符号
    symbal = 1 if num >=0 else -1
    num = abs(num)
    return symbal * int(str(num)[::-1])

# 不使用str方法，使用reduce规约方法
def reverse2(num:int):
    symbal = 1 if num>= 0 else -1 
    num = abs(num)
    tmp = []
    while num:
        tmp.append(num % 10)
        num //= 10 # 注意这里必须是 // 除法！
    return symbal * reduce(lambda x,y: 10*x+y, tmp)

# 一次循环的方法
def reverse3(num:int):
    symbal = 1 if num>= 0 else -1
    num = abs(num)
    tmp = 10
    sum = 0
    while num:
        sum = sum*tmp + (num % 10)
        num //= 10
    return symbal * sum 

if __name__ == "__main__":
    num = 1234
    # result = reverse1(num)
    result = reverse2(num)
    # result = reverse3(num)
    print(result)