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
    char a[200100], b[200100];
    scanf("%s %s", a, b);

    int alen = strlen(a), blen = strlen(b);

    int prefix[blen + 1];
    prefix[0] = 0;
    for (int i = 1; i <= blen; i++)
        prefix[i] = prefix[i - 1] + (*(b + i - 1) == '1');

    int diff = blen - alen + 1;
    /*
    for (int i = 0; i <= blen; i++)
        printf("%d%c", prefix[i], i == blen ? '\n' : ' ');
    printf("%d\n", diff);
    */
    long long int ans = 0LL;
    for (int i = 0; i < alen; i++) {
        if (*(a + i) == '0')
            ans += prefix[diff + i] - prefix[i];
        else
            ans += diff - (prefix[diff + i] - prefix[i]);
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}
