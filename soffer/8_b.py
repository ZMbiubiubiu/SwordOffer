import random

def sort(arr):
    if arr == None or len(arr) <=1:
        return arr
    length = len(arr)
    # 建立一个年龄频率数组,统计每个年龄出现的次数
    # 让1岁对应new_arr[1],而不是new_arr[0]
    new_arr = [0 for i in range(length+1)]
    for num in arr:
        new_arr[num] += 1
    # 开始就地排序
    k = 0
    j = 0
    for i in range(1,length+1):
        while j < new_arr[i]:
            arr[k] = i
            k += 1 
            j += 1
        j = 0
# 一个装饰器,打印排序前,排序后的数组
def decorate(func):
    def wrapper(*args):
        print('排序前:',*args)
        func(*args)
        print('排序后:',*args)
    return wrapper

sort = decorate(sort)

if __name__ == "__main__":
    # 生成100个 [0,100] 之间的整数
    ll = [random.randint(1,100) for i in range(100)]
    sort(ll)