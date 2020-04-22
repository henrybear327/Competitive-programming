class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target)
                return i;
        return -1;
    }
};
