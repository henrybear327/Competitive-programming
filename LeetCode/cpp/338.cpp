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
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, -1);

        ans[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (ans[i] == -1) {
                int cnt = __builtin_popcount(i);
                ans[i] = cnt;
                for (int j = 1; (i << j) <= num; j++) {
                    ans[i << j] = cnt;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int num;
    scanf("%d", &num);

    Solution s;
    auto res = s.countBits(num);
    for (auto i : res)
        printf("%d ", i);
    return 0;
}
