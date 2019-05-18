class Solution {
public:
    int  NumberOf1(int n) {
        // 有可能是负数,右移的时候就要小心,始终会补1.
        int bit = 32;
        int count = 0;
        while (bit--) {
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};