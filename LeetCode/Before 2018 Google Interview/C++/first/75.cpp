// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

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
    // in-place
    void sortColors(vector<int> &nums)
    {
        /*
        When you see:
        0: you swap with pos zero
        1: you ignore it
        2: you swap with pos two, and leave i as where it was
        */
        int zero = 0, two = (int)nums.size() - 1; // the next not-sure pos
        for (int i = 0; i <= two; i++) { // the terminating condition! WOW!!!!!
            if (nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
                i--; // you might be swapping two 2s
            }
        }
    }

    // counting sort
    // void sortColors(vector<int> &nums)
    // {
    //     int cnt[3] = {0};
    //     for (auto i : nums)
    //         cnt[i]++;

    //     int idx = 0;
    //     for (int i = 0; i < 3; i++)
    //         for (int j = 0; j < cnt[i]; j++)
    //             nums[idx++] = i;
    // }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif