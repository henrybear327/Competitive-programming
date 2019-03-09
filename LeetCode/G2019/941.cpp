class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int n = A.size();
        if (n == 0)
            return false;

        int mx = A[0], idx = 0;
        for (int i = 1; i < n; i++) {
            if (mx < A[i])
                idx = i, mx = A[i];
        }

        int cnt = 0;
        for (auto &i : A)
            if (i == mx)
                cnt++;
        if (cnt > 1 || idx == 0 || idx == n - 1)
            return false;

        for (int i = idx; i >= 1; i--) {
            if (A[i - 1] >= A[i])
                return false;
        }
        for (int i = idx; i < n - 1; i++) {
            if (A[i] <= A[i + 1])
                return false;
        }

        return true;
    }
};
