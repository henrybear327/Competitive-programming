#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int mod[k] = {0};
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        mod[num % k]++;
    }

    int ans = 0;
    for (int i = 1; i < k; i++) {
        int mn = min(mod[i], mod[k - i]);
        mod[i] -= mn;

        if (i == k - i)
            ans += mn / 2 * 2;
        else
            ans += 2 * mn, mod[k - i] -= mn;
    }

    ans += mod[0] / 2 * 2;

    printf("%d\n", ans);

    return 0;
}
