#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// observation
// can only *2 or /3
// if a number consists of some 2, the next one that is mul of 2 will only have
// more if a number consists of some 3, the next one that is mul of 3 will only
// have less

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    if (k == n) {
        printf("%d\n", inp[n - 1]);
        return 0;
    }

    if (k == 0) {
        printf("%d\n", inp[0] == 1 ? -1 : 1);
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (inp[i] != inp[i - 1]) {
            // i
            if (i == k) {
                printf("%d\n", inp[i - 1]);
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}
