// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;

        map<vector<int>, vector<string>> res;
        for (auto i : strs) {
            vector<int> cnt(26, 0);
            for (auto j : i) {
                cnt[j - 'a']++;
            }
            res[cnt].push_back(i);
        }

        for (auto i : res) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif