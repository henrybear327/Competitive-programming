#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return b < a;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n, t;
        scanf("%d %d", &n, &t);

        int morning[n], evening[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &morning[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &evening[i]);

        sort(morning, morning + n);
        sort(evening, evening + n, cmp);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = morning[i] + evening[i];
            tmp = tmp > t ? tmp - t : 0;
            ans += tmp;
        }

        printf("%d\n", ans);
    }

    return 0;
}
