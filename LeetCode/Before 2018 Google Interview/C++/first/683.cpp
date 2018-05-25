#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
/*
[1,3,2]
1
[1,3,5,2,4,6]
1
[2,4,1,3,5,6]
1
[2,4,1,3,5,6]
2
[2,4,1,3,5,6]
3
[3,9,2,8,1,6,10,5,4,7]
1
*/
class Solution
{
public:
    int kEmptySlots(vector<int> &flowers, int k)
    {
        // cout << "-------" << endl;
        // O(n)
        // observation
        // build pos[n], where pos[i] means ith position blossom on the pos[i] day
        // find an interval [l, r]
        // where r - l == k + 1 (k positions between them)
        // and
        // every element in j = (l, r), pos[j] > pos[l] and pos[r]
        // this means that between all positions between l and r blossoms no sooner
        // than l and r
        int n = flowers.size();
        if (n == 0) {
            return -1;
        }

        int pos[n + 1]; // position i blossom on pos[i] day
        for (int i = 0; i < n; i++)
            pos[flowers[i]] = i + 1;
        // for (int i = 1; i <= n; i++)
        // cout << i << " " << pos[i] << endl;

        int ans = INT_MAX;
        for (int l = 1; l < n; l++) {
            int r = l + k + 1;
            if (r > n)
                break;
            int mx = max(pos[l], pos[r]);

            bool ok = true;
            for (int j = l + 1; j < r; j++) {
                if (pos[j] < mx) {
                    l = j - 1;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // cout << l << " " << r << endl;
                ans = min(ans, max(pos[l], pos[r]));
                l = r - 1; // Important
            }
        }

        return ans == INT_MAX ? -1 : ans;
        // O(nlogn)
        // set<int> s;
        // int day = 1;
        // for (auto i : flowers) {
        //     s.insert(i);
        //     auto it = s.find(i);
        //     auto before = it, after = it;

        //     if (before != s.begin()) {
        //         before--;
        //         // printf("day %d, %d\n", day, *it - *before - 1);
        //         if (k == *it - *before - 1) {
        //             return day;
        //         }
        //     }

        //     after++;
        //     if (after != s.end()) {
        //         // printf("day %d, %d\n", day, *after - *it - 1);
        //         if (k == *after - *it - 1) {
        //             return day;
        //         }
        //     }

        //     day++;
        // }

        // return -1;
    }
};

#ifdef LOCAL
int main()
{
    vector<int> inp({2, 4, 1, 3, 5, 6});
    int k = 2;
    cout << Solution().kEmptySlots(inp, k) << endl;
    return 0;
}
#endif