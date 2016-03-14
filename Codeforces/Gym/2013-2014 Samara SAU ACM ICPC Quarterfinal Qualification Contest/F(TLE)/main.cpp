#include <queue>
#include <cstdio>

using namespace std;

int main()
{
    int n, p, q;
    while(scanf("%d %d %d", &n, &p, &q) != EOF) {
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            pq.push(tmp);
        }

        int diff = p - q, now= q;

        int ans = 0;
        while(1) {
            ans++;

            int curr = pq.top();
            pq.pop();
            pq.push(curr - diff);

            if(pq.top() <= now)
                break;
            now += q;
        }

        printf("%d\n", ans);
    }
    return 0;
}
