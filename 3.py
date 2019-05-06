#!/usr/bin/python
# -*- coding: UTF-8 -*-


def find(array, number):
    if array == None or number == None: # 是否为有效参数
        return False
    rows = len(array)
    columns = len(array[0])
    j = columns - 1
    i = 0
    # 从右上角开始查找目标值
    while j >=0 and i < rows:
        if array[i][j] == number:
            return True
        elif array[i][j] < number:
            i += 1
        else:
            j -= 1

    


if __name__ == "__main__":
    ll = [[1,2,8,9], [2,4,9,12], [4,7,10,13], [6,8,11,15]]
    print(find(ll, 7))