#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        if (length < 1) return ;
        queue<int> queue1;
        queue<int> queue2;
        for (int i=0; i<length; i++) {
            if (array[i] % 2 == 0) {
                queue2.push(array[i]);
            } else {
                queue1.push(array[i]);
            }
        }
        int index = 0;
        while (queue1.size() > 0) {
            int tmp = queue1.front();
            queue1.pop();
            array[index] = tmp;
            index++;
        }
        while (queue2.size() > 0) {
            int tmp = queue2.front();
            queue2.pop();
            array[index] = tmp;
            index++;
        }
    }
};