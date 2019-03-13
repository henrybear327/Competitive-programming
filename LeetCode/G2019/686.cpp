class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        int n = A.length(), m = B.length();
        for (int i = 0; i < n; i++) {
            // match start at i
            int idx = i, ans = 1;
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (A[idx] != B[j]) {
                    ok = false;
                    break;
                } else {
                    idx++;
                    if (idx == n && j != m - 1)
                        idx = 0, ans++;
                }
            }

            if (ok)
                return ans;
        }
        return -1;
    }
};
