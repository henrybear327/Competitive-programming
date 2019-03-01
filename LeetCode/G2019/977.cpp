class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // O(nlogn)
        for(auto &i : A)
            i *= i;
        sort(A.begin(), A.end());
        
        return A;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // two pointers
        // find 0 first, then expend around it
        
        int l = -1, r = A.size();
        int sz = A.size();
        
        vector<int> ans(sz);
        
        int idx = 0;
        if(A[0] < 0 && A[sz - 1] < 0)
            l = sz - 1;
        else if(A[0] > 0 && A[sz - 1] > 0)
            r = 0;
        else {
            l = INT_MIN;
            r = INT_MAX;
            for(int i = 0; i < sz; i++) {
                if(A[i] > 0) {
                    r = min(r, i);
                } else {
                    l = max(l, i);
                }
            }
            
            while(l >= 0 && A[l] == 0) 
                ans[idx++] = 0, l--;
        }
        
        while(l >= 0 || r < sz) {
            int left = INT_MAX, right = INT_MAX;
            if(l >= 0)
                left = -A[l];
            if(r < sz)
                right = A[r];
            
            if(left <= right) {
                l--;
                ans[idx++] = left * left;
            } else {
                r++;
                ans[idx++] = right * right;
            }
        }
        
        return ans;
    }
};
