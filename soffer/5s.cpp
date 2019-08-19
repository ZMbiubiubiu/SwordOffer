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