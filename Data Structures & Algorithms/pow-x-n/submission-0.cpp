class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, abs(n));

        if (n >= 0) {
            return res;
        }
        return 1 / res;
    }

    double helper(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == 2) {
            return x * x;
        }
        
        double res = helper(x, abs(n / 2));
        res *= res;
        if (abs(n) % 2 == 1) {
            res *= x;
        }
        return res;
    }
};
