class Solution {
public:
    double myPow(double x, int _n) {
        bool isNeg = _n < 0;
        long long int n = isNeg ? -1LL * _n : _n;

        double ret = 1.0;
        double base = x;
        while(n > 0) {
            if(n & 1) {
                ret *= base;
            }
            base = base * base;
            n >>= 1;
        }

        if(isNeg) {
            ret = 1/ret;
        }

        return ret;
    }
};
