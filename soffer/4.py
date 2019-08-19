#!/usr/bin/python
# -*- coding: UTF-8 -*-

def replaceBlank(string):
    if string == None or len(string) < 1: 
        print('需要提供一个非空字符串')
    # 接下来用字符列表来模拟
    string = list(string)
    length_pre = len(string)
    num_blank = 0
    for char in string:
        if char == " ":
            num_blank += 1
    length_now = num_blank*2 + length_pre
    string_now = ['_' for i in range(length_now)]
    p1 = length_pre - 1
    p2 = length_now - 1
    while p1 >= 0:
        if string[p1] != " ":
            string_now[p2] = string[p1]
            p2 -= 1
        else:
            string_now[p2] = '0'
            string_now[p2-1] = '2'
            string_now[p2-2] = '%'
            p2 -= 3
        p1 -= 1
    print(''.join(string))
    print(''.join(string_now))

if __name__ == "__main__":
    s = 'I love you Lee.'
    replaceBlank(s)
