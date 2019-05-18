class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) return 0;
        int a=1, b=2;
        while (--number) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
    }
};