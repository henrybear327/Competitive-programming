class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int ans = 0;
        int acc = 0;
        for (const auto &i : s) {
            if (i == 'L')
                acc++;
            else
                acc--;

            if (acc == 0)
                ans++;
        }

        return ans;
    }
};
