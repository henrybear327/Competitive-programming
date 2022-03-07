class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto check = [](string str) -> stack<char> {
            stack<char> stk;
            for(const auto &c : str) {
                if(c == '#') {
                    if(stk.size() > 0) {
                        stk.pop();
                    }
                } else {
                    stk.push(c);
                }
            }

            return stk;
        }; 

        auto s1 = check(s);
        auto s2 = check(t);

        if(s1.size() == s2.size()) {
            while(s1.size() > 0) {
                if(s1.top() != s2.top()) {
                    return false;
                }
                s1.pop();
                s2.pop();
            }
        } else {
            return false;
        }    

        return true;
    }
};
