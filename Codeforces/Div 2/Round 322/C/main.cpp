#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef struct data {
    int first, second;
} Data;

int cmp(const void *a, const void *b)
{
    if (((Data *)a)->first == ((Data *)b)->first)
        return ((Data *)b)->second - ((Data *)a)->second;
    return ((Data *)a)->first - ((Data *)b)->first;
}

int main()
{
    int tot, k;
    scanf("%d %d", &tot, &k);

    Data inp[tot];
    for (int i = 0; i < tot; i++) {
        int tmp;
        scanf("%d", &tmp);
        inp[i].first = (100 - tmp) % 10;
        inp[i].second = tmp;
    }

    qsort(inp, tot, sizeof(Data), cmp);

    for (int i = 0; i < tot; i++) {
        if (k >= inp[i].first) {
            k -= inp[i].first;
            inp[i].second += inp[i].first;
            inp[i].first = 100 - inp[i].second;
        } else {
            int ans = 0;
            for (int i = 0; i < tot; i++) {
                ans += inp[i].second / 10;
            }

            printf("%d\n", ans);

            return 0;
        }
    }

    qsort(inp, tot, sizeof(Data), cmp);
    for (int i = 0; i < tot; i++) {
        if (k - inp[i].first >= 0) {
            k -= inp[i].first;
            inp[i].second += inp[i].first;
            inp[i].first = 100 - inp[i].second;
        } else {
            inp[i].second += k;
            inp[i].first = 100 - inp[i].second;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < tot; i++) {
        ans += inp[i].second / 10;
    }

    printf("%d\n", ans);

    return 0;
}
