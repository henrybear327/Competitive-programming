class Solution
{
private:
    int gcd(int a, int b)
    {
        return a == 0 ? b : gcd(b % a, a); // b % a < a -> b % a if eventually = 0
        // -> can be caught
    }

public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        int cnt[10000] = {0};
        for (auto i : deck)
            cnt[i]++;

        int g = 0;
        for (int i = 0; i < 10000; i++)
            if (cnt[i] > 0)
                g = gcd(cnt[i], g);

        if (g >= 2)
            return true;
        return false;
    }
};
