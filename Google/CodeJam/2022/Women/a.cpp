#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int solve()
{
    int n;
    scanf("%d", &n);

    int cnt[4] = {0};
    // a b
    // c d
    for (int i = 0; i < 2 * n; i++) {
        char inp[n * 2 + 3];
        scanf("%s", inp);
        for (int j = 0; j < 2 * n; j++) {
            if (inp[j] == 'I') {
                if (j < n) {
                    if (i < n) {
                        cnt[0]++;
                    } else {
                        cnt[2]++;
                    }
                } else {
                    if (i < n) {
                        cnt[1]++;
                    } else {
                        cnt[3]++;
                    }
                }
            }
        }
    }

    return abs(cnt[0] - cnt[3]) + abs(cnt[1] - cnt[2]);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
