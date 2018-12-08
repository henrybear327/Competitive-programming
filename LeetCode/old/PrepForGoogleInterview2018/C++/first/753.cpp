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

// not sure why greedy works (from k - 1 -> 0) though
// DFS will work, simply do the same thing!
// Proof? Euler graph!
class Solution
{
private:
    bool dfs(string ans, unordered_set<string> &seen, int &ub, int &n, int &k,
             string &ret)
    {
        if ((int)seen.size() == ub) {
            ret = ans;
            return true;
        }

        int len = ans.length();
        string cand = ans.substr(len - n + 1);
        for (int i = 0; i < k; i++) {
            if (seen.count(cand + to_string(i)) == 0) {
                seen.insert(cand + to_string(i));
                if (dfs(ans + to_string(i), seen, ub, n, k, ret)) {
                    return true;
                }
                seen.erase(cand + to_string(i));
            }
        }

        return false;
    }

public:
    string crackSafe(int n, int k)
    {
        int ub = k;
        for (int i = 1; i < n; i++)
            ub *= k;

        // solve
        string ans, ret;
        for (int i = 0; i < n; i++)
            ans += '0';

        unordered_set<string> seen;
        seen.insert(ans);
        dfs(ans, seen, ub, n, k, ret);

        return ret;
    }

    // string crackSafe(int n, int k)
    // {
    //     unordered_set<string> occurrence;
    //     int ub = k;
    //     for (int i = 1; i < n; i++)
    //         ub *= k;
    //     string prev = "";
    //     for (int i = 0; i < n - 1; i++)
    //         prev += "0";
    //     string ans = prev;
    //     while ((int)occurrence.size() < ub) {
    //         for (int i = k - 1; i >= 0; i--) {
    //             string cand = prev + to_string(i);
    //             // cout << "cand = " << cand << endl;
    //             if (occurrence.count(cand) == 0) {
    //                 occurrence.insert(cand);
    //                 ans += i + '0';
    //                 prev = cand.substr(1);
    //                 // cout << "prev = " << prev << endl;
    //                 break;
    //             }
    //         }
    //     }

    //     return ans;
    // }
};

#ifdef LOCAL
int main()
{
    cout << Solution().crackSafe(2, 2) << endl;
    return 0;
}
#endif