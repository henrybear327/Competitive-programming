#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int cnt[111] = {0};
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        cnt[tmp]++;
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        if (i != k && cnt[i] == 0)
            ans++;
        else if (i == k && cnt[i] == 1)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
