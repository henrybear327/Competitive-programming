class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        
        int mn[prices.size()];
        int mx[prices.size()];

        mn[0] = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            mn[i] = min(mn[i - 1], prices[i]);
        }

        mx[prices.size() - 1] = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], prices[i]);
        }

        for(int i = 1; i < prices.size(); i++) {
            ret = max(ret, mx[i] - mn[i - 1]);
        }

        return ret;
    }
};
