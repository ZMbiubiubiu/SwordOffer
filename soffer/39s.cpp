struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
}

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        // 递归基
        if (pRoot == NULL) return 0;
        // 寻找联系 Tree(root) Tree(root->left) Tree(root->right)
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        // 返回预期的结果
        return 1 + max(left, right);
    }
};