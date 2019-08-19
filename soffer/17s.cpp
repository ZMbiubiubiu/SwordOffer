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