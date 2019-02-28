#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1000010;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int cnt[N] = {0};
    ll total = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        cnt[num]++;
        total += cnt[num];
    }

    ll sum = 0;
    for (int i = 1; i < m; i++)
        sum += cnt[i];

    for (int i = 1; i + m - 1 < N; i++) {
        sum -= cnt[i - 1];
        sum += cnt[i + m - 1];

        int j = i + m - 1;
        while (sum >= k) {
            if (cnt[j] > 0) {
                cnt[j]--;
                sum--;
            } else {
                j--;
            }
        }
    }

    ll rem = 0;
    for (int i = 0; i < N; i++)
        rem += cnt[i];
    printf("%lld\n", total - rem);

    return 0;
}
