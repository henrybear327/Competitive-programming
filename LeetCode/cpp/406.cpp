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

typedef pair<int, int> ii;

class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        sort(people.begin(), people.end(), [](const ii &a, const ii &b) -> bool {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

        vector<ii> ans;
        for (auto i : people)
            ans.insert(next(ans.begin(), i.second), i);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
