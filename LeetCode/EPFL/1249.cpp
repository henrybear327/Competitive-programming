class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pos;
                
        vector<bool> ok(s.size(), true);
        for(int i = 0; i < s.size(); i++) {    
            if(s[i] == '(') {
                pos.push(i);
            } else if(s[i] == ')') {
                if(pos.size() > 0) {
                    pos.pop();
                } else {
                    ok[i] = false;
                }
            }
        }
        
        
        while(pos.size() > 0) {
            ok[pos.top()] = false;
            pos.pop();
        }
                
        string ret = "";
        for(int i = 0; i < s.size(); i++) {
            if(ok[i])
                ret += s[i];
        }
        
        return ret;
    }
};
