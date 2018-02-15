// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int x = []()
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
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }
};

int main()
{
    return 0;
}