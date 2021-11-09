class Solution {
private:
    void qSort(int lb, int rb, vector<int> &nums) { // [lb, rb)
        int n = rb - lb;
        
        // terminating condition
        if(n <= 1) {
            return;
        }
        
        int pivot = lb + rand() % n;
        swap(nums[rb - 1], nums[pivot]); // pivot init at rb - 1
        pivot = rb - 1; // lol
        
        int i = lb;
        while(i != pivot) { 
            if(i < pivot) {
                if(nums[i] <= nums[pivot]) {
                    i++;
                } else {
                    swap(nums[i], nums[pivot]);
                    swap(pivot, i);
                    i--;
                }
            } else {
                if(nums[pivot] > nums[i]) {
                    swap(nums[i], nums[pivot]);
                    swap(pivot, i);
                    i++;
                } else {
                    i--;
                }
            }
        }

        qSort(lb, i, nums);
        qSort(i + 1, rb, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        qSort(0, nums.size(), nums);
        
        return nums;
        
        /*
        // straight forward implementation of quick sort
        int n = nums.size();
        
        // terminating condition
        if(n <= 1) {
            return nums;
        }
        
        int pivot = rand() % n;
        vector<int> left, right;
        for(int i = 0; i < n; i++) {
            if(i != pivot) {
                if(nums[i] <= nums[pivot]) {
                    left.push_back(nums[i]);
                } else {
                    right.push_back(nums[i]);
                }
            }
        }
        
        left = sortArray(left);
        right = sortArray(right);
        
        vector<int> ret(left);
        ret.push_back(nums[pivot]);
        ret.insert(ret.end(), right.begin(), right.end());
        
        return ret;
        */
    }
};
