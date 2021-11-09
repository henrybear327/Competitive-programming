class Solution {
public:
    bool isPerfectSquare(int num) {
        /*
        // straight forward implementation
        
        int tmp = int(sqrt(num));
        return tmp * tmp == num;
        */
        
        // binary search
        int l = 0, r = 46341; // [l, r)
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(mid * mid <= num) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return l * l == num;
    }
};
