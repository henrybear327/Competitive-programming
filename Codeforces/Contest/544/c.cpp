#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

/*
// 二分
bool check(int len, int inp[], int n)
{
    for (int i = 0; i + len <= n; i++) {
        if (inp[i + len - 1] - inp[i] <= 5)
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(mid, inp, n))
            l = mid;
        else
            r = mid;
    }

    printf("%d\n", l);

    return 0;
}
*/

// 爬行
int main()
{
    int n;
    scanf("%d", &n);
    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        while (inp[r] - inp[l] > 5)
            l++;
        ans = max(ans, r - l + 1);
    }

    printf("%d\n", ans);
}
