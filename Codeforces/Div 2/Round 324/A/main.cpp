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
    int n, t;
    scanf("%d %d", &n, &t);

    if (t == 10 && n == 1) {
        printf("-1\n");
        return 0;
    } else if (t == 10 && n >= 2) {
        for (int i = 1; i <= n; i++) {
            if (i == 1)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d", t);
    }
    printf("\n");

    return 0;
}
