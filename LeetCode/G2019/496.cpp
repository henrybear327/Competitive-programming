class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        for(auto i : findNums) {
            for(int j = 0; j < (int)nums.size(); j++) {
                if(i == nums[j]) {
                    int val = -1;
                    for(int k = j + 1; k < (int)nums.size(); k++) {
                        if(nums[k] > i) {
                            val = nums[k];
                            break;
                        }
                    }
                    
                    ans.push_back(val);
                    break;
                }
            }
        }
        return ans;
    }
};
