#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int cnt[100010] = {0};
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        cnt[num]++;
    }
    
    int mx = cnt[0] + cnt[1] + cnt[2];
    int sum = mx;
    for(int i = 1; i < 100010 - 2; i++) {
        sum += cnt[i + 2];
        sum -= cnt[i - 1];

        mx = max(mx, sum);
    }
    printf("%d\n", mx);

    return 0;
}
