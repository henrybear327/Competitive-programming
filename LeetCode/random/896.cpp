static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int cnt[3] = {0};
        for(int i = 1; i < A.size(); i++) {
            int diff = A[i] - A[i - 1];
            if(diff > 0)
                cnt[2]++;
            else if(diff == 0)
                cnt[1]++;
            else
                cnt[0]++;
        }
        
        if(cnt[0] != 0 && cnt[2] != 0)
            return false;
        return true;
    } 
};

/*
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool ans = true;
        for(int i = 1; i < A.size(); i++)
            if(A[i - 1] <= A[i])
                continue;
            else
                ans = false;
        
        if(ans == false) {
            ans = true;
            reverse(A.begin(), A.end());
            for(int i = 1; i < A.size(); i++)
            if(A[i - 1] <= A[i])
                continue;
            else
                ans = false;
        }
        
        return ans;
    }
};
*/
