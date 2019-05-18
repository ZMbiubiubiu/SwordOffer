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
    void Reverse(vector<int> &arr, ListNode* node) {
        // 每次访问一个节点的时候,先递归输出后面的节点,然后输出此节点
        if (node == NULL) return;
        Reverse(arr, node->next);
        arr.push_back(node->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr;
        Reverse(arr, head);
        return arr;
    }
};