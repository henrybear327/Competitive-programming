#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y, b, r;
    scanf("%d %d %d", &y, &b, &r);

    int ans = 0;
    for (int i = 0; i <= y; i++)
        for (int j = 0; j <= b; j++)
            for (int k = 0; k <= r; k++) {
                if (j - i == 1 && k - j == 1) {
                    ans = max(ans, i + j + k);
                }
            }

    printf("%d\n", ans);

    return 0;
}
