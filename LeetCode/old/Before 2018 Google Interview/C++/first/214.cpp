#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
private:
    bool isPalindrome(string s)
    {
        int n = (int)s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }

public:
    string shortestPalindrome(string s)
    {
        for (int i = (int)s.length(); i >= 1; i--) {
            // [0, i]
            if (isPalindrome(s.substr(0, i))) {
                string front = s.substr(i);
                reverse(front.begin(), front.end());
                return front + s;
            }
        }

        return s;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif