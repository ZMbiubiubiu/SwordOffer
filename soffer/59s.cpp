#include <iostream>
// #include 
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        return Mirror(pRoot, pRoot);
    }
    bool Mirror(TreeNode* root1, TreeNode* root2) {
        // 递归基
        if (root1==NULL && root2==NULL) return true;
        if (root1==NULL || root2==NULL) return false;
        if (root1->val != root2->val) {
            return false;
        }
        // 递归之间建立联系
        return Mirror(root1->left, root2->right) && 
            Mirror(root1->right, root2->left);
    }
};