class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int dist = 0;
        int ans = 0;
        bool first = true;
        for (auto i : seats) {
            if (i == 0)
                dist++;
            else {
                if (first) // ...0001
                    first = false, ans = dist;
                else
                    ans = max(ans, (dist + 1) / 2);
                dist = 0;
            }
        }
        ans = max(ans, dist);

        return ans;
    }
};