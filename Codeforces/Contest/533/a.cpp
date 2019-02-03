#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int bestT = 0, ans = INT_MAX;
    for (int t = 1; t <= 100; t++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int diff = abs(inp[j] - t);
            if (diff > 1)
                cnt += diff - 1;
        }

        if (cnt < ans) {
            ans = cnt;
            bestT = t;
        }
    }

    printf("%d %d\n", bestT, ans);

    return 0;
}
