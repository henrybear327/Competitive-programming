class Solution {
// binary search won't work!!
// 11000011

public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> prev;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prev.count(sum) == 0)
                prev[sum] = i; 
            else
                ans = max(ans, i - prev[sum]);
            
            sum += nums[i] == 1 ? 1 : -1;
        }
        
        if(prev.count(sum) > 0)
            ans = max(ans, (int)nums.size() - prev[sum]);
        
        return ans;
    }
};

class Solution {
// binary search won't work!!
// 11000011

public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int prev[nums.size() * 2 + 1];
        fill(prev, prev + nums.size() * 2 + 1, -1);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prev[sum + nums.size()] == -1)
                prev[sum + nums.size()] = i;
            else
                ans = max(ans, i - prev[sum + nums.size()]);

            sum += nums[i] == 1 ? 1 : -1;
        }

        if(prev[sum + nums.size()] != -1)
            ans = max(ans, (int)nums.size() - prev[sum + nums.size()]);

        return ans;
    }
};
