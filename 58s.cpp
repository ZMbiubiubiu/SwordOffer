#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 边界检查
        if (pNode == NULL) return NULL;
        // 如果有右子树:下一节点为右子树中最左节点
        TreeLinkNode* next = NULL; // 隐含逻辑为:当pNode指向中序遍历的最后一个节点时,它没有下一个节点,此时理所应当的返回NULL
        if (pNode->right != NULL) {
            next =  visitAlongLeftBranch(pNode->right);
        } else if (pNode->next != NULL) {
            TreeLinkNode* current = pNode;
            TreeLinkNode* father = pNode->next;
            while (father != NULL && current == father->right) {
                current = father;
                father = father->next;
            }
            next = father;
        }
        return next;
    }
    // 以root为根的树中的最左节点
    TreeLinkNode* visitAlongLeftBranch(TreeLinkNode* root) {
        TreeLinkNode* node = root;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
};