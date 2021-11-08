class Solution {
public:
    int triangleNumber(vector<int>& nums) {                
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int cnt = 0;
        /* 
        a <= b <= c
        a + b > c -> b > c - a
        
        a b c -> b > c - a = 2
        2 3 4
        2 2 3 -> b > c - a = 1
        */
        
        /*
        // iterate ac and search for b
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j > i; j--) {
                int cand = nums[j] - nums[i];
                int idx = upper_bound(nums.begin() + i + 1, nums.begin() + j + 1, cand) - nums.begin();
                // cout << i << " " << j << " " << idx << endl;
                if(i < idx && idx < j) {
                    cnt += (j - idx);
                }
            }
        }
        */
        
        // iterate ab and search for c
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // a b c
                // a+b>c -> c<a+b
                
                // a...bvvvvvvvxxxxxxx
                //            lr
                // a...bxxxxxxxxxxxxxx
                //     lr
                // a...bvvvvvvvvvvvvvv
                //                   lr
                int left = j, right = n; // [left, right) -> both init to out of bound
                int target = nums[i] + nums[j];
                while(right - left > 1) {
                    int mid = (left + right) / 2;
                    
                    if(nums[mid] < target) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                
                if(left < n) {
                    cnt += left - j;
                }
            }
        }
        
        return cnt;
    }
};
