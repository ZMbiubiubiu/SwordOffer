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

