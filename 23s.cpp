#include <iostream>
#include <queue>
#include <vector>
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
private:
    queue<TreeNode*> q;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 建立返回值数组
        vector<int> result;
        if (root == NULL) return result;
        q.push(root);
        // 队列为空说明遍历完毕
        while (q.size() > 0) {
            TreeNode* tmp = q.front();
            result.push_back(tmp->val);
            q.pop();
            // 节点存在才让入队
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return result;
    }
};