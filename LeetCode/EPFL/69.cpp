class Solution {
public:
    int mySqrt(int x) {
        long long int l = 0, r = 50000;
        while(r - l > 1) {
            long long int mid = l + (r - l) / 2; // [l, r)
            if(mid * mid <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }
};
