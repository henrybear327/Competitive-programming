#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> inp[m];
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int num;
            scanf("%d", &num);
            num--;
            inp[i].push_back(num);
        }
    }

    int p[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &p[i]);

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum[m] = {0};
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                for (int k = 0; k < m; k++) {
                    for (auto l : inp[k])
                        if (l == j) {
                            sum[k]++;
                            break;
                        }
                }
            }
        }

        bool ok = true;
        for (int j = 0; j < m; j++) {
            if ((sum[j] % 2) != (p[j] % 2))
                ok = false;
        }
        if (ok)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
