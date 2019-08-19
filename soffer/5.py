#!/usr/bin/python
# -*- coding: UTF-8 -*-

class ListNode:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

def reverse1(node):
    """
        用栈的方法
    """
    if node == None or node.next == None:
        return node
    # 用python的列表表示栈
    stack = []
    cur = node
    # 入栈
    while cur:
        stack.append(cur.data)
        cur = cur.next
    # 出栈
    while stack:
        print(stack.pop())

def reverse2(node):
    """
        递归的方式
    """
    if node == None:
        return None
    # 递归基,就算不需要返回值,递归基这里也需要终止函数!
    if node.next == None:
        print(node.data)
        return;
    reverse2(node.next)
    print(node.data)


if __name__ == "__main__":
    dummy = ListNode('begin')
    node = dummy
    for i in range(10):
        node.next = ListNode(data=i)
        node = node.next
    # reverse1(dummy.next)    
    reverse2(dummy.next)
