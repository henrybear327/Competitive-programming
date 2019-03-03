class Solution {
public:
    int findComplement(int num) {
        bool started = false;
        for(int i = 31; i >= 0; i--) {
            if(started) {
                num ^= (1 << i);
            } else {
                if((num >> i) & 1) {
                    started = true;
                    i++;
                }
            }
        }
        
        return num;
    }
};
