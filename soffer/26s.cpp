#include <iostream>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    // 克隆每一个节点
    void CloneList(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        while (node != NULL) {
            // 生成新的节点
            RandomListNode* clone = new RandomListNode(node->label);
            clone->next = node->next;
            node->next = clone;
            // 和下面函数，node的使用是同样的逻辑
            node = clone->next;
        }
    }
    
    void ConnectRandomNode(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        while (node != NULL) {
            RandomListNode* clone = node->next;
            if (node->random != NULL) {
                clone->random = node->random->next;
            }
            node = clone->next;
        }
    }
    
    RandomListNode* SeperateList(RandomListNode* pHead) {
        RandomListNode* node = pHead;
        RandomListNode* clonedHead = new RandomListNode(666);
        RandomListNode* clone = clonedHead;
        while (node != NULL) {
            // 想要建立新的连接，那么就需要用 node->next 这样的形式
            clone->next = node->next;
            clone = clone->next;
            node->next = clone->next;
            node = node->next;
        }
        return clonedHead->next;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL ) return NULL;
        CloneList(pHead);
        ConnectRandomNode(pHead);
        return SeperateList(pHead);
    }
};