// :%s/^ \*//g
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
    int majorityElement(vector<int> &nums)
    {
        srand(time(NULL));
        while (true) {
            int pos = rand() % (int)nums.size();
            int cnt = 0;
            for (auto i : nums) {
                if (i == nums[pos])
                    cnt++;
            }
            if (cnt > (int)nums.size() / 2)
                return nums[pos];
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
