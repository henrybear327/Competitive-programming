class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start,
                                int destination)
    {
        if (start == destination)
            return 0;

        int ans = INT_MAX, n = distance.size();
        int sum = 0;
        for (int i = start; i != destination; i = (i + 1) % n)
            sum += distance[i];
        ans = min(ans, sum);

        sum = 0;
        for (int i = start; i != destination; i = (i - 1 + n) % n)
            sum += distance[(i - 1 + n) % n];
        ans = min(ans, sum);

        return ans;
    }

    // solution 2: total - one leg = another leg
};
