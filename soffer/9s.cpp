
class Solution {
public:
    int Fibonacci(int n) {
        // 这种解法的思路就是不断向前移动a,b
        int a=0, b=1;
        for (int i=1; i<=n; i++) {
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
        
    }
};