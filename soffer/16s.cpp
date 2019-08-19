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