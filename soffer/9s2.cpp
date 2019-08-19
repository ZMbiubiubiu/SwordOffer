class Solution {
public:
    int jumpFloor(int number) {
        int a=1, b=2;
        for (int i=2; i<=number; i++) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
    }
};