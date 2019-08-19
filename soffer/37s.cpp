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