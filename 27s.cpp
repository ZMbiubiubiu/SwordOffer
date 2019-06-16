#include <iostream>
#include <stack>
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
    TreeNode* Convert(TreeNode* root)
    {
        if (root == NULL) return NULL;
        stack<TreeNode*> nodes;
        TreeNode* node = root;
        TreeNode* pre = NULL;
        bool is_first = true;  // 这是一个小的trick
        while ((node != NULL) || !nodes.empty()) {
            while (node != NULL) {  // 中序遍历
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();nodes.pop();
            if (is_first) {
                root = node;  // 将中序遍历的第一个元素作为转换后的双链表的首元素 
                pre = node;
                is_first = false;
            } else {
                pre->right = node;
                node->left = pre;
                pre = node;
            }
            node = node->right;
        }
        return root;
    }
};