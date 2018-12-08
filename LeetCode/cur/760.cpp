// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, stack<int>> mapping;
        for (int i = 0; i < (int)B.size(); i++)
            mapping[B[i]].push(i);

        vector<int> ans;
        for (auto i : A) {
            auto &s = mapping[i];
            ans.push_back(s.top());
            s.pop();
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
