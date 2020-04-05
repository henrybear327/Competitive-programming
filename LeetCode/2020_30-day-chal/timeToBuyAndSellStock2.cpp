class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int idx = 0;
        int ans = 0;
        for(int i = 1; i <= prices.size(); i++) {
            if(i == prices.size() || prices[i - 1] > prices[i]) {
                ans += prices[i - 1] - prices[idx];
                idx = i;
            }
        }
        
        return ans;
    }
};
