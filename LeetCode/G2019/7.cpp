class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        else if (x > 0) {
            int ans = 0;
            while (x > 0) {
                if (INT_MAX / 10 < ans)
                    return 0;

                ans = ans * 10;
                ans += x % 10;
                x /= 10;
            }
            return ans;
        } else {
            int ans = 0;
            while (x != 0) {
                if (INT_MIN / 10 > ans)
                    return 0;

                ans = ans * 10;
                ans += x % 10;
                x /= 10;
            }
            return ans;
        }
    }
};
