class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;

        for(int i = 0; i < numRows; i++) {
            vector<int> tmp;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    tmp.push_back(1);
                } else {
                    tmp.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
                }
            }

            ret.push_back(tmp);
        }

        return ret;
    }
};
