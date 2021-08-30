#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        char enemy[n + 3];
        scanf("%s", enemy);

        char my[n + 3];
        scanf("%s", my);

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (enemy[i] == '0' && my[i] == '1') {
                ans++;
                my[i] = '0';
            }

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && enemy[i - 1] == '1' && my[i] == '1') {
                ans++;
                enemy[i - 1] = '0';
            } else if (i + 1 < n && enemy[i + 1] == '1' && my[i] == '1') {
                ans++;
                enemy[i + 1] = '0';
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
