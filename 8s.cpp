#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(vector<int>& arr, int i, int j) {
        int m = i; // 最小值对应的索引记为m
        for (int k=i+1; k<=j; k++) {
            if (arr[k] < arr[m]) {
                m = k;
            }
        }
        return m;
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() < 1) {
            return 666;
        }
        // 采用二分查找的思路
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = left;
        while (rotateArray[left] >= rotateArray[right]) {
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = left + (right-left) / 2;
            if (rotateArray[left] == rotateArray[right] && 
                rotateArray[left] == rotateArray[mid] ) {
                mid = min(rotateArray, left, right);
            } else if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else if (rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};