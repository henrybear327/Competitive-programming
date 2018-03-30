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
    // fix a number, and search other 2 numbers
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) // skip consecutive values for i
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k && j < (int)nums.size() && i < k) {
                // -a == b + c
                int a = -nums[i], b = nums[j], c = nums[k];

                if (a == b + c) {
                    vector<int> res({-a, b, c});
                    ans.push_back(res);

                    while (j < k && b == nums[j])
                        j++;
                    while (j < k && c == nums[k])
                        k--;
                } else if (a > b + c) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
        // /*
        //  case 1: 0 + x + -x
        //  case 2: 0 + 0 + 0
        //  case 3: a + b + c, where a + b == -c
        // */

        // unordered_map<int, int> cnt;
        // set<vector<int>> s;
        // for (auto i : nums)
        //     cnt[i]++;

        // vector<vector<int>> ans;
        // // case 2
        // if (cnt[0] >= 3) {
        //     vector<int> tmp({0, 0, 0});
        //     sort(tmp.begin(), tmp.end());
        //     s.insert(tmp);
        // }

        // // case 1
        // if (cnt[0] > 0) {
        //     for (auto i : cnt) {
        //         if (i.first == 0 || i.first < 0)
        //             continue;
        //         if (cnt.find(-i.first) != cnt.end()) {
        //             vector<int> tmp({0, i.first, -i.first});
        //             sort(tmp.begin(), tmp.end());
        //             s.insert(tmp);
        //         }
        //     }
        // }

        // // case 3
        // for (auto i = cnt.begin(); i != cnt.end(); i++) {
        //     if (i->first == 0)
        //         continue;

        //     auto j = i;
        //     j++;
        //     for (; j != cnt.end(); j++) {
        //         if (i->first == j->first || j->first == 0 ||
        //             i->first + j->first == 0) // missed the last case
        //             continue;

        //         int k = -(i->first + j->first);
        //         if (i->first == k || j->first == k) // missed this case
        //             if (cnt[k] < 2)
        //                 continue;

        //         if (cnt.find(k) != cnt.end()) {
        //             vector<int> tmp({i->first, j->first, k});
        //             sort(tmp.begin(), tmp.end());
        //             s.insert(tmp);
        //         }
        //     }
        // }

        // for (auto i : s)
        //     ans.push_back(i);
        // return ans;

        // brute force
        // set<vector<int>> s;
        // vector<vector<int>> ans;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        //     for (int j = i + 1; j < n; j++)
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> tmp({nums[i], nums[j], nums[k]});
        //                 sort(tmp.begin(), tmp.end());
        //                 s.insert(tmp);
        //             }
        //         }

        // for (auto i : s)
        //     ans.push_back(i);
        // return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif