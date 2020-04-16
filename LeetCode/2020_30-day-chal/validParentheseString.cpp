#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        // left to right
        int l = 0, r = 0;
        for (auto c : s) {
            if (c != ')')
                l++;
            else
                r++;

            if (l < r)
                return false;
        }

        reverse(s.begin(), s.end());
        l = 0, r = 0;
        // right to left
        for (auto c : s) {
            if (c != '(')
                l++;
            else
                r++;

            if (l < r)
                return false;
        }

        return true;
    }
    bool checkValidStringWA(string s)
    {
        //**(*((

        int cnt = 0;
        int balance = 0;
        for (auto c : s) {
            if (c == '*')
                cnt++;
            else if (c == '(')
                balance++;
            else {
                if (balance > 0)
                    balance--;
                else {
                    if (cnt > 0)
                        cnt--;
                    else
                        return false;
                }
            }
        }

        return balance == 0 || (balance - cnt <= 0);
    }
};

int main()
{
    auto sol = Solution();

    int N = 6;
    const char *inp = "()*";
    while (true) {
        string t = "";
        for (int i = 0; i < N; i++) {
            t += inp[rand() % 3];
        }

        if (sol.checkValidString(t) != sol.checkValidStringWA(t)) {
            printf("%s\n", t.c_str());
            break;
        }
    }

    return 0;
}
