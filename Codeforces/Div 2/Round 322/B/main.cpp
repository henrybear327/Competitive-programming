#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);

    int data[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &data[i]);
    }

    int maxh = data[num - 1];
    data[num - 1] = 0;
    for (int i = num - 2; i >= 0; i--) {
        int tmp = data[i];
        data[i] = max(0, maxh + 1 - data[i]);
        maxh = max(tmp, maxh);
    }

    for (int i = 0; i < num; i++)
        printf("%d%c", data[i], i == num - 1 ? '\n' : ' ');

    /*
    int maxx[num], rmax = data[num - 1];
    maxx[num - 1] = data[num - 1];
    bool flag[num];
    memset(flag, false, sizeof(flag));
    for (int i = num - 2; i >= 0; i--) {
        if (rmax == data[i]) {
            flag[i] = true;
            maxx[i] = rmax + 1;
            continue;
        }
        maxx[i] = max(data[i], rmax);
        rmax = maxx[i];
    }

    for (int i = 0; i < num; i++) {
        int ans = maxx[i] - data[i];
        if (flag[i] == false && ans)
            ans++;
        printf("%d%c", ans, i == num - 1 ? '\n' : ' ');
    }
    */

    return 0;
}
