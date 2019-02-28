class Solution {
public:
    // n = strlen of J, m = strlen of S
    // O(n * m)
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        
        for(auto i : S)
            for(auto j : J)
                if(i == j)
                    ans++;
        
        return ans;
    }
};
