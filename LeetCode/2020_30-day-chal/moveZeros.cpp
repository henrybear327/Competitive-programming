class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        // O(n^2)
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == 0) {
        //         for(int j = i + 1; j < n; j++) {
        //             if(nums[j] != 0) {
        //                 swap(nums[i], nums[j]);
        //                 break;
        //             }
        //         }
        //     }
        // }
        
        // O(n)
        int zero = 0;
        for(int i = 0; i < n; i++)
            zero++;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                nums[idx] = nums[i], idx++;
        }
        
        for(int i = idx; i < n; i++)
            nums[i] = 0;
    }
};
