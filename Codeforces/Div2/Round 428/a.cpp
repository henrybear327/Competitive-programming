#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int sum = 0;
    int ok = -1;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        sum += num;

        k -= min(8, sum);
        sum -= min(8, sum);

        if (k <= 0) {
            ok = i + 1;
            break;
        }
    }

    printf("%d\n", ok);

    return 0;
}
