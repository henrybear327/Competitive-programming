class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = to_string(1);
        for (int i = 1; i < n; i++) {
            string tmp;
            for (int j = 0; j < ans.size();) {
                int k = j;
                while (k < ans.size() && ans[j] == ans[k])
                    k++;
                // [j, k)
                tmp += to_string(k - j) + ans[j];
                j = k;
            }
            ans = tmp;
        }
        return ans;
    }
};
