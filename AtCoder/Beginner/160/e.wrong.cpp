#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int x, y, a, b, c;
    scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);

    priority_queue<ii> pq;
    priority_queue<int> pq2;
    for (int i = 0; i < a; i++) {
        int num;
        scanf("%d", &num);
        pq.push(ii{num, 0});
    }
    for (int i = 0; i < b; i++) {
        int num;
        scanf("%d", &num);
        pq.push(ii{num, 1});
    }
    for (int i = 0; i < c; i++) {
        int num;
        scanf("%d", &num);
        pq2.push(num);
    }

    ll ans = 0;
    while (x > 0 || y > 0) {
        int cand = -1;
        ii nxt;
        if (pq2.size() > 0)
            cand = pq2.top(), pq2.pop();

        while (pq.size() > 0) {
            nxt = pq.top();
            pq.pop();
            if (nxt.second == 0 && x == 0)
                continue;
            if (nxt.second == 1 && y == 0)
                continue;

            break;
        }

        if (nxt.second == 0)
            x--;
        else
            y--;

        if (cand > nxt.first) {
            ans += cand;

            pq.push(nxt);
        } else {
            ans += nxt.first;

            if (cand != -1)
                pq2.push(cand);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
