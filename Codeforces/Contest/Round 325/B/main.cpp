#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int a[n], b[n], c[n];
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int DP0[n], DP1[n];

    //go
    DP0[0] = 0;
    for(int i = 1; i < n; i++) {
        DP0[i] = DP0[i - 1] + a[i - 1];
    }
    /*
    for(int i = 0; i < n; i++)
        printf("%d ", DP0[i]);
    printf("\n");
    */

    DP1[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        DP1[i] = DP1[i + 1] + b[i];
    }
    /*
    for(int i = 0; i < n; i++)
        printf("%d ", DP1[i]);
    printf("\n");
    */

    int ans = INT_MAX, min_idx;
    for(int i = 0; i < n; i++) {
        if(DP0[i] + c[i] + DP1[i] < ans)
            min_idx = i;
        ans = min(ans, DP0[i] + c[i] + DP1[i]);
    }
    c[min_idx] = 1000000;
    /*
    for(int i = 0; i < n; i++)
        printf("%d%c", c[i], i == n - 1 ? '\n' : ' ');
    */
    //back

    DP0[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        DP0[i] = DP0[i + 1] + b[i];
    }
    /*
    for(int i = 0; i < n; i++)
        printf("%d ", DP0[i]);
    printf("\n");
    */

    DP1[0] = 0;
    for(int i = 1; i < n; i++) {
        DP1[i] = DP1[i - 1] + a[i - 1];
    }
    /*
    for(int i = 0; i < n; i++)
        printf("%d ", DP1[i]);
    printf("\n");
    */

    int ans1 = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(DP0[i] + c[i] + DP1[i] < ans1)
            min_idx= i;
        ans1 = min(ans1, DP0[i] + c[i] + DP1[i]);
    }

    // printf("%d %d %d\n", ans, ans1, ans + ans1);
    printf("%d\n", ans + ans1);

    return 0;
}
