class Solution {
public:
    bool equal(double a, double b) {
        if ( a-b >= -0.00001 && a-b <= 0.00001) return true;
        else return false;
    }
    double PowerWithAbsExponent(double base, int absExponent) {
        double result = 1.0;
        while (absExponent--) {
            result *= base;
        }
        return result;
    }
    double Power(double base, int exponent) {
        if (equal(base, 0.0) && exponent< 0) {
            cout << "Invalid input" << endl;
            return 0.1234;
        }
        if (exponent == 0) {
            return 1.0; // 约定0的0次幂等于1
        }
        int absExponent = exponent > 0 ? exponent : -exponent;
        double result = PowerWithAbsExponent(base, absExponent);
        if (exponent > 0)
            return result;
        else
            return 1 / result;
    }
};