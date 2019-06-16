#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 中序遍历为升序
        if (root == NULL) return true;
        vector<int> list;
        inorder(list, root);
        for (int i=0; i<list.size()-1; i++) {
            if (list[i+1] <= list[i])
                return false;
        }
        return true;
        
    }
    void inorder(vector<int>& list, TreeNode* root) {
        if (root == NULL) return;
        inorder(list, root->left);
        list.push_back(root->val);
        inorder(list, root->right);
        
    }
};