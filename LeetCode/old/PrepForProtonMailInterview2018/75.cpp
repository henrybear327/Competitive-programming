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
    void sortColors(vector<int> &nums)
    {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 0 && i >= zero) {
                swap(nums[i], nums[zero]);
                zero++;
                i--;
            } else if (nums[i] == 2 && i <= two) {
                swap(nums[i], nums[two]);
                two--;
                i--;
            }
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
