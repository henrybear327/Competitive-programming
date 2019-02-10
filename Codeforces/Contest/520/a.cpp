#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n + 2];
    // 0 1 2 3 4 999 1000 1001
    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);
    inp[0] = 0;
    inp[n + 1] = 1001;

    int ans = 0;
    for (int i = 0; i < n + 2;) {
        int r = i + 1;
        while (r < n + 2 && inp[r] - inp[r - 1] == 1)
            r++;

        ans = max(ans, r - i);
        i = r;
    }

    printf("%d\n", max(0, ans - 2));

    return 0;
}
