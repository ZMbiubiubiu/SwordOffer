#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 边界检查
        int length = sequence.size();
        if (length == 0) return false;
        int low = 0;
        int high = length - 1;
        return Verify(sequence, low, high);
        
    }
    bool Verify(vector<int> arr, int low, int high) {
        // 递归基
        if ( high<=low ) return true;
        // 根节点的值,用来划分左右子树
        int root = arr[high];
        int i = low;
        for (; i < high; i++) {
            if (arr[i] > root)
                break;
        }
        // 划分边界, mid为左子树的最右边索引
        int mid = i - 1;
        // 如果所谓的右子树出现小于根节点的值,那么说明并非为二叉搜索树
        while (i < high) {
            if (arr[i] < root)
                return false;
            i++;
        }
        // 根据二叉搜索树的定义,我们需要递归判定左右子树是否符合定义
        return Verify(arr,low, mid) && Verify(arr, mid+1, high - 1);
    }
};