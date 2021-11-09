class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = nums.size() - 1;
        for(int i = 0; i <= pos;) {
            while(i <= pos && nums[i] == val) {
                swap(nums[i], nums[pos]);
                pos--;
            }
            i++;
        }
        
        return pos + 1;
    }
};
