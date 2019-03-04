class Solution
{
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        // ask for A and B's respective lengths and range: same length and len range
        // <= 100 ask for if A and B must have one-to-one relationship: no

        int sz = A.size();
        vector<int> ans(sz);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++)
                if (A[i] == B[j]) {
                    ans[i] = j;
                    break;
                }
        }

        return ans;
    }
};
