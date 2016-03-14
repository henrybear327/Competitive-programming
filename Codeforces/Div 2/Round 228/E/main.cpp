#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int a = 0, b = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int cnt;
        scanf("%d", &cnt);

        int inp[cnt];
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &inp[j]);
        }

        if (cnt % 2 == 1) {
            pq.push(inp[cnt / 2]);
        }
        // 0 1 2 3
        for (int j = 0; j < cnt / 2; j++)
            a += inp[j];
        for (int j = (cnt % 2 == 0 ? cnt / 2 : cnt / 2 + 1); j < cnt; j++)
            b += inp[j];
    }

    bool now_a = true;
    while (pq.size() > 0) {
        int top = pq.top();
        pq.pop();

        if (now_a == true) {
            a += top;
        } else {
            b += top;
        }

        now_a = !now_a;
    }

    printf("%d %d\n", a, b);

    return 0;
}
