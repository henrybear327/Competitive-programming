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

// code using look-ahead logic -> life is a lot more easier
class Solution
{
private:
    string conv(int a, int b)
    {
        return to_string(a) + to_string(b);
    }

    unordered_map<string, bool> dp;
    bool match(string s, string p, int ps, int pp)
    {
        if (dp.find(conv(ps, pp)) != dp.end())
            return dp[conv(ps, pp)];

        if ((int)p.length() == pp) {        // no more pattern to match
            bool ret = (int)s.length() == ps; // empty string or not
            dp[conv(ps, pp)] = ret;
            return ret;
        }

        if ((int)s.length() == ps) { // run down the regex :)
            while (pp < (int)p.length()) {
                if (pp + 1 < (int)p.length() &&
                    p[pp + 1] == '*') // skip match all cases
                    pp += 2;
                else { // others: failing...
                    dp[conv(ps, pp)] = false;
                    return false;
                }
            }
            dp[conv(ps, pp)] = true;
            return true;
        }

        if (pp + 1 < (int)p.length() && p[pp + 1] == '*') { // a * term
            // match 0 or match 1+
            // case char or .
            bool ret =
                match(s, p, ps, pp + 2) ||
                (p[pp] == '.' ? match(s, p, ps + 1, pp)
                 : (p[pp] == s[ps] ? match(s, p, ps + 1, pp) : false));
            dp[conv(ps, pp)] = ret;
            return ret;
        } else { // a normal term
            // case char or .
            bool ret = p[pp] == '.'
                       ? match(s, p, ps + 1, pp + 1)
                       : (p[pp] == s[ps] ? match(s, p, ps + 1, pp + 1) : false);
            dp[conv(ps, pp)] = ret;
            return ret;
        }
    }

public:
    bool isMatch(string s, string p)
    {
        // return regex_match(s, regex(p));

        return match(s, p, 0, 0);
    }
};

// // code using look-ahead logic -> life is a lot more easier
// class Solution
// {
// private:
//     bool match(string s, string p, int ps, int pp)
//     {
//         if ((int)p.length() == pp) {    // no more pattern to match
//             return (int)s.length() == ps; // empty string or not
//         }

//         if ((int)s.length() == ps) { // run down the regex :)
//             while (pp < (int)p.length()) {
//                 if (pp + 1 < (int)p.length() && p[pp + 1] == '*')
//                     pp += 2;
//                 else
//                     return false;
//             }
//             return true;
//         }

//         if (pp + 1 < (int)p.length() && p[pp + 1] == '*') { // a * term
//             // match 0 or match 1+
//             // case char or .
//             return match(s, p, ps, pp + 2) ||
//                    (p[pp] == '.'
//                     ? match(s, p, ps + 1, pp)
//                     : (p[pp] == s[ps] ? match(s, p, ps + 1, pp) : false));
//         } else { // a normal term
//             // case char or .
//             return p[pp] == '.'
//                    ? match(s, p, ps + 1, pp + 1)
//                    : (p[pp] == s[ps] ? match(s, p, ps + 1, pp + 1) : false);
//         }
//     }

// public:
//     bool isMatch(string s, string p)
//     {
//         // return regex_match(s, regex(p));

//         return match(s, p, 0, 0);
//     }
// };

#ifdef LOCAL
int main()
{
    {
        string s = "";
        string p = "";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "aa";
        string p = "a*";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "cabc";
        string p = "c.*c";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "cab";
        string p = "c.*c";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "aab";
        string p = "c*a*b*";
        cout << Solution().isMatch(s, p) << endl;
    }
    {
        string s = "a";
        string p = "ab*";
        cout << Solution().isMatch(s, p) << endl;
    }
    return 0;
}
#endif