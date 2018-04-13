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

// last input WTF
/*
[0,1,3,50,75]
0
99
[10, 20, 30]
0
40
[0,1,2,3,4]
0
4
[1,1,1]
1
1
[-2147483648,2147483647]
-2147483648
2147483647
*/
class Solution
{
private:
    inline string gen(int x, int y)
    {
        if (x == y)
            return to_string(x);
        return to_string(x) + "->" + to_string(y);
    }

public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> ans;
        if (nums.size() == 0)
            ans.push_back(gen(lower, upper));
        else {
            if (lower != nums.front()) {
                ans.push_back(gen(lower, nums.front() - 1));
            }
            int n = nums.size();
            for (int i = 1; i < n; i++) {
                if (nums[i] != nums[i - 1] + 1 && nums[i] != nums[i - 1]) {
                    ans.push_back(gen(nums[i - 1] + 1, nums[i] - 1));
                }
            }
            if (upper != nums.back()) {
                ans.push_back(gen(nums.back() + 1, upper));
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
