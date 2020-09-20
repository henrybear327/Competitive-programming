#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // 1 2 3 4 5 6 7
    // 4 1 5 2 6 3 7

    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + n);

    int ans[n];
    ans[0] = inp[0];
    int idx = 1;
    for (int i = 0; i < n; i++) {
        ans[idx] = inp[i];
        idx += 2;

        if (idx >= n)
            idx = 0;
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
        if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
            cnt++;

    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}
