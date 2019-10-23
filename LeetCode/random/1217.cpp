class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int n = chips.size();
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                int dist = abs(chips[i] - chips[j]);
                sum += dist % 2;
            }
            mn = min(mn, sum);
        }

        return mn;
    }
};
