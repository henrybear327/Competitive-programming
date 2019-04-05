#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int acc = 0;
    int diff[n];
    diff[0] = 0;
    int mn = 0, idx = 0;
    set<int> s;
    s.insert(0);
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);

        acc += num;
        diff[i] = acc;

        if (s.count(acc) > 0) {
            printf("-1\n");
            return 0;
        }
        s.insert(acc);
        if (acc < mn) {
            mn = acc;
            idx = i;
        }
    }

    int cnt[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        diff[i] += -mn + 1;
        if (diff[i] < 0 || diff[i] > n) {
            printf("-1\n");
            return 0;
        }
        cnt[diff[i]]++;
    }

    for (int i = 1; i <= n; i++)
        if (cnt[i] != 1) {
            printf("-1\n");
            return 0;
        }

    for (int i = 0; i < n; i++)
        printf("%d ", diff[i]);

    return 0;
}
