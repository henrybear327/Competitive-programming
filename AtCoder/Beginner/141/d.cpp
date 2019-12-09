#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        pq.push(num);
    }

    while (m > 0) {
        int cur = pq.top();
        pq.pop();

        m--;
        pq.push(cur / 2);
    }

    ll sum = 0;
    while (pq.size() > 0)
        sum += pq.top(), pq.pop();

    printf("%lld\n", sum);

    return 0;
}
