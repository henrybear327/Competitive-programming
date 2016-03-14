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
    long long int n;
    scanf("%lld", &n);

    printf("%lld\n", n * n - 4 * n + 4);
    return 0;
}
