#include <cstdio>

using namespace std;

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

long long dp[100][100] = {0};
long long cmb(int n, int m)
{
    if (n < m || m < 0)
        return 0;
    if (n == m || m == 0)
        return 1;
    if (dp[n][m])
        return dp[n][m];
    return dp[n][m] = cmb(n - 1, m) + cmb(n - 1, m - 1);
}

int main()
{
    long long m, n = 0;
    int k, t = 59;
    scanf("%lld %d", &m, &k);

    if (m == 0 || k == 1) {
        printf("1\n");
    } else {
        k--;
        while (m) {
            if (cmb(t, k) <= m) {
                m -= cmb(t, k);
                n |= (1LL << t);
                k--;
            }
            t--;
        }
        printf("%lld\n", n);
    }

    return 0;
}
