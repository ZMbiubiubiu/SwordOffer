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