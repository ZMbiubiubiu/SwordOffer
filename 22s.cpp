#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    stack<int> s;
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 两个序列的大小不相等的话,那还判断个毛线...
        if (pushV.size() != popV.size()) return false; 
        int index1 = 0;
        int index2 = 0;
        while (index2 < popV.size()) {
            while (s.size() < 1 || s.top() != popV[index2]){
                s.push(pushV[index1]);
                index1++;
                if (index1 >= pushV.size() && s.top() != popV[index2]) {
                    return false;
                }
            }
            s.pop();
            index2++;
        }
        return true;
    }
};