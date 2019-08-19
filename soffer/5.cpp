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
