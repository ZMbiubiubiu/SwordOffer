`数据结构` `algorithm` `python` `C++`  

学习《剑指offer》,看懂解法.并用C++和python解答,加深印象,锻炼编程技巧  

#### 所有答案均在牛客网上编译运行通过,另外牛客网上的题与书上同名题有的并不相同.以牛客网的题干要求为准.  


### 3 二维数组中的查找 

二维数组的特点：每一行从左到右递增,每一列从上到下递增.完成一个函数,输入这样的一个二维数组和一个整数,判断整数是否在数组中.  

#### 解答思路:
不要从中间开始找,否则当前值不论过小还是过大,你都有两个方向需要去继续查找.正确的做法是从一角开始找,但也并不是哪个角都适合.到底从哪里开始找,自己举个例子即可.

[c++版本](./3.cpp)  
```c++
#include <iostream>

using namespace std;

bool find(int* matrix, int rows, int columns, int target) {
    bool flag = false;
    if (matrix == NULL or rows < 0 or columns < 0) return flag;
    int row = 0;
    int column = columns - 1;
    while (column >= 0 && row < rows) {
        if (matrix[row*columns + column] == target) {
            flag = true;
            break;
        } else if (matrix[row*columns + column] < target) {
            ++row;
        } else {
            --column;
        }
    }
    return flag;
}

int main()
{
    int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    cout << "result:" << find(matrix, 4, 4, 1) << endl;
    return 0;
}
```
[python版本](./3.py)

### 4 替换空格  

实现一个函数,把字符串中的每个空格替换成"%20".例如输入'I am Iron man'输出'I%20am%20Iron%20man'.  

#### 解答思路:
避免重复移动.首先遍历字符串,找出空格数.确定替换之后字符串长度,由一个字符扩展到三个字符,即增加的长度为空格数*2.声明两个指针p1/p2,p1指向原字符串末尾,p2指向新字符串末尾.逐渐向左逼近,p1指向的值赋值给p2指向的值;当p1指向空格时,p1向前移动一格,p2向前移动三格,并且插入'%20' 
```c++
#include <iostream>
using namespace std;


void replaceBlank(char string[], int length) { // length 为字符数组的总长度
    if (string == NULL or length <= 0) return;
    int length_pre = 0; // 原始长度
    int length_now = 0; // 替换后长度
    int number_blank = 0; // 空格数
    int i = 0;
    while (string[i] != '\0') {
        ++length_pre;
        if (string[i] == ' ')
            ++number_blank;
        ++i;
    }
    length_now = length_pre + number_blank * 2;
    if (length_now > length) return; // 字符数组不够用
    // 从字符串'\0'开始复制
    int index_pre = length_pre;
    int index_now = length_now; // 指定两个指针
    while(index_now>index_pre) {
        if (string[index_pre] == ' ') {
            string[index_now--] = '0';
            string[index_now--] = '2';
            string[index_now--] = '%';
        } else {
            string[index_now--] = string[index_pre];
        }
        --index_pre;
    }
    cout << string << endl;
}

int main() {
    char string[100] = "I love you lee.";
    replaceBlank(string, 100);
}
``` 

### 5 从尾到头打印链表  

输入一个链表的头结点,从尾到头反过来打印出每个节点的值  

#### 解答思路:
后入先出,标准的栈特征.  
第一种,直接用栈.  
第二种用递归函数(递归本质上就是一种栈结构).当我们访问一个节点的时候,首先递归输出后面的节点,然后输出此节点.  
[C++递归版本](./5s.cpp)  
```c++
/*
**  5.从尾到头打印链表
**  输入一个链表的头结点,从尾到头反过来打印出每个节点的值
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int       value;
    ListNode* next;
};

void PrintListReversingly_Iteratively(ListNode* pHead) {
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while (pNode->next != NULL) {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        nodes.pop();
        cout << pNode->value << " ";
    }
    cout << endl;
}

void PrintListReversingly_Recursively(ListNode* pHead) {
    if (pHead == NULL) return;
    if (pHead->next == NULL) {
        cout << pHead->value << endl;
        return;
    }
    PrintListReversingly_Recursively(pHead->next);
    cout << pHead->value << endl;
}

int main()
{   
    // 初始化一个测试链表
    ListNode* dummy = new ListNode();
    dummy->value = 666; // 开始
    ListNode* pNode = dummy;
    for (int i=0; i<10; i++) {
        ListNode* tmp = new ListNode();
        tmp->value = i;
        pNode->next = tmp;
        pNode = pNode->next;
    }
    // PrintListReversingly_Iteratively(dummy->next);
    PrintListReversingly_Recursively(dummy->next);
    return 0;
}

```
[C++迭代版使用容器栈](./5s.cpp)  
```c++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> arr;
        vector<int> result;
        ListNode* pNode = head;
        while (pNode) {
            arr.push(pNode->val);
            pNode = pNode->next;
        }
        while (arr.size() > 0) {
            int tmp = arr.top();
            arr.pop();
            result.push_back(tmp);
        }
        return result;
    }
};
```
[Python版本](./5.py) 


### 6 重建二叉树  
给定一个二叉树的前序遍历和中序遍历的结果,通过这两个序列重建二叉树的结构  

#### 解答思路:
 前序遍历的结果中第一个便是树根, 中序遍历的结果树根在中间,然后可以分割出左子树和右子树. 得到了左子树的长度之后,便可以在前序遍历中划定左子树的范围,这样有什么好处?继而在确定左子树中的根节点.所以这就是一个递归的过程.  
[C++版本](./6.cpp)  
```c++
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() < 0 || vin.size() < 0) return NULL;
        return Construct(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    TreeNode* Construct(
        vector<int> pre, int startPre, int endPre,
        vector<int> vin, int startVin, int endVin
    ) 
    {
        if (startPre > endPre || startVin > endVin) {
            return NULL;
        }
        // 建立根节点
        int rootValue = pre[startPre];
        TreeNode* root = new TreeNode(rootValue);
        
        // 有多个节点,在中序遍历中找到根节点的值
        int rootIndex = startVin;
        while (vin[rootIndex] != rootValue && rootIndex < endVin) 
            rootIndex++;
            
        if (rootIndex == endVin && vin[rootIndex] != rootValue) {
            // throw std::exception("Invalid input");
            cout << "False" << endl;
            return NULL;
        }
        
        // 根据中序遍历中根节点的位置,判断左子树的长度
        int leftLength = rootIndex - startVin;
        root->left = Construct(pre, startPre+1, startPre+leftLength,
                                vin, startVin, rootIndex-1);
        root->right = Construct(pre, startPre+leftLength+1, endPre,
                                vin, rootIndex+1, endVin);
        return root;
    }
};
```

### 7 用两个栈实现队列  

#### 解题思路:我们有两个栈.一个用作'入队'时使用, 一个用作'出队'时使用.  
[C++版本](./7.cpp)  
```c++
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.size() <= 0) {
            while (stack1.size() > 0) {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        } 
        // 发生这种情况,说明两个栈都为空,没有可弹出的元素
        if (stack2.size() == 0) {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        int head = stack2.top();
        stack2.pop();
        return head;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


```

### 8 补充 排序员工的年龄数组

#### 解答思路:
人的年龄是一个有限范围数字组成的数组.对其排序,可以采用简单桶排序的方法  
[C++版本](./8_b.cpp)  
```c++
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
```
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
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(vector<int>& arr, int i, int j) {
        int m = i; // 最小值对应的索引记为m
        for (int k=i+1; k<=j; k++) {
            if (arr[k] < arr[m]) {
                m = k;
            }
        }
        return m;
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() < 1) {
            return 666;
        }
        // 采用二分查找的思路
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = left;
        while (rotateArray[left] >= rotateArray[right]) {
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = left + (right-left) / 2;
            if (rotateArray[left] == rotateArray[right] && 
                rotateArray[left] == rotateArray[mid] ) {
                mid = min(rotateArray, left, right);
            } else if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else if (rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};
```

### 9.1 斐波那契数列  

[C++版本](./9s.cpp)  
```c++

class Solution {
public:
    int Fibonacci(int n) {
        // 这种解法的思路就是不断向前移动a,b
        int a=0, b=1;
        for (int i=1; i<=n; i++) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
        
    }
};
```  

### 9.2 青蛙跳台阶问题  

一只青蛙一次可以跳上1级台阶,也可以跳上2级.求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）.

#### 解答思路:
 对于n阶的台阶的问题可以记做f(n),如果第一步跳了1阶,剩下n-1阶,对应问题f(n-1), 如果第一步跳了两步,剩下n-2阶,对应问题f(n-2).所以f(n) = f(n-1) + f(n-2).由此可以看出这是斐波那契数列的变体.  
[C++版本](./9s2.cpp)  
```c++
class Solution {
public:
    int jumpFloor(int number) {
        int a=1, b=2;
        for (int i=2; i<=number; i++) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
    }
};
```


### 9.3 举行覆盖问题  

我们可以用2x1的小矩形横着或者竖着去覆盖更大的矩形.请问用n个2x1的小矩形无重叠地覆盖一个2xn的大矩形,总共有多少种方法？ 

#### 解答思路:
要覆盖的矩形长度为n,宽度为2.记做问题f(n) 如果第一步采用竖着覆盖, 那么还剩下长度为n-1的矩形需要覆盖, 记做问题f(n-1).如果第一步采用横着覆盖,横着覆盖的话,左下角必须同样横着覆盖,别无他法.剩下长度为n-2的矩形记做问题f(n-2).没错,又是斐波那契数列的变体.  
```c++
class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) return 0;
        int a=1, b=2;
        while (--number) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
    }
};
```

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
```c++
class Solution {
public:
    int  NumberOf1(int n) {
        // 有可能是负数,右移的时候就要小心,始终会补1.
        int bit = 32;
        int count = 0;
        while (bit--) {
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};
```

#### (2)  整数与减去1的结果做位与运算  
一个整数比如1100, 减去1的结果为1011.两者进行位与运算为1000.没进行依次上述操作就消去了一个1.如此便可以计算二进制数中1的个数.  
[C++与运算版本](./10s1.cpp) 
```c++
class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n) {
            count++;
            n = n & (n-1);
        }
        return count;
    }
};
```

### 11 数值的整数次幂  

给定一个double类型的浮点数base和int类型的整数exponent.求base的exponent次方.note:没有大数问题.  

#### 解答思路: 
值得注意的就是注意幂数可能小于等于0.  

    (1)0的0次幂需要约定一下  
    (2)负数次幂,需要计算倒数.一涉及到倒数就要想到除数为0的情况,此时base不能为0  
    (3)浮点数的相等比较,不能用==来操作.因为计算机表示浮点数会有误差,我们比较两个浮点数通过确认两者的差值是否在某一个限定范围内.  
[C++版本](./11s.cpp) 
```c++
class Solution {
public:
    bool equal(double a, double b) {
        if ( a-b >= -0.00001 && a-b <= 0.00001) return true;
        else return false;
    }
    double PowerWithAbsExponent(double base, int absExponent) {
        double result = 1.0;
        while (absExponent--) {
            result *= base;
        }
        return result;
    }
    double Power(double base, int exponent) {
        if (equal(base, 0.0) && exponent< 0) {
            cout << "Invalid input" << endl;
            return 0.1234;
        }
        if (exponent == 0) {
            return 1.0; // 约定0的0次幂等于1
        }
        int absExponent = exponent > 0 ? exponent : -exponent;
        double result = PowerWithAbsExponent(base, absExponent);
        if (exponent > 0)
            return result;
        else
            return 1 / result;
    }
};
```

### 14 调整数组顺序使奇数位于偶数前面  

输入一个整数数组,实现一个函数来调整该数组中数字的顺序,使得所有的奇数位于数组的前半部分,所有的偶数位于数组的后半部分,并保证奇数和奇数,偶数和偶数之间的相对位置不变.  

#### 解答思路: 
见代码  
[C++队列版本](./14s.cpp)  
```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        if (length < 1) return ;
        queue<int> queue1;
        queue<int> queue2;
        for (int i=0; i<length; i++) {
            if (array[i] % 2 == 0) {
                queue2.push(array[i]);
            } else {
                queue1.push(array[i]);
            }
        }
        int index = 0;
        while (queue1.size() > 0) {
            int tmp = queue1.front();
            queue1.pop();
            array[index] = tmp;
            index++;
        }
        while (queue2.size() > 0) {
            int tmp = queue2.front();
            queue2.pop();
            array[index] = tmp;
            index++;
        }
    }
};
```

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
```c++
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) return NULL;
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        // fast到达尾节点时, slow正好到达倒数第k个节点
        // fast需要比slow先走k-1步
         // 而且要注意,链表的长度不能小于k;
        for (int i=0; i<k-1; i++) {
            if (fast->next) {
                fast = fast->next;
            } else {
                return NULL;
            }
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```


### 16 反转链表  

定义一个函数,输入一个链表的头结点,反转该链表并输出翻转后的头结点  

#### 解答思路:
    确定递归基.相信递归函数的作用.找到Reverse(head)与Reverse(next)的关系

[C++递归版本](./16s.cpp)  
```c++
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 递归:反转链表,返回反转之后的头结点指针
        
        // 递归基
        if (!pHead || !pHead->next) {
            return pHead;
        }
        ListNode* pNext = pHead->next; // 保存下一节点
        ListNode* pNew = ReverseList(pNext);
        pNext->next = pHead; // 下一节点指向当前节点
        pHead->next = NULL;  // 废掉当前节点的指向
        return pNew;
    }
};
```
[C++迭代版本](./16s2.cpp)  
```c++
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 迭代

        if (!pHead || !pHead->next) { // 边界检查
            return pHead;
        }
        // pPre 和 pNext 都是用来临时存储
        ListNode* pPre = NULL;
        ListNode* pNode = pHead;
        ListNode* pNext = NULL;
        while (pNode) {
            pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return pPre;
    }
};
```

### 17 合并两个排序的链表  

输入两个单调递增的链表,输出两个链表合成后的链表,当然我们需要合成后的链表满足单调不减规则  

#### 解答思路: 
    使用递归,那么递归函数的作用为:合并两个排序链表,返回合并之后链表的头结点. 根据递归函数的作用确定递归基,返回值,建立递归之间的联系.  
[C++递归版本](./17s.cpp)  
```c++
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 合并两个排序链表,返回合并之后的头结点
        // 确定递归基, 相信递归函数, 建立联系
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode* pNode = NULL;
        if (pHead1->val <= pHead2->val) {
            pNode = pHead1;
            pNode->next = Merge(pHead1->next, pHead2);
        } else {
            pNode = pHead2;
            pNode->next = Merge(pHead1, pHead2->next);
        }
        return pNode;
        
    }
};
```  
[C++迭代版本](./17s2.cpp) 
```c++
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 迭代版
        ListNode* dummpy = new ListNode(0);
        ListNode* pNode = dummpy;
        while(pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                pNode->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                pNode->next = pHead2;
                pHead2 = pHead2->next;
            }
            // 前进
            pNode = pNode->next;
        }
        // 最终总会剩下两个链表中的一个, while每次只吃一个节点
        // 所以两个链表不会同时到达末尾
        // 所以新合并的链表的末尾继承了NULL,不必担心.
        if (pHead1) pNode->next = pHead1;
        if (pHead2) pNode->next = pHead2;
        return dummpy->next;
    }
};
```

### 18 树的子结构  

输入两棵二叉树A,B,判断B是不是A的子结构.（ps：我们约定空树不是任意一个树的子结构）

#### 解答思路:  
主要就是如何遍历树的问题.  
(1) 首先在tree1中找到节点值与tree2根节点值相同的节点.判断tree2是否是其子结构  
(2)上述没成功,继续遍历tree1.  
[C++递归版本](./18s.cpp)  
```c++

```


### 19 二叉树的镜像  

操作给定的二叉树,将其变换为源二叉树的镜像

#### 解答思路:  
其实就是翻转二叉树.主旨就是递归函数的定义  
```c++
#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 翻转二叉树,无返回值.
// 没有返回值的递归函数,自己建立树的结构时,多动一下手即可.
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        CreateMirror(pRoot);
    }
    void CreateMirror(TreeNode* root) {
        // 翻转树,没有返回值
        if (!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        CreateMirror(root->left);
        CreateMirror(root->right);
        TreeNode* tmp = left;
        root->left = right;
        root->right = tmp;
    }
};

// 翻转二叉树,有返回值
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        pRoot = Trans(pRoot);
    }
    TreeNode* Trans(TreeNode *root) {
        if (root == NULL) return NULL;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = Trans(right);
        root->right = Trans(left);
        return root;
    }
};
```

### 21 包含min函数的栈  

定义栈的数据结构,请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1))  

#### 解答思路:  

构造一个辅助栈,用来存储当前最小值.push数值入栈时,数据栈直接入栈,存储最小值的栈需要判断.如果value小于辅助栈的栈顶(即之前的最小值),那么也把value入辅助栈,否则将辅助栈栈顶元素再次入栈.  
要点就是始终保持两个栈的大小相等.根据压入的value来更新辅助栈的栈顶元素.  
[C++版本](./21s.cpp)  
```c++
#include <iostream>
#include <stack>;

using namespace std;

class Solution {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int value) {
        stack1.push(value);
        if (stack2.size() < 1 || stack2.top() > value) {
            stack2.push(value);
        } else if (stack2.top() <= value) {
            stack2.push(stack2.top());
        }
    }
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};
```

### 22 栈的压入, 弹出序列  

输入两个整数序列,第一个序列表示栈的压入顺序,请判断第二个序列是否为该栈的弹出顺序.假设压入栈的所有数字均不相等  

#### 解答思路:  

如果下一个弹出的数字刚好是栈顶数字,那么直接弹出.如果下一个弹出的数字不在栈顶,我们把压栈序列中还没有入栈的数字依次入栈,直到把下一个需要弹出的数字压入栈顶为止(然后弹出).如果所有数字都入栈了,还没有找到下一个需要被弹出的数字,那么该序列不可能是一个弹出序列.  
[C++版本](./22s.cpp)  
```c++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    stack<int> s;
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 两个序列的大小不相等的话,那还判断个毛线...
        if (pushV.size() != popV.size()) return false; 
        int index1 = 0;
        int index2 = 0;
        while (index2 < popV.size()) {
            while (s.size() < 1 || s.top() != popV[index2]){
                s.push(pushV[index1]);
                index1++;
                if (index1 >= pushV.size() && s.top() != popV[index2]) {
                    return false;
                }
            }
            s.pop();
            index2++;
        }
        return true;
    }
};
``` 

### 23 从上往下打印二叉树  

从上往下打印出二叉树的每个节点,同一层的节点按照从左到右的顺序  

#### 解答思路:  

不难看出,此题使用队列来解决.从上到下按层遍历二叉树,从本质上来说就是广度优先遍历二叉树.  
[C++版本](./23s.cpp)  
```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
private:
    queue<TreeNode*> q;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 建立返回值数组
        vector<int> result;
        if (root == NULL) return result;
        q.push(root);
        // 队列为空说明遍历完毕
        while (q.size() > 0) {
            TreeNode* tmp = q.front();
            result.push_back(tmp->val);
            q.pop();
            // 节点存在才让入队
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return result;
    }
};
```

### 24 二叉搜索树的后序遍历序列  

输入一个整数数组,判断该数组是不是某二叉搜索树的后序遍历的结果.如果是则输出Yes,否则输出No.假设输入的数组的任意两个数字都互不相同.  

#### 解答思路:  

二叉搜索树的定义:  
* 节点的值各不相同
* 若有左子树,则左子树的值均小于根节点的值
* 若有右子树,则右子树的值均大于根节点的值  

根据其定义,对于一个二叉搜索树的后序遍历数组中.根节点的值肯定为末尾元素,然后找到左子树,怎么找?就从头开始找数组中小于根节点值的元素,然后剩下的就应该是右子树中的值.如果果真为右子树,那么剩下元素的值应该均大于根节点的值.然后递归判断左子树/右子树是否为二叉搜索树.  

递归函数的提示:  
* 递归基:因为在接口函数VerifySquenceOfBST中已经排除掉空数组,所以至少有一个元素,那么如果只有一个元素的话,肯定是二叉搜索树咯
* 剩下的看函数内的注解即可  

[C++版本](./24s.cpp) 
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 边界检查
        int length = sequence.size();
        if (length == 0) return false;
        int low = 0;
        int high = length - 1;
        return Verify(sequence, low, high);
        
    }
    bool Verify(vector<int> arr, int low, int high) {
        // 递归基
        if ( high<=low ) return true;
        // 根节点的值,用来划分左右子树
        int root = arr[high];
        int i = low;
        for (; i < high; i++) {
            if (arr[i] > root)
                break;
        }
        // 划分边界, mid为左子树的最右边索引
        int mid = i - 1;
        // 如果所谓的右子树出现小于根节点的值,那么说明并非为二叉搜索树
        while (i < high) {
            if (arr[i] < root)
                return false;
            i++;
        }
        // 根据二叉搜索树的定义,我们需要递归判定左右子树是否符合定义
        return Verify(arr,low, mid) && Verify(arr, mid+1, high - 1);
    }
};
```

### 26 复杂链表的复制  

输入一个复杂链表（每个节点中有节点值,以及两个指针,一个指向下一个节点,另一个特殊指针指向任意一个节点）,返回结果为复制后复杂链表的head.（注意,输出结果中请不要返回参数中的节点引用,否则判题程序会直接返回空）  

#### 解答思路：  

分成三个步骤：
* 复制每个节点: a->b->c  => a->a'->b->b'->c->c'
* 复制random指针
* 分离  

[C++代码](./26s.cpp)  
```c++
#include <iostream>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    // 克隆每一个节点
    void CloneList(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        while (node != NULL) {
            // 生成新的节点
            RandomListNode* clone = new RandomListNode(node->label);
            clone->next = node->next;
            node->next = clone;
            // 和下面函数，node的使用是同样的逻辑
            node = clone->next;
        }
    }
    
    void ConnectRandomNode(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        while (node != NULL) {
            RandomListNode* clone = node->next;
            if (node->random != NULL) {
                clone->random = node->random->next;
            }
            node = clone->next;
        }
    }
    
    RandomListNode* SeperateList(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        RandomListNode* clonedHead = new RandomListNode(666);
        RandomListNode* clone = clonedHead;
        while (node != NULL) {
            // 想要建立新的连接，那么就需要用 node->next 这样的形式
            clone->next = node->next;
            clone = clone->next;
            node->next = clone->next;
            node = node->next;
        }
        return clonedHead->next;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL ) return NULL;
        CloneList(pHead);
        ConnectRandomNode(pHead);
        return SeperateList(pHead);
    }
};
```

### 27 二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表.要求不能创建任何新的结点，只能调整树中结点指针的指向   
#### 解答思路:  
核心就是中序遍历,然后修改当前节点与前一个节点的指向即可  
[C++代码](./27s.cpp)  
```c++
#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if (root == NULL) return NULL;
        stack<TreeNode*> nodes;
        TreeNode* node = root;
        TreeNode* pre = NULL;
        bool is_first = true;  // 这是一个小的trick
        while ((node != NULL) || !nodes.empty()) {
            while (node != NULL) {  // 中序遍历
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();nodes.pop();
            if (is_first) {
                root = node;  // 将中序遍历的第一个元素作为转换后的双链表的首元素 
                pre = node;
                is_first = false;
            } else {
                pre->right = node;
                node->left = pre;
                pre = node;
            }
            node = node->right;
        }
        return root;
    }
};
```


### 29 数组中出现次数超过一半的数字  

数组中有一个数字出现的次数超过数组长度的一半,请找出这个数字.例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}.由于数字2在数组中出现了5次,超过数组长度的一半,因此输出2.如果不存在则输出0.

#### 解答思路:  

首先我们假设这样的数存在,我们找出它.使用'[投票算法](https://blog.csdn.net/kimixuchen/article/details/52787307)'.然后验证如果这个确实出现的次数超过数组个数的一半,应该满足 2*m > N(其中N为总个数,m为找出的数在数组中出现的次数).否则,不存在这样的数.  
[C++版本](./29s.cpp)  
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length < 0) return 666;
        int flag = numbers[0];
        int times = 1;
        for (int i=1; i<length; i++) {
            if (times == 0) {
                flag = numbers[i];
                times = 1;
            } else if (numbers[i] == flag) {
                times++;
            } else {
                times--;
            }
        }
        int count = 0;
        for (int i=0; i<length; i++) {
            if (numbers[i] == flag)
                count++;
        }
        return 2*count>length? flag: 0;
    }
};
```




### 31 连续子数组的最大和  

输入一个整数数组,数组里面有整数也有负数.数组中一个或连续的多个整数组成一个子数组.
求所有子数组的和的最大值.要求时间复杂度为O(n)

#### 解答思路:  

详情见代码  
[C++版本](./31s.cpp)  
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0]; // 保存一个之前的最大子数组和
        int sum = array[0]; // 当前的子数组的和
        for (int i=1; i<array.size(); i++) {
            if (sum < 0) {
                sum = array[i];
            } else {
                sum += array[i];
            }
            // 更新一下目前为止的最大子数组和(如果有必要的话)
            max = sum > max ? sum : max;
        }
        return max;
    }
};
```

### 37 两个链表的第一个公共节点  

输入两个链表,找出它们的第一个公共结点  

#### 解答思路:  

这两个链表的拓扑结构一定是Y型,不可能是X型,即所谓的公共节点不是节点值相同的那一个点.这个我开始便理解错了.  
如果我们从两个链表的尾部向前找,最后一个相同的节点就是我们要找的公共节点.很自然,我们需要使用栈.  

[C++代码](./37s.cpp) 
```c++
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        // 将第一个链表中的节点入栈
        ListNode* node1 = pHead1;
        while (node1 != NULL) {
            s1.push(node1);
            node1 = node1->next;
        }
        // 将第二个链表中的节点入栈
        ListNode* node2 = pHead2;
        while (node2 != NULL) {
            s2.push(node2);
            node2 = node2->next;
        }
        // 找到公共节点
        ListNode* result = NULL;
        while (!s1.empty() && !s2.empty()) {
            node1 = s1.top();
            node2 = s2.top();
            if (node1->val == node2->val) {
                result = node1;
                s1.pop();
                s2.pop();
            } else {
                break;
            }
        }
        return result;
    }
};
``` 


### 39 二叉树的深度 

输入一棵二叉树,求该树的深度.从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径,最长路径的长度为树的深度  

#### 解答思路:  
递归  
[C++代码](./39s.cpp)  
```c++
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
}

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        // 递归基
        if (pRoot == NULL) return 0;
        // 寻找联系 Tree(root) Tree(root->left) Tree(root->right)
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        // 返回预期的结果
        return 1 + max(left, right);
    }
};
```


### 40 数组中只出现一次的数字   

输入一棵二叉树,求该树的深度.从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径,最长路径的长度为树的深度  

#### 解答思路:  
首先先用亦或运算迭代整个数组,结果是这唯一的两个不同的数字的亦或结果.  
然后找到某一位结果为1,代表这两个数在这一位不同.据此将整个数组分成两个部分.  
最后在每一个部分再次进行迭代亦或运算,如此分别得到这两个数.  
[C++代码](./40s.cpp)  
```c++
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 边界检查
        // if (data.size() == 0) return ;
        int tmp = 0; 
        for (size_t i=0; i<data.size(); i++) {
            tmp ^= data[i];
        } // 最终tmp为num1与num2的亦或结果,然后根据亦或中某一位为1可以将整个data分成两组
        int first = FindFirstOne(tmp);
        *num1 = 0;
        *num2 = 0;
        for (size_t i=0; i<data.size(); i++) {
            int num = data[i];
            if ((num >> (first-1)) & 1) {
                *num1 ^= num;
            } else {
                *num2 ^= num;
            }
        }
    }
    int FindFirstOne(int num) {
        int index = 1;
        while (1) {
            if ((num & 1) == 1) break;
            num = num >> 1;
            index++;
        }
        return index;
    }
};
```

### 44 扑克牌顺子
五张牌,其中大小鬼为癞子,牌面为 0.判断这五张牌是否能组成顺子

#### 解答思路:  
分别统计癞子的数量和不连续的顺子的数量  
[C++代码](./44s.cpp)  
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 边界检查
        if (numbers.size() < 5) return false;
        // SelectSort(numbers); // 用选择排序算法排序
        // sort(numbers.begin(), numbers.end());
        // BubbleSort(numbers);
        // InsertSort(numbers);
        QuickSort(numbers);
        // 癞子的数量
        int king = 0;
        for(int i=0; i<numbers.size(); i++) {
            if (numbers[i] == 0) {
                king++;
                 } else {
                break;
            }
        }
        // 不连续顺子的数量
        int weak = 0;
        for (int i=king; i<numbers.size()-1; i++) {
            int diff = numbers[i+1] - numbers[i];
            if (diff == 0) {
                return false; // 有相同的排,肯定不能构成顺子
            } else {
                weak += diff - 1;
            }
        }
        return king >= weak;
    }
    
    void QuickSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <= 1) return;
        int low = 0;
        int high = numbers.size() - 1;
        Sort(numbers, low, high);
    }
    void Sort(vector<int>& numbers, int low, int high) {
        if (low >= high) return;
        int mid = Partition(numbers, low, high); 
        Sort(numbers, low, mid-1);
        Sort(numbers, mid+1, high);
    }
    int Partition(vector<int>& numbers, int low, int high) {
        int flag = numbers[low];
        int left = low+1;
        int right = high;
        while (1) {
            while (numbers[left] <= flag && left < high) 
                left++;
            while (numbers[right] >= flag && right > low) 
                right--;
            if (left >= right) {
                break;
            }
            swap(numbers, left, right);
        }
        swap(numbers, low, right);
        return right;
    }
    
    void InsertSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <=1 ) return ;
        int i,j;
        for (i=1; i<numbers.size(); i++) {
            int tmp = numbers[i];
            for (j=i; j>0 && numbers[j-1] > tmp; j--) {
                numbers[j] = numbers[j-1];
            }
            numbers[j] = tmp;
        }
    }
    void BubbleSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <= 1) return;
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for(int i=0; i<numbers.size()-1; i++) {
                if (numbers[i] > numbers[i+1]) {
                    sorted = false;
                    swap(numbers, i, i+1);
                }
            }
        }
        for(int i=0; i<numbers.size()-1; i++) {
            cout << i;
        }
    }
    void SelectSort(vector<int>& numbers) {
        // 逐渐选择最小的元素与第一/二/.../个元素交换
        for (int i=0; i<numbers.size(); i++) {
            int min_index = i;
            for (int j=i; j<numbers.size(); j++) {
                if (numbers[j] < numbers[min_index]) {
                    min_index = j;
                }
            }
            swap(numbers, min_index, i);
        }
    }
    void swap(vector<int>& numbers,int i, int j) {
        int tmp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = tmp;
    }
};
```


### 46 求 1+2+3+..+n
求1+2+3+...+n,要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句(A?B:C)  
#### 解答思路  
  
最直观的解法就是使用递归.但是递归基的判断这里不能使用if条件判断,那么可以利用&&短路原则.  
找到递归基判断,即n<=0.  
因此核心代码为:bool flag = (n > 0) && (sum += Sum_Solution(n-1))  
[C++代码](./46s.cpp)  
```c++
class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        bool flag = n > 0 && (sum += Sum_Solution(n-1));
        return sum;
    }
};
```

### 47 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号  

#### 解答思路  
亦或^操作可以模拟不考虑进位的加法  
与&操作然后左移1位可以模拟所有的进位,左移1位就表示进到上一位去继续参与加法  
这样我们可以得到两个数,其一没有进位的加法结果,其二为只有进位的结果  
如此一来我们可以不断的循环执行,直到进位值为0,此时的没有进位的加法结果便是最终结果  
[C++代码](./47s.cpp)  
```c++
class Solution {
public:
    int Add(int num1, int num2)
    {
        if (num2 == 0) return num1;
        return Add(num1^num2, (num1&num2)<<1);
    }
};



class Solution2 {
public:
    int Add(int num1, int num2)
    {
        return num2 == 0 ? num1 : Add(num1^num2, (num1&num2)<<1);
    }
};
```



### 58 二叉树的下一个节点  


给定一个二叉树和其中的一个结点,请找出中序遍历顺序的下一个结点并且返回.注意,树中的结点不仅包含左右子结点,同时包含指向父结点的指针 

#### 解答思路:  
注意指的是中序遍历:  
* 如果有右子树:下一节点为右子树中最左节点
* 如果没有右子树,且当前节点是父节点的左节点:下一节点为父节点
* 如果没有右子树,且当前节点是父节点的右节点:沿着父节点的指针回溯,直到节点为其父节点左节点
[C代码](./58.cpp)  
```c++
#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 边界检查
        if (pNode == NULL) return NULL;
        // 如果有右子树:下一节点为右子树中最左节点
        TreeLinkNode* next = NULL; // 隐含逻辑为:当pNode指向中序遍历的最后一个节点时,它没有下一个节点,此时理所应当的返回NULL
        if (pNode->right != NULL) {
            next =  visitAlongLeftBranch(pNode->right);
        } else if (pNode->next != NULL) {
            TreeLinkNode* current = pNode;
            TreeLinkNode* father = pNode->next;
            while (father != NULL && current == father->right) {
                current = father;
                father = father->next;
            }
            next = father;
        }
        return next;
    }
    // 以root为根的树中的最左节点
    TreeLinkNode* visitAlongLeftBranch(TreeLinkNode* root) {
        TreeLinkNode* node = root;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
};
```


### 59 对称的二叉树  

请实现一个函数,用来判断一颗二叉树是不是对称的.  

#### 解答思路:  

如果一个二叉树同此二叉树的镜像是同样的,定义其为对称的.  
上面那句话也可以理解为,二叉树的前序遍历结果,我们在定义个与前序遍历对应的遍历(root->right->left).比较这两者的序列(加上NULL值).  
[C++代码](./59s.cpp)  
```c++
#include <iostream>
// #include 
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        return Mirror(pRoot, pRoot);
    }
    bool Mirror(TreeNode* root1, TreeNode* root2) {
        // 递归基
        if (root1==NULL && root2==NULL) return true;
        if (root1==NULL || root2==NULL) return false;
        if (root1->val != root2->val) {
            return false;
        }
        // 递归之间建立联系
        return Mirror(root1->left, root2->right) && 
            Mirror(root1->right, root2->left);
    }
};
```

### 60 把二叉树打印成多行  

从上到下按层打印二叉树，同一层结点从左至右输出.每一层输出一行. 

#### 解答思路:  
使用队列,层次遍历,记录每一层的节点数.  
[C++代码](./60s.cpp)  
```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> matrix;
            TreeNode* node = NULL;
            // 边界检查 
            if (pRoot == NULL) return matrix;
            queue<TreeNode*> q;
            q.push(pRoot);
            int count = 1; // 记录每一层的节点数
            int index = 0; // 记录当前为哪一层
            while (!q.empty()) { // 当q不为空时
                int times = count; // 记录当前层的节点数,以此控制遍历的节点数
                vector<int> tmp;
                count = 0; // 为记录下一层节点数做准备
                while (times > 0) {
                    node = q.front();
                    tmp.push_back(node->val);
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                        count++;
                    }
                    if (node->right) {
                        q.push(node->right);
                        count++;
                    }
                    times--;
                }
                matrix.push_back(tmp);
                index++;
            }
            return matrix;
        }
};
```
[C++代码](./60s_2.cpp): 与上算法一样,但是思路更为清晰  
```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 要点,用队列存储.记录每一层的数目count
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int count = que.size();
            vector<int> temp;
            while (count > 0) {
                TreeNode* node = que.front();que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                count--;
            }
            result.push_back(temp);
        }
        return result;
        
    }
};
```

### 62 序列化二叉树  

实现两个函数,分别用来序列化和反序列化二叉树

#### 解答思路:  
1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割.对于空节点则以 '#' 代替.
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！) 
[C++代码](./62s.cpp)  
```c++
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(root == NULL)
            return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        TreeNode *ret = Deserialize(&str);

        return ret;
    }
    TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
        if(**str == '#'){  //所以一定要用**str,
            ++(*str);         //以保证得到递归后指针str指向未被读取的字符
            return NULL;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};
```


## 高频题   

### 反转数字  
比如 1234 -> 4321  -456 -> -654  
[python代码实现](./reverse_number.py)  

## LeetCode

### 中等难度

### 98 验证二叉搜索树

#### 解答思路  
根据二叉搜索树的定义:左子树小于当前节点,右子树大于当前节点.可以采取中序遍历,然后判断中序遍历的结果是否有逆序对.  
[C++代码实现](./lee_98.cpp)  

### 102 按层遍历二叉树  

#### 解答思路 

[C++代码实现](./lee_102.cpp)



