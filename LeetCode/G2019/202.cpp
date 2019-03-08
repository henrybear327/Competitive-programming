class Solution
{
private:
    int next(int n)
    {
        int ret = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            ret += digit * digit;
        }
        return ret;
    }

public:
    bool isHappy(int n)
    {
        set<int> seen;
        while (n > 1) {
            if (seen.find(n) != seen.end())
                return false;
            seen.insert(n);
            n = next(n);
        }
        return true;
    }
};
