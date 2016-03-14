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
    int a, b;
    scanf("%d %d", &a, &b);

    int minn = min(a, b);
    int maxx = max(a, b);

    printf("%d ", minn);

    maxx -= minn;

    printf("%d\n", maxx / 2);

    return 0;
}
