#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int ans[n][n], cnt = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            ans[i][j] = cnt++;
    for (int i = 0; i < n; i++)
        for (int j = k; j < n; j++)
            ans[i][j] = cnt++;

    int cnt_ans = 0;
    for (int i = 0; i < n; i++)
        cnt_ans += ans[i][k];

    printf("%d\n", cnt_ans);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');

    return 0;
}
