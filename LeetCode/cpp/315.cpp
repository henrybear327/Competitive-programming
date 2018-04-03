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

struct BIT {
    int *data;
    int N;
    void init(int _n)
    {
        N = _n + 10;
        data = (int *)malloc(sizeof(int) * N); // 1-based
        for (int i = 0; i < N; i++)
            data[i] = 0;
    }

#define LSB(x) (x & -x)

    void add(int pos, int val)
    {
        for (; pos < N; pos += LSB(pos))
            data[pos] += val;
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= LSB(pos))
            res += data[pos];
        return res;
    }
};

class Solution
{
public:
    // stable merge sort solution is amazing
    vector<int> countSmaller(vector<int> &nums)
    {
        // lisan
        vector<int> lisan = nums;
        {
            sort(lisan.begin(), lisan.end());
            auto it = unique(lisan.begin(), lisan.end());
            lisan.resize(distance(lisan.begin(), it));
        }

        for (auto &i : nums) {
            int pos = lower_bound(lisan.begin(), lisan.end(), i) - lisan.begin();
            i = pos + 2; // !!
        }

        // use BIT
        BIT bit;
        bit.init(lisan.size());

        vector<int> ans(nums.size(), 0);
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            ans[i] = bit.query(nums[i] - 1);
            bit.add(nums[i], 1);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    vector<int> inp({-1, -2, -3, -4});
    auto ans = Solution().countSmaller(inp);
    for (auto i : ans)
        printf("%d ", i);
    puts("");

    return 0;
}
#endif