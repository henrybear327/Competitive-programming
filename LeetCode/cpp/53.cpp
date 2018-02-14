// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = INT_MIN;
        int sum = 0;
        for (auto i : nums) {
            sum += i;

            sum = max(sum, i); // BUG!
            mx = max(mx, sum);
        }

        return mx;
    }
};

int main()
{
    return 0;
}