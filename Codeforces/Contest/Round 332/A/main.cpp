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
    int d1, d2, d3;
    scanf("%d %d %d", &d1, &d2, &d3);

    printf("%d\n", min(min(d1 + d2 + d3, (d1 + d2) * 2),
                       min((d1 + d3) * 2, (d2 + d3) * 2)));

    return 0;
}
