#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    long long int total = 0, inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &inp[i]);
        total += inp[i];
    }

    long long int avg = total / n;
    long long int r = total % n;

    long long int best[n];
    for (int i = 0; i < n - r; i++)
        best[i] = avg;
    for (int i = n - r; i < n; i++)
        best[i] = avg + 1;

    sort(inp, inp + n);
    long long int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(inp[i] - best[i]);
    printf("%lld\n", ans / 2);

    return 0;
}
