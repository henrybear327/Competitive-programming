class Solution {
public:
    int romanToInt(string s) {
        map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            int orig = ret;
            if(i + 1 < s.size()) {
                char nc = s[i + 1];
                if(c == 'I' && nc == 'V')
                    ret += 4;
                if(c == 'I' && nc ==  'X')
                    ret += 9;
                if(c == 'X' && nc ==  'L')
                    ret += 40;
                if(c == 'X' && nc ==  'C')
                    ret += 90;
                if(c == 'C' && nc ==  'D')
                    ret += 400;
                if(c == 'C' && nc ==  'M')
                    ret += 900;
                
                if(ret != orig) {
                    i++;
                    continue;
                }
            } 

            ret += val[c];
        }

        return ret;
    }
};
