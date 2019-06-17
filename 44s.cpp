#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 边界检查
        if (numbers.size() < 5) return false;
        // SelectSort(numbers); // 用选择排序算法排序
        // sort(numbers.begin(), numbers.end());
        // BubbleSort(numbers);
        // InsertSort(numbers);
        QuickSort(numbers);
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
    
    void QuickSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <= 1) return;
        int low = 0;
        int high = numbers.size() - 1;
        Sort(numbers, low, high);
    }
    void Sort(vector<int>& numbers, int low, int high) {
        if (low >= high) return;
        int mid = Partition(numbers, low, high); 
        Sort(numbers, low, mid-1);
        Sort(numbers, mid+1, high);
    }
    int Partition(vector<int>& numbers, int low, int high) {
        int flag = numbers[low];
        int left = low+1;
        int right = high;
        while (1) {
            while (numbers[left] <= flag && left < high) 
                left++;
            while (numbers[right] >= flag && right > low) 
                right--;
            if (left >= right) {
                break;
            }
            swap(numbers, left, right);
        }
        swap(numbers, low, right);
        return right;
    }
    
    void InsertSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <=1 ) return ;
        int i,j;
        for (i=1; i<numbers.size(); i++) {
            int tmp = numbers[i];
            for (j=i; j>0 && numbers[j-1] > tmp; j--) {
                numbers[j] = numbers[j-1];
            }
            numbers[j] = tmp;
        }
    }
    void BubbleSort(vector<int>& numbers) {
        // 边界检查
        if (numbers.size() <= 1) return;
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for(int i=0; i<numbers.size()-1; i++) {
                if (numbers[i] > numbers[i+1]) {
                    sorted = false;
                    swap(numbers, i, i+1);
                }
            }
        }
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