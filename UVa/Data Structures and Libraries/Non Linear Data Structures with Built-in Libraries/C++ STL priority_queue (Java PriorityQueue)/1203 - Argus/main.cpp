#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef struct container {
    int idx, time, interval;
} Container;

struct cmp {
    bool operator()(Container const &p1, Container const &p2) {
        if (p1.time == p2.time)
            return p1.idx > p2.idx;
        return p1.time > p2.time;
    }
};

int main()
{
    Container Data[3010];
    char input[1000];
    memset(Data, 0, sizeof(Data));
    for (int i = 0; i < 3010; i++)
        Data[i].idx = i;
    priority_queue<Container, vector<Container>, cmp> pq;

    while (fgets(input, 1000, stdin) != NULL) {
        if (input[0] != '#') {
            char c[100];
            int idx, time;
            sscanf(input, "%s %d %d", c, &idx, &time);

            Data[idx].time = Data[idx].interval = time;

            pq.push(Data[idx]);

            continue;
        }

        fgets(input, 1000, stdin);
        int cnt;
        sscanf(input, "%d", &cnt);

        while (cnt--) {
            int idx;
            printf("%d\n", idx = pq.top().idx);
            pq.pop();
            Data[idx].time += Data[idx].interval;
            pq.push(Data[idx]);
        }

        // reset for next input
        memset(Data, 0, sizeof(Data));
        for (int i = 0; i < 3010; i++)
            Data[i].idx = i;

        while (!pq.empty())
            pq.pop();
    }

    return 0;
}
