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
    int findDuplicate(vector<int> &nums)
    {
        srand(time(NULL));
        int sz = nums.size();
        while (1) {
            int cand = nums[rand() % (sz - 1)];
            int cnt = 0;
            for (int i = 0; i < sz; i++)
                if (nums[i] == cand)
                    cnt++;
            if (cnt >= 2)
                return cand;
        }

        return -1;
    }
};

int main()
{
    return 0;
}