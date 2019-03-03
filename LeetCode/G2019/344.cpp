class Solution {
private:
    void mySwap(char &a, char &b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }
    
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < (int)s.size() / 2; i++) 
            mySwap(s[i], s[s.size() - 1 - i]);
    }
};
