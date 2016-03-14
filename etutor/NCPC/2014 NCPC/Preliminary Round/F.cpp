#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int rep, rank;
} Node;

int station, road, device;
Node data[100010];

void init_set()
{
    for (int i = 0; i < station; i++) {
        data[i].rep = i;
        data[i].rank = 0;
    }
}

int find_set(int a)
{
    return data[a].rep == a ? a : (data[a].rep = find_set(data[a].rep));
}

bool is_same_set(int a, int b)
{
    return find_set(a) == find_set(b);
}

void union_set(int a, int b)
{
    if (!is_same_set(a, b)) {
        int x = find_set(a), y = find_set(b);
        if (data[x].rank > data[y].rank)
            data[y].rep = x;
        else
            data[x].rep = y;

        if (data[x].rank == data[y].rank) {
            data[y].rank++;
        }
    }
}

typedef struct data {
    int a, b, w;
} Data;

int cmp(const void *a, const void *b)
{
    return ((Data *)a)->w - ((Data *)b)->w;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d", &station, &road, &device);

        Data inp[road];
        for (int i = 0; i < road; i++) {
            scanf("%d %d %d", &inp[i].a, &inp[i].b, &inp[i].w);
        }

        qsort(inp, road, sizeof(Data), cmp);

        init_set();
        int rep_max_w[station];
        memset(rep_max_w, 0, sizeof(rep_max_w));
        priority_queue< pair<int, int> > pq;
        for (int i = 0; i < road; i++) {
            if (is_same_set(inp[i].a, inp[i].b) == false) {
                union_set(inp[i].a, inp[i].b);
                rep_max_w[find_set(inp[i].a)] =
                    max(rep_max_w[find_set(inp[i].a)], inp[i].w);
                pq.push(make_pair(inp[i].w, find_set(inp[i].a)));
            }
        }

        bool used[station];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < station; i++) {
            find_set(i);
            used[data[i].rep] = true;
        }

        int cnt = 0;
        for (int i = 0; i < station; i++) {
            if (used[i] == true) {
                cnt++;
            }
        }

        if (cnt > device) {
            printf("-1\n");
            continue;
        } else if (device >= station) {
            printf("0\n");
            continue;
        }

        device -= cnt;
        int ans = 0;
        for (int i = 0; i < station; i++) {
            ans = max(ans, rep_max_w[i]);
        }
        while (!pq.empty() && device) {
            if (rep_max_w[pq.top().second] == pq.top().first) {
                rep_max_w[pq.top().second] = -1;
                pq.pop();
            }

            ans = pq.top().first;
            pq.pop();
            device--;
        }

        printf("%d\n", ans);
    }

    return 0;
}
