#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

inline long long int cal_m(long long int n, long long int x)
{
    long long a = (6 * x + n * n * n - n);
    long long b = (3 * n * n + 3 * n);
    if (a < 0 || b < 0)
        return -1;

    return a % b == 0 ? a / b : -1;
}

bool valid(long long int n, long long int x)
{
    return 6 * x >= -(n * n * n) + 3 * n * n + 2 * n;
}

int main()
{
    long long int x;
    scanf("%lld", &x);

    map<long long int, long long int> ans;
    for (long long int n = 1; valid(n, x); n++) {
        long long int m = cal_m(n, x);
        if (n > m)
            continue;
        if (m == -1)
            continue;
        if (ans.find(n) != ans.end())
            break;
        ans.insert(make_pair(n, m));
        ans.insert(make_pair(m, n));
    }

    printf("%d\n", (int)ans.size());
    for (map<long long int, long long int>::iterator it = ans.begin();
         it != ans.end(); it++)
        printf("%lld %lld\n", it->first, it->second);

    return 0;
}
