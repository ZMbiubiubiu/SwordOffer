class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 边界检查
        // if (data.size() == 0) return ;
        int tmp = 0; 
        for (size_t i=0; i<data.size(); i++) {
            tmp ^= data[i];
        } // 最终tmp为num1与num2的亦或结果,然后根据亦或中某一位为1可以将整个data分成两组
        int first = FindFirstOne(tmp);
        *num1 = 0;
        *num2 = 0;
        for (size_t i=0; i<data.size(); i++) {
            int num = data[i];
            if ((num >> (first-1)) & 1) {
                *num1 ^= num;
            } else {
                *num2 ^= num;
            }
        }
    }
    int FindFirstOne(int num) {
        int index = 1;
        while (1) {
            if ((num & 1) == 1) break;
            num = num >> 1;
            index++;
        }
        return index;
    }
};