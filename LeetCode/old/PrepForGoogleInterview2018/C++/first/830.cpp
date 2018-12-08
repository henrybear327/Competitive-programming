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
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        int n = S.length();

        vector<vector<int>> ans;
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i != n && S[i] == S[i - 1])
                continue;
            else {
                if (i - start >= 3) {
                    ans.push_back(vector<int> {start, i - 1});
                }
                start = i;
            }
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