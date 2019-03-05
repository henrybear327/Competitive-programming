class Solution
{
public:
    int rotatedDigits(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int tmp = i;
            bool ok = false;
            while (tmp > 0) {
                int d = tmp % 10;
                if (d == 3 || d == 4 || d == 7) {
                    ok = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    ok = true;
                }
                tmp /= 10;
            }
            ans += ok;
        }
        return ans;
    }
};
