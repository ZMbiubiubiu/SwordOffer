#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length < 0) return 666;
        int flag = numbers[0];
        int times = 1;
        for (int i=1; i<length; i++) {
            if (times == 0) {
                flag = numbers[i];
                times = 1;
            } else if (numbers[i] == flag) {
                times++;
            } else {
                times--;
            }
        }
        int count = 0;
        for (int i=0; i<length; i++) {
            if (numbers[i] == flag)
                count++;
        }
        return 2*count>length? flag: 0;
    }
};