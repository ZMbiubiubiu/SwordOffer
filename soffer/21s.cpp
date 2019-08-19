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