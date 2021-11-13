class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int mx = 0;
        
        vector<int> ans;
        for(int i = heights.size() - 1; i >= 0; i--) {
            if(heights[i] > mx)
                ans.push_back(i);
            mx = max(mx, heights[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
