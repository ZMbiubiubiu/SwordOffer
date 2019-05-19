`数据结构` `algorithm` `python` `C++`  

学习《剑指offer》，看懂解法。并用C++和python解答，加深印象，锻炼编程技巧  

### 3 二维数组中的查找 

二维数组的特点：每一行从左到右递增，每一列从上到下递增。完成一个函数，输入这样的一个二维数组和一个整数，判断整数是否在数组中。  

#### 解答思路:
不要从中间开始找，否则当前值不论过小还是过大，你都有两个方向需要去继续查找。正确的做法是从一角开始找，但也并不是哪个角都适合。到底从哪里开始找，自己举个例子即可。

[c++版本](./3.cpp)  
[python版本](./3.py)

### 4 替换空格  

实现一个函数,把字符串中的每个空格替换成"%20".例如输入'I am Iron man'输出'I%20am%20Iron%20man'.  

#### 解答思路:
避免重复移动.首先遍历字符串,找出空格数.确定替换之后字符串长度,由一个字符扩展到三个字符,即增加的长度为空格数*2.声明两个指针p1/p2,p1指向原字符串末尾,p2指向新字符串末尾.逐渐向左逼近,p1指向的值赋值给p2指向的值;当p1指向空格时,p1向前移动一格,p2向前移动三格,并且插入'%20'  

### 5 从尾到头打印链表  

输入一个链表的头结点,从尾到头反过来打印出每个节点的值  

#### 解答思路:
后入先出,标准的栈特征.  
第一种,直接用栈.  
第二种用递归函数(递归本质上就是一种栈结构).当我们访问一个节点的时候,首先递归输出后面的节点,然后输出此节点.  
[C++递归版本](./5s.cpp)  
[C++迭代版使用容器栈](./5s.cpp)  
[Python版本](./5.py) 


### 6 重建二叉树  
给定一个二叉树的前序遍历和中序遍历的结果,通过这两个序列重建二叉树的结构  

#### 解答思路:
 前序遍历的结果中第一个便是树根, 中序遍历的结果树根在中间,然后可以分割出左子树和右子树. 得到了左子树的长度之后,便可以在前序遍历中划定左子树的范围,这样有什么好处?继而在确定左子树中的根节点.所以这就是一个递归的过程.  
[C++版本](./6.cpp)

### 7 用两个栈实现队列  

#### 解题思路:我们有两个栈.一个用作'入队'时使用, 一个用作'出队'时使用.  
[C++版本](./7.cpp)  


### 8补充 排序员工的年龄数组

#### 解答思路:
人的年龄是一个有限范围数字组成的数组.对其排序,可以采用简单桶排序的方法  
[C++版本](./8_b.cpp)  
[Python版本](./8_b.py)  

### 8 旋转数组中的最小值  

输入递增数组的一个旋转数组,输出旋转数组中的最小值.
补充: 什么是旋转数组? 即把一个数组最开始的若干个数搬到数的后面去  1,2,3,4,5 -- 3,4,5,1,2  

#### 解答思路:
使用两个指针,不断缩小范围.  
    (1)旋转数组将原数组分成两个分别递增的数组, 分界点就是最小值  
    (2)左右两个指针不断向中间靠拢,最后左指针指向前面数组的最大值,右面指针指向后面数组的最小值.所以两个指针相邻,并且肯定不会越界.这是指针移动的逻辑所决定的.  
    特例  
    1-旋转0个元素,即数组没有动. 此时只有一个递增的数组, 即第一个元素便是最值  
    2-left right mid 对应的值相同的话,无法判断中间值到底属于前后递增数组中的哪一个.此时用笨办法直接局部遍历的方法找  
            比如1,0,1,1,1  
[C++版本]('./8s.cpp') 

### 9.1 斐波那契数列  

[C++版本](./9s.cpp)  

### 9.2 青蛙跳台阶问题  

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

#### 解答思路:
 对于n阶的台阶的问题可以记做f(n),如果第一步跳了1阶,剩下n-1阶,对应问题f(n-1), 如果第一步跳了两步,剩下n-2阶,对应问题f(n-2).所以f(n) = f(n-1) + f(n-2).由此可以看出这是斐波那契数列的变体.  
[C++版本](./9s2.cpp)  

### 9.3 举行覆盖问题  

我们可以用2x1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2x1的小矩形无重叠地覆盖一个2xn的大矩形，总共有多少种方法？ 

#### 解答思路:
要覆盖的矩形长度为n,宽度为2.记做问题f(n) 如果第一步采用竖着覆盖, 那么还剩下长度为n-1的矩形需要覆盖, 记做问题f(n-1).如果第一步采用横着覆盖,横着覆盖的话,左下角必须同样横着覆盖,别无他法.剩下长度为n-2的矩形记做问题f(n-2).没错,又是斐波那契数列的变体.  

### 10 二进制中1的个数  

#### 解答思路:
  
#### (1) 移位  
首先比较二进制数最右边一位是不是1, 如果是计数加1.然后右移(右移要小心,之后讨论).再次比较二进制数最右边一位,以此类推.  
##### 左移: 
m<<n 表示把m左移n位. 左移的时候,最左边的位将被抛弃,同时在最右边补上n个0  
##### 右移: 
m>>n 表示把m右移n位. 此时需要分情况讨论  

    m是一个无符号整数: 用0补上最左边的n位  
    m是一个有符号整数,且是一个正数: 用0补上最左边的n位(有符号中,最高位0表示正的,1表示负的)  
    m是一个有符号整数,且是一个负数: 用1补上最左边的n位  

[C++移位版本](./10s1.cpp) 

#### (2)  整数与减去1的结果做位与运算  
一个整数比如1100, 减去1的结果为1011.两者进行位与运算为1000.没进行依次上述操作就消去了一个1.如此便可以计算二进制数中1的个数.  
[C++与运算版本](./10s1.cpp) 

### 11 数值的整数次幂  

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。note:没有大数问题.  

#### 解答思路: 
值得注意的就是注意幂数可能小于等于0.  

    (1)0的0次幂需要约定一下  
    (2)负数次幂,需要计算倒数.一涉及到倒数就要想到除数为0的情况,此时base不能为0  
    (3)浮点数的相等比较,不能用==来操作.因为计算机表示浮点数会有误差,我们比较两个浮点数通过确认两者的差值是否在某一个限定范围内.  
[C++版本](./11s.cpp) 

### 14 调整数组顺序使奇数位于偶数前面  

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。  

#### 解答思路: 
见代码  
[C++队列版本](./14s.cpp)  

### 15 链表中倒数第k个节点  

输入一个链表,输入该链表中倒数第k个节点. 规定尾节点是倒数第一个节点  

#### 解答思路:  
(1)想要fast到达尾节点时, slow正好到达倒数第k个节点  
(2)fast需要比slow先走k-1步  
(3)要注意,链表的长度不能小于k,如果小于k,返回NULL.  
#### 引申  
求链表的中间节点.定义两个指针,一快一慢.慢的一步走一个节点,快的一步走两个节点.当快指针到达尾节点时,此时慢指针到达中间节点  
求链表中是否有环.同上定义快慢两个指针,当快指针追上慢指针的时候,说明链表中有环,否则快指针到达尾节点,说明链表中没有环.      
[C++迭代版本](./15s.cpp)  


### 16 反转链表  

定义一个函数,输入一个链表的头结点,反转该链表并输出翻转后的头结点  

#### 解答思路:
    确定递归基.相信递归函数的作用.找到Reverse(head)与Reverse(next)的关系

[C++递归版本](./16s.cpp)  
[C++迭代版本](./16s2.cpp)  

### 17 合并两个排序的链表  

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则  

#### 解答思路: 
    使用递归,那么递归函数的作用为:合并两个排序链表,返回合并之后链表的头结点. 根据递归函数的作用确定递归基,返回值,建立递归之间的联系.  
[C++递归版本](./17s.cpp)  
[C++迭代版本](./17s2.cpp) 

### 18 树的子结构  

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

#### 解答思路:  
主要就是如何遍历树的问题.  
(1) 首先在tree1中找到节点值与tree2根节点值相同的节点.判断tree2是否是其子结构  
(2)上述没成功,继续遍历tree1.  
[C++递归版本](./18s.cpp)  

### 19 二叉树的镜像  

操作给定的二叉树，将其变换为源二叉树的镜像

#### 解答思路:  
其实就是翻转二叉树.主旨就是递归函数的定义  

### 21 包含min函数的栈  

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1))  

#### 解答思路:  

构造一个辅助栈,用来存储当前最小值.push数值入栈时,数据栈直接入栈,存储最小值的栈需要判断.如果value小于辅助栈的栈顶(即之前的最小值),那么也把value入辅助栈,否则将辅助栈栈顶元素再次入栈.  
要点就是始终保持两个栈的大小相等.根据压入的value来更新辅助栈的栈顶元素.  
[C++版本](./21s.cpp)  

### 22 栈的压入, 弹出序列  

输入两个整数序列,第一个序列表示栈的压入顺序,请判断第二个序列是否为该栈的弹出顺序.假设压入栈的所有数字均不相等  

#### 解答思路:  

如果下一个弹出的数字刚好是栈顶数字,那么直接弹出.如果下一个弹出的数字不在栈顶,我们把压栈序列中还没有入栈的数字依次入栈,直到把下一个需要弹出的数字压入栈顶为止(然后弹出).如果所有数字都入栈了,还没有找到下一个需要被弹出的数字,那么该序列不可能是一个弹出序列.  
[C++版本](./22s.cpp)   


### 31 连续子数组的最大和  

输入一个整数数组,数组里面有整数也有负数.数组中一个或连续的多个整数组成一个子数组.
求所有子数组的和的最大值.要求时间复杂度为O(n)





