#include <bits/stdc++.h>

using namespace std;

int get(int i, int j, int sum[]) { // [i, j]
    return sum[j] - sum[i - 1];
}

int main()
{
    // 0 0 0 0 1 1 1 1 1 
    int n;
    scanf("%d", &n);
    
    int inp[n + 1];
    for(int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);
    
    int sum[n + 1];
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + inp[i];
    
    int ans = 0;
    // for every position
    // get the best 00...11... number list
    for(int i = 1; i <= n; i++) {
        if(inp[i] == 0) {
            ans = max(ans, 1 + (i - 1 - get(1, i - 1, sum)) + get(i + 1, n, sum));
        } else {
            ans = max(ans, (i - 1 - get(1, i - 1, sum)) + (1 + get(i + 1, n, sum)));
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
