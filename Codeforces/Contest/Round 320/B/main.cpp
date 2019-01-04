#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef struct record {
    int val, a, b;
} Record;

struct cmp {
    bool operator()(Record const &p1, Record const &p2) {
        return p1.val < p2.val;
    }
};

int main()
{
    int teams;
    scanf("%d", &teams);

    priority_queue<Record, vector<Record>, cmp> pq;
    for (int i = 2; i <= teams * 2; i++) {
        for (int j = 1; j < i; j++) {
            Record tmp;
            int value;
            scanf("%d", &value);
            tmp.val = value;
            tmp.a = i;
            tmp.b = j;
            pq.push(tmp);
        }
    }

    int cnt = 0;
    int ans[teams * 2 + 10];
    memset(ans, -1, sizeof(ans));

    while (cnt != teams) {
        Record tmp = pq.top();
        pq.pop();

        // getchar();
        // printf("%d %d %d\n", tmp.a, tmp.b, tmp.val);

        if (ans[tmp.a] == -1 && ans[tmp.b] == -1) {
            ans[tmp.a] = tmp.b;
            ans[tmp.b] = tmp.a;
            cnt++;
        }
    }

    for (int i = 1; i <= 2 * teams; i++) {
        if (i != 2 * teams)
            printf("%d ", ans[i]);
        else
            printf("%d\n", ans[i]);
    }

    return 0;
}
