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

// two pointers
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int mx = 0;
        unordered_map<char, int> cnt;
        for (int r = 0; r < (int)s.size(); r++) { // [l, r]
            cnt[s[r]]++;

            int sz = r - l + 1;
            while ((int)cnt.size() < sz) {
                if (cnt[s[l]] == 1)
                    cnt.erase(s[l]);
                else
                    cnt[s[l]]--;
                l++;

                sz = r - l + 1;
            }
            mx = max(mx, sz);
        }

        return mx;

        // int l = 0;
        // int mx = 0;
        // unordered_map<char, int> cnt;
        // int conflict = 0;
        // for (int r = 0; r < (int)s.size(); r++) { // [l, r]
        //     cnt[s[r]]++;
        //     if (cnt[s[r]] > 1)
        //         conflict++;

        //     int sz = r - l + 1;
        //     while (conflict > 0) {
        //         if (cnt[s[l]] > 1)
        //             conflict--;
        //         if (cnt[s[l]] == 1)
        //             cnt.erase(s[l]);
        //         else
        //             cnt[s[l]]--;
        //         l++;

        //         sz = r - l + 1;
        //     }
        //     mx = max(mx, sz);
        // }

        // return mx;
    }
};

// binary search
// class Solution
// {
// private:
//     bool check(string s, int mid)
//     {
//         unordered_map<char, int> cnt;
//         int conflict = 0;
//         for (int i = 0; i < mid; i++) {
//             cnt[s[i]]++;
//             if (cnt[s[i]] > 1)
//                 conflict++;
//         }

//         if (conflict == 0)
//             return true;

//         for (int i = mid; i < (int)s.size(); i++) {
//             if (cnt[s[i - mid]] > 1)
//                 conflict--;
//             cnt[s[i - mid]]--;

//             cnt[s[i]]++;
//             if (cnt[s[i]] > 1)
//                 conflict++;

//             if (conflict == 0)
//                 return true;
//         }

//         return false;
//     }

// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         if (s.size() == 0)
//             return 0;
//         int l = 1, r = (int)s.size() + 1;
//         while (r - l > 1) {
//             int mid = (l + r) / 2;
//             if (check(s, mid))
//                 l = mid;
//             else
//                 r = mid;
//         }

//         return l;
//     }
// };

#ifdef LOCAL
int main()
{
    return 0;
}
#endif