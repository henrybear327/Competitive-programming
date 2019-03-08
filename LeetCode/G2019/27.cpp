class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int put = 0;
        for(int i = 0; i < (int)nums.size(); i++) {
            if(nums[i] != val) {
                swap(nums[i], nums[put]);
                put++;
            }
        }
        
        return put;
    }
};
