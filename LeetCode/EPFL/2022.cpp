class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret;

        if(m * n != original.size())
            return ret;
        
        for(int i = 0; i < original.size(); i++) {
            if(i % n == 0) 
                ret.push_back(vector<int>{});
            
            ret[i / n].push_back(original[i]);
        }

        return ret;
    }
};
