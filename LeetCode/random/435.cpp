class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
            return 0;

        sort(intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        // for(auto i : intervals)
        // cout << i[0] << " " << i[1] << endl;

        int dp[n] = {0};
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (intervals[i][0] < intervals[j][1]) {

                } else {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break;
                }
            }
            // cout << i << " " << dp[i] << endl;

            dp[i] = max(dp[i - 1], dp[i]);
        }

        return n - dp[n - 1];
    }
};
