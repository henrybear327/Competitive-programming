class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
            return false;

        int idx = -1;
        int cnt[26] = {0};
        for (int i = 0; i < A.length(); i++) {
            cnt[A[i] - 'a']++;

            if (A[i] != B[i]) {
                if (idx == -1)
                    idx = i;
                else {
                    if (idx == INT_MAX) // third diff
                        return false;
                    if (A[idx] != B[i] || A[i] != B[idx]) // swap won't work
                        return false;

                    idx = INT_MAX; // after one swap
                }
            }
        }

        if (idx == INT_MAX)
            return true;
        else {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 1)
                    return true;
            }
            return false;
        }
    }
};
