#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char inp[m + 10];
    int ans = 0;
    bool ok = true;

    int diff[1010] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", inp);

        int g = -1, s = -1;
        for (int j = m - 1; j >= 0; j--) {
            if (inp[j] == 'S') {
                s = j;
            }

            if (inp[j] == 'G') {
                g = j;
            }
        }

        if (g > s)
            ok = false;
        else
            diff[s - g]++;
    }

    sort(diff, diff + n);

    for (int i = 1000; i >= 1; i--) {
        if (diff[i] != 0) {
            ans++;
        }
    }

    printf("%d\n", ans == 0 || ok == false ? -1 : ans);

    return 0;
}
