#include <iostream>
#include <vector>
#include <queue>
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> matrix;
            TreeNode* node = NULL;
            // 边界检查 
            if (pRoot == NULL) return matrix;
            queue<TreeNode*> q;
            q.push(pRoot);
            int count = 1; // 记录每一层的节点数
            int index = 0; // 记录当前为哪一层
            while (!q.empty()) { // 当q不为空时
                int times = count; // 记录当前层的节点数,以此控制遍历的节点数
                vector<int> tmp;
                count = 0; // 为记录下一层节点数做准备
                while (times > 0) {
                    node = q.front();
                    tmp.push_back(node->val);
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                        count++;
                    }
                    if (node->right) {
                        q.push(node->right);
                        count++;
                    }
                    times--;
                }
                matrix.push_back(tmp);
                index++;
            }
            return matrix;
        }
    
};