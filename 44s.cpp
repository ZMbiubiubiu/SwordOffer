#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 边界检查
        if (numbers.size() < 5) return false;
        SelectSort(numbers); // 用选择排序算法排序
        // sort(numbers.begin(), numbers.end());
        // 癞子的数量
        int king = 0;
        for(int i=0; i<numbers.size(); i++) {
            if (numbers[i] == 0) {
                king++;
            } else {
                break;
            }
        }
        // 不连续顺子的数量
        int weak = 0;
        for (int i=king; i<numbers.size()-1; i++) {
            int diff = numbers[i+1] - numbers[i];
            if (diff == 0) {
                return false; // 有相同的排,肯定不能构成顺子
            } else {
                weak += diff - 1;
            }
        }
        return king >= weak;
    }
    void BubbleSort(vector<int>& numbers) {
        for(int i=0; i<numbers.size()-1; i++) {
            cout << i;
        }
    }
    void SelectSort(vector<int>& numbers) {
        // 逐渐选择最小的元素与第一/二/.../个元素交换
        for (int i=0; i<numbers.size(); i++) {
            int min_index = i;
            for (int j=i; j<numbers.size(); j++) {
                if (numbers[j] < numbers[min_index]) {
                    min_index = j;
                }
            }
            swap(numbers, min_index, i);
        }
    }
    void swap(vector<int>& numbers,int i, int j) {
        int tmp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = tmp;
    }
};