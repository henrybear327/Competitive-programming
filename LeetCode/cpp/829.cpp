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

class Solution
{
public:
    int consecutiveNumbersSum(int N)
    {
        // N = s+1 + s+2 + s+3 ... + s+k
        // 2N = k(2s + k + 1)

        // 2N > k
        // due to k^2 on the right hand side, we can further push the limit
        // 2N > k^2

        int ans = 0;
        for (int k = 1; k * k < 2 * N; k++) {
            if (2 * N % k != 0)
                continue;
            if ((2 * N / k - k - 1) % 2 == 0) {
                int s = (2 * N / k - k - 1) / 2;
                // cout << "s " << s + 1 << endl;
                if (k * (2 * s + k + 1) == 2 * N)
                    ans++;
            }
        }

        return ans;
    }
};

// handle special cases first
// [], "", ...
// range of input?
/*
// two-pointer won't work for large test cases
class Solution
{
public:
    int slow(int N)
    {
        int ans = 0;
        for (int start = 1; start <= N; ++start) {
            int target = N, x = start;
            while (target > 0)
                target -= x++;
            if (target == 0) {
                ans++;
                cout << "start " << start << endl;
            }
        }
        return ans;
    }

    int ans(int N)
    {
        while ((N & 1) == 0)
            N >>= 1;
        int ans = 1, d = 3;

        while (d * d <= N) {
            int e = 0;
            while (N % d == 0) {
                N /= d;
                e++;
            }
            ans *= e + 1;
            d += 2;
        }

        if (N > 1)
            ans <<= 1;
        return ans;
    }

    int consecutiveNumbersSum(int N, bool show = false)
    {
        int left = 1;
        int sum = 1, ans = 0;
        for (int right = 2; right < 1e7 && left <= N; right++) { // [left,
right) while (left < right && sum > N) { sum -= left; left++;
            }

            if (sum == N) {
                if (show)
                    cout << "left " << left << endl;
                ans++;
            }

            sum += right;
        }

        return ans;
    }
};
*/

#ifdef LOCAL
int main()
{
    cout << Solution().consecutiveNumbersSum(5) << endl;
    // for (int i = 1; i < 1000000; i++)
    //     if (Solution().ans(i) != Solution().consecutiveNumbersSum(i)) {
    //         cout << i << " " << Solution().ans(i) << " "
    //              << " " << Solution().slow(i) << endl
    //              << Solution().consecutiveNumbersSum(i, true) << endl;
    //         break;
    //     }
    return 0;
}
#endif