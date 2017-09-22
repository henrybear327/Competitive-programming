#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n * 2];
    for (int i = 0; i < n * 2; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + 2 * n);

    int ans = INT_MAX;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < n * 2; j++) {
            int tmp = 0;

            vector<int> slice;
            slice.reserve(n * 2 - 2);
            for (int k = 0; k < 2 * n; k++) {
                if (i == k || j == k)
                    continue;
                slice.push_back(inp[k]);
            }

            for (int k = 0; k < 2 * n - 2; k += 2)
                tmp += slice[k + 1] - slice[k];

            // printf("%d %d %d\n", i, j, tmp);
            ans = min(ans, tmp);
        }
    }

    printf("%d\n", ans);

    return 0;
}