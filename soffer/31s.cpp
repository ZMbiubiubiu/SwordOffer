#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0]; // 保存一个之前的最大子数组和
        int sum = array[0]; // 当前的子数组的和
        for (int i=1; i<array.size(); i++) {
            if (sum < 0) {
                sum = array[i];
            } else {
                sum += array[i];
            }
            // 更新一下目前为止的最大子数组和(如果有必要的话)
            max = sum > max ? sum : max;
        }
        return max;
    }
};