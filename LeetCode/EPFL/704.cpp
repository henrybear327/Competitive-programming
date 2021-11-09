class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(r - l > 1) {
            int mid = (l + r) / 2;
            
            if(nums[mid] < target)
                l = mid;
            else if(nums[mid] > target)
                r = mid;
            else
                return mid;
        }
        
        return nums[l] == target ? l : -1; // Oops
    }
};
