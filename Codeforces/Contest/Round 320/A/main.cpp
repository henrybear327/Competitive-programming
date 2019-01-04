#include <bits/stdc++.h>

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int inp;
    scanf("%d", &inp);

    int cnt = 0;
    while (inp) {
        if (inp & 1)
            cnt++;
        inp >>= 1;
    }

    printf("%d\n", cnt);

    /*
    long long int inp;
    scanf("%lld", &inp);

    long long int tmp = 1LL << 31;

    int ans = 0;
    while (inp) {
    if (inp - tmp >= 0) {
    ans++;
    inp -= tmp;
    }
    tmp >>= 1;
    }

    printf("%d\n", ans);
    */
    return 0;
}
