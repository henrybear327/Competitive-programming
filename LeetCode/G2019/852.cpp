class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // O(n)
        int mx = -1;
        int idx = -1;
        for(int i = 0; i < (int)A.size(); i++)
            if(A[i] > mx) {
                mx = A[i];
                idx = i;
            }
        
        return idx;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
	// O(logn)
        int l = 0, r = (int)A.size() - 1;
        
        while(r - l > 1) {
            int mid = (l + r) / 2;
            
            if(A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) 
                return mid;
            else if(A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
                l = mid;
            else
                r = mid;
        }
        
        return -1;
        
        
    }
};
