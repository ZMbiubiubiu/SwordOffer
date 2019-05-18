#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 翻转二叉树,无返回值.
// 没有返回值的递归函数,自己建立树的结构时,多动一下手即可.
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        CreateMirror(pRoot);
    }
    void CreateMirror(TreeNode* root) {
        // 翻转树,没有返回值
        if (!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        CreateMirror(root->left);
        CreateMirror(root->right);
        TreeNode* tmp = left;
        root->left = right;
        root->right = tmp;
    }
};

// 翻转二叉树,有返回值
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        pRoot = Trans(pRoot);
    }
    TreeNode* Trans(TreeNode *root) {
        if (root == NULL) return NULL;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = Trans(right);
        root->right = Trans(left);
        return root;
    }
};