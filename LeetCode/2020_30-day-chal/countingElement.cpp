class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> cnt;
        for(auto i : arr)
            cnt[i]++;
        
        int ans = 0;
        for(auto i : arr) {            
            if(cnt.count(i + 1) > 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
