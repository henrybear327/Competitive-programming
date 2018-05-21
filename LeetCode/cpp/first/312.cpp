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

// What a solution!
// Instead of doing it like the cutting stick
// e.g. ab c def, if you kick blow c first and recurse, you can't have bd
// easily! We do it reversely! e.g. we think of the last balloon being bursted!
// class Solution
// {
// private:
//     vector<vector<int>> dp;
//     int cuttingStick(vector<int> &nums, int l, int r) // (l, r)
//     {
//         // printf("l %d r %d\n", l, r);
//         if (l + 1 == r)
//             return 0;

//         if (dp[l][r] != -1)
//             return dp[l][r];

//         for (int i = l + 1; i < r; i++) { // for every balloon as the last
//         one being bursted
//             int tmp = nums[l] * nums[i] * nums[r];
//             // printf("i = %d, %d\n", i, tmp);
//             dp[l][r] = max(dp[l][r],
//                            cuttingStick(nums, l, i) + tmp +
//                            cuttingStick(nums, i, r));
//         }

//         return dp[l][r];
//     }

// public:
//     int maxCoins(vector<int> &nums)
//     {
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         int n = (int)nums.size();
//         for (int i = 0; i < n; i++) {
//             vector<int> inp(n, -1);
//             dp.push_back(inp);
//         }
//         return cuttingStick(nums, 0, n - 1);
//     }
// };

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int originalLength = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= originalLength; len++) {
            for (int left = 1; left <= originalLength; left++) { // [left, right]
                int right = left + len - 1;
                if (right > originalLength)
                    break;

                for (int k = left; k <= right; k++) { // try bursting every position
                    // CRUCIAL! understand this line and you are done
                    // printf("l %d k %d r %d\n", left, k, right);
                    int center = nums[left - 1] * nums[k] * nums[right + 1];
                    int tmp = dp[left][k - 1] + center + dp[k + 1][right];
                    // printf("done\n");

                    dp[left][right] = max(dp[left][right], tmp);
                }
            }
            // printf("len %d\n", len);
            // for (int i = 0; i < n; i++)
            //     for (int j = 0; j < n; j++)
            //         printf("%4d%c", dp[i][j], j == n - 1 ? '\n' : ' ');
        }
        return dp[1][originalLength];
    }
};

// https://blog.csdn.net/Zarlove/article/details/76577460
// class Solution
// {
// public:
//     int maxCoins(vector<int> &nums)
//     {
//         int n = nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(), 1);
//         vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
//         for (int len = 1; len <= n; len++) { // original nums array index
//         0~n-1
//             printf("len = %d\n", len);
//             for (int start = 1; start <= n - len + 1; start++) {
//                 int end = start + len - 1;

//                 int maxC = 0;
//                 for (int k = start; k <= end; k++) {
//                     int temp = dp[start][k - 1] +
//                                nums[start - 1] * nums[k] * nums[end + 1] +
//                                dp[k + 1][end];
//                     printf("%d %d %d, temp %d\n", start, k, end, temp);
//                     printf("%d %d %d %d %d\n", dp[start][k - 1], nums[start -
//                     1], nums[k],
//                            nums[end + 1], dp[k + 1][end]);
//                     maxC = (maxC < temp) ? temp : maxC;
//                 }
//                 dp[start][end] = maxC;
//             }
//             {
//                 for (int i = 0; i <= n; i++)
//                     for (int j = 0; j <= n; j++)
//                         printf("%4d%c", dp[i][j], j == n ? '\n' : ' ');
//             }
//         }
//         return dp[1][n];
//     }
// };

#ifdef LOCAL
int main()
{
    vector<int> inp({3, 1, 5, 8});
    cout << Solution().maxCoins(inp) << endl;
    return 0;
}
#endif