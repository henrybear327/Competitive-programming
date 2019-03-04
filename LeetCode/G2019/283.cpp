class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0, zero = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zero++;
            else
                nums[idx] = nums[i], idx++;
        }
        
        for(int i = 0 ; i < zero; i++)
            nums[idx++] = 0;
    }
};
