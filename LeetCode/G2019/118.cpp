class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows >= 1)
            ans.push_back(vector<int> {1});
        if (numRows >= 2)
            ans.push_back(vector<int> {1, 1});
        if (numRows >= 3) {
            for (int i = 3; i <= numRows; i++) {
                vector<int> tmp;
                tmp.push_back(1);
                for (int j = 1; j < i - 1; j++) {
                    tmp.push_back(ans[i - 2][j - 1] + ans[i - 2][j]); // i - 1 is wrong...
                }
                tmp.push_back(1);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};
