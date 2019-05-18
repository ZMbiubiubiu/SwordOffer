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