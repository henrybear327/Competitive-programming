class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<long long> candidates;
        for (int i = 1; i <= 9; i++)
            candidates.push_back(i);

        // 1 2 3 4 5 6 7 8 9
        // 1 2 3 4 5 6 7 8 9 12 23 34 45 56 67 78 89
        // 1 2 3 4 5 6 7 8 9 12 23 34 45 56 67 78 89
        int lb = 0, rb = candidates.size();
        while (1) {
            for (int i = lb; i < rb; i++) {
                if (candidates[i] % 10 + 1 < 10) {
                    candidates.push_back(candidates[i] * 10 + (candidates[i] % 10 + 1));
                }
            }

            if (rb != candidates.size()) {
                lb = rb;
                rb = candidates.size();
            } else {
                break;
            }
            // cout << lb << " " << rb << endl;
        }

        vector<int> ans;
        for (auto i : candidates) {
            if (i > INT_MAX)
                continue;
            if (low <= i && i <= high)
                ans.push_back(i);
        }

        return ans;
    }
};
