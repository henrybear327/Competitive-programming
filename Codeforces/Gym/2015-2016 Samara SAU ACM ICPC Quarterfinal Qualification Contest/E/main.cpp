#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int number, cnt, parent;
} Data;

int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> inp[100010]; // cost, resource
    inp[0].first = 0;
    inp[0].second = 1;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        inp[i].first = a;
        inp[i].second = b;
    }

    sort(inp, inp + n);

    queue<Data> q;
    Data curr = {0, 0, -1};
    q.push(curr);

    int idx = 0, dist[100010];
    for (int i = 0; i < 100010; i++)
        dist[i] = INT_MAX;

    bool ok = false;
    while (q.empty() == false) {
        curr = q.front();
        q.pop();
        if (curr.number == n) {
            ok = true;
            printf("%d\n", curr.cnt);

            int hey = curr.number;
        }

        if (dist[curr.number] < curr.cnt)
            continue;

        dist[curr.number] = min(dist[curr.number], curr.cnt);
        for (int i = idx; i <= n; i++) {
            if (inp[i].first <=
                inp[curr.number].second) { // inp[i] cost <= curr resource
                Data tmp = {i, curr.cnt + 1, curr.number}; // next num, cnt, parent

                q.push(tmp);
                idx++;
            } else {
                break;
            }
        }
    }

    if (ok == false) {
        printf("No such luck\n");
    }

    return 0;
}
