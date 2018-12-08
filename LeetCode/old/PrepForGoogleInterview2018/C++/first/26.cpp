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
class Solution
{
private:
    vector<int>::iterator myunique(vector<int>::iterator s,
                                   vector<int>::iterator t)
    {
        // empty
        if (s == t)
            return t;

        auto cand = s;
        for (; s != t; s++) {
            // 1 2 3 3 4 5 5
            // 1 1 2 3 3 
            if (*cand != *s) {
                cand++; 
                *cand = *s;
            }
        }

        return ++cand;
    }

public:
    int removeDuplicates(vector<int> &nums)
    {
        // auto it = unique(nums.begin(), nums.end());
        auto it = myunique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));

        return nums.size();
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif