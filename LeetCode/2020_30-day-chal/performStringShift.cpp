class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int head = 0;
        for(auto i : shift) {
            if(i[0] == 0) {
                head = (head + i[1]) % s.length();
            } else {
                head = (head - i[1] + s.length() * 100) % s.length();
            }
        }
        
        return s.substr(head, s.length()) + s.substr(0, head);
    }
};
