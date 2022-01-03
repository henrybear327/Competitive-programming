class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // !! Reverse two pointer !!
        int i = m + n - 1;
        int x = m - 1, y = n - 1;
        while(x >= 0 || y >= 0) {
            int candX = x >= 0 ? nums1[x] : INT_MIN;
            int candY = y >= 0 ? nums2[y] : INT_MIN;

            if(candX > candY) {
                x--;
                nums1[i] = candX;
            } else {
                y--;
                nums1[i] = candY;
            }
            i--;
        }
    }
};
