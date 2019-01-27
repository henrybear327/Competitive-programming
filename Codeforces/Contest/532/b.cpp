#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int kind = 0;
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        num--;

        if (cnt[num] == 0)
            kind++;
        cnt[num]++;

        printf("%d", kind == n);

        if (kind == n) {
            for (int j = 0; j < n; j++) {
                cnt[j]--;
                if (cnt[j] == 0)
                    kind--;
            }
        }
    }

    return 0;
}
