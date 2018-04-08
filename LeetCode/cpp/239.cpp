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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<pair<int, int>> mx;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (mx.size() > 0 && mx.front().second <= i - k) // pop old
                mx.pop_front();
            while (mx.size() > 0 && mx.back().first < nums[i]) // pop small back
                // enough, since if you have a larger element in the middle of deque
                // it will already pop all smaller elements in front of it
                mx.pop_back();

            mx.push_back(make_pair(nums[i], i));
            if (i < k - 1)
                continue;
            ans.push_back(mx.front().first);
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