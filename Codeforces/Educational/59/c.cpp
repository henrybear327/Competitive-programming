#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int val[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    char inp[n + 3];
    scanf("%s", inp);

    ll ans = 0;
    for (int l = 0; l < n; l++) {
        int r = l + 1;
        priority_queue<int> pq;
        pq.push(val[l]);
        while (r < n) {
            if (inp[l] == inp[r]) {
                pq.push(val[r]);
                r++;
            } else
                break;
        }

        for (int i = 0; i < min(r - l, m); i++) {
            ans += pq.top();
            pq.pop();
        }

        l = r - 1;
    }
    printf("%lld\n", ans);

    return 0;
}
