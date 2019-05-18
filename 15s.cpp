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