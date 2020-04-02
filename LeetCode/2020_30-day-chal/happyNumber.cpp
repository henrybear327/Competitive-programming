class Solution {
private: 
    int cal(int n) {
        int ret = 0;
        
        while(n > 0) {
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return ret;
    }
public:
    bool isHappy(int n) {
        set<int> seen;
        
        while(n != 1) {
            if(seen.count(n) == 1)
                return false;
            seen.insert(n);
            n = cal(n);
        }
        
        return true;
    }
};
