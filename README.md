`数据结构` `algorithm` `python` `C++`  
学习《剑指offer》，看懂解法。并用C++和python解答，加深印象，锻炼编程技巧  
> 面试题3 二维数组中的查找  
二维数组的特点：每一行从左到右递增，每一列从上到下递增。完成一个函数，输入这样的一个二维数组和一个整数，判断整数是否在数组中。  

解答思路：不要从中间开始找，否则当前值不论过小还是过大，你都有两个方向需要去继续查找。正确的做法是从一角开始找，但也并不是哪个角都适合。到底从哪里开始找，自己举个例子即可。

[c++版本](./3.cpp)  
[python版本](./3.py)

