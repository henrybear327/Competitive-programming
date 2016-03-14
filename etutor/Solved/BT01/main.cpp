#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int len, cnt;

int info[110];

int range_cost[110][110];

int calculate(int L, int R)
{
    if (R - L == 1)
        return 0;

    if (range_cost[L][R] != -1)
        return range_cost[L][R];

    int ans = INT_MAX;
    for (int i = L + 1; i < R; i++) {
        ans = min(ans, info[R] - info[L] + calculate(L, i) + calculate(i, R));
    }

    return range_cost[L][R] = ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d", &len);

        info[0] = 0;
        cnt = 1;

        int tmp;
        while (scanf("%d", &tmp) == 1 && tmp != 0)
            info[cnt++] = tmp;
        info[cnt++] = len;

        memset(range_cost, -1, sizeof(range_cost));
        printf("%d\n", calculate(0, cnt - 1));
    }

    return 0;
}
