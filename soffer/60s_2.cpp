class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 要点,用队列存储.记录每一层的数目count
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int count = que.size();
            vector<int> temp;
            while (count > 0) {
                TreeNode* node = que.front();que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                count--;
            }
            result.push_back(temp);
        }
        return result;
        
    }
};