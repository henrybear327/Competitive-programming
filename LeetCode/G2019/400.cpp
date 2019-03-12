class Solution {
public:
    int findNthDigit(int n) {
        long long size = 9, digits = 1, base = 1;
        while(n - size * digits > 0) {
            n -= size * digits;
            size *= 10;
            base *= 10;
            digits++;
        }
                
        n--; // 0-based
        long long rem = n % digits;
        n /= digits; 
        
        base += n;
                
        int de[digits], i = 0;
        while(base > 0) {
            de[i] = base % 10;
            base /= 10;
            i++;
        }
        reverse(de, de + i);
        
        return de[rem];
    }
};
