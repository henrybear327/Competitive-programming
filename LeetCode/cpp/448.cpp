// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // since the value range is in the size range
        // we can use this trick...
        for (auto &i : nums) {
            int pos = abs(i) - 1;
            nums[pos] = nums[pos] > 0 ? -nums[pos] : nums[pos];
        }

        vector<int> ans;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
    }
};

int main()
{
    return 0;
}