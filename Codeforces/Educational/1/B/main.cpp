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
    char inp[10100];
    while (scanf("%s", inp + 1) == 1) {
        int query;
        scanf("%d", &query);
        for (int i = 0; i < query; i++) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);

            k %= (r - l + 1);

            char copy[10100];
            for (int i = l; i <= r; i++)
                copy[i] = inp[i];

            int idx = l + k;
            for (int i = l; i <= r - k; i++) {
                inp[idx++] = copy[i];
            }

            idx = l;
            for (int i = r - k + 1; i <= r; i++) {
                inp[idx++] = copy[i];
            }
        }

        printf("%s\n", inp + 1);
    }
    return 0;
}
