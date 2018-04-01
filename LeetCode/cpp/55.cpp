#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
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
    // observation
    // starting from the last index
    // we keep extenting the farthest left index that can jump up to the last
    // index
    bool canJump(vector<int> &nums)
    {
        int ok = (int)nums.size() - 1;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= ok) {
                ok = i;
            }
        }

        return ok == 0;
    }

    // O(N^2)
    // bool canJump(vector<int> &nums)
    // {
    //     bool ok[nums.size()];
    //     memset(ok, false, sizeof(ok));
    //     for (int i = (int)nums.size() - 1; i >= 0; i--) {
    //         if (i + nums[i] >= (int)nums.size() - 1)
    //             ok[i] = true;
    //         else {
    //             for (int j = i; j <= i + nums[i] && j < (int)nums.size(); j++)
    //             {
    //                 if (ok[j]) {
    //                     ok[i] = true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }

    //     return ok[0];
    // }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif