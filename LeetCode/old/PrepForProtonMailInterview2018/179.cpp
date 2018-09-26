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

bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> numstr;
        for (auto i : nums)
            numstr.push_back(to_string(i));
        sort(numstr.begin(), numstr.end(), cmp);

        string ans;
        for (auto i : numstr)
            ans += i;

        if (ans[0] == '0')
            ans = "0";
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
