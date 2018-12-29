#include <bits/stdc++.h>

typedef unsigned long long int ull;
#ifdef _WIN32
#define lld "I64u"
#else
#define lld "llu"
#endif

using namespace std;

int main()
{
    unsigned long long int a, b;
    scanf("%llu %llu", &a, &b);

    unsigned long long int na = a, nb = b;

    int cnta = 0;
    while (na) {
        cnta++;
        na >>= 1;
    }

    int cntb = 0;
    while (nb) {
        cntb++;
        nb >>= 1;
    }
    // printf("%d %d\n", cnta, cntb);

    int ans = 0;
    for (ull i = cnta; i <= (ull)cntb; i++) {
        unsigned long long int ones = (1LL << i) - 1;
        // printf("i %llu %llu\n", i, ones);
        for (ull j = 0; j < (ull)i - 1; j++) {
            unsigned long long int mask = 1LL << j;
            unsigned long long int comp = ones ^ mask;
            if (a <= comp && comp <= b) {
                ans++;
                // printf("comp %llu\n", comp);
            }
            // printf("%llu %llu %d\n", mask, comp, ans);
        }
    }
    printf("%d\n", ans);

    return 0;
}
