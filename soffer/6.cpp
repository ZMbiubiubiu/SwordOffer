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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() < 0 || vin.size() < 0) return NULL;
        return Construct(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    TreeNode* Construct(
        vector<int> pre, int startPre, int endPre,
        vector<int> vin, int startVin, int endVin
    ) 
    {
        if (startPre > endPre || startVin > endVin) {
            return NULL;
        }
        // 建立根节点
        int rootValue = pre[startPre];
        TreeNode* root = new TreeNode(rootValue);
        
        // 有多个节点,在中序遍历中找到根节点的值
        int rootIndex = startVin;
        while (vin[rootIndex] != rootValue && rootIndex < endVin) 
            rootIndex++;
            
        if (rootIndex == endVin && vin[rootIndex] != rootValue) {
            // throw std::exception("Invalid input");
            cout << "False" << endl;
            return NULL;
        }
        
        // 根据中序遍历中根节点的位置,判断左子树的长度
        int leftLength = rootIndex - startVin;
        root->left = Construct(pre, startPre+1, startPre+leftLength,
                                vin, startVin, rootIndex-1);
        root->right = Construct(pre, startPre+leftLength+1, endPre,
                                vin, rootIndex+1, endVin);
        return root;
    }
};