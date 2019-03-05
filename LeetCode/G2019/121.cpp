class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // three passes
        int n = prices.size();
        if (n == 0)
            return 0;

        int mn[n], mx[n];
        mn[0] = prices[0];
        for (int i = 1; i < n; i++)
            mn[i] = min(mn[i - 1], prices[i]);
        mx[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
            mx[i] = max(mx[i + 1], prices[i]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, mx[i] - mn[i]);

        return ans;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // one pass
        if (prices.size() == 0)
            return 0;

        int mn = prices.front(), ans = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] > mn)
                ans = max(ans, prices[i] - mn);
            else
                mn = prices[i];
        }

        return ans;
    }
};