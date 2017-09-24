#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    int ans = 0;
    while (scanf("%s", inp) == 1) {
        int cnt = 0;
        int len = strlen(inp);
        for (int i = 0; i < len; i++) {
            if ('A' <= inp[i] && inp[i] <= 'Z')
                cnt++;
        }

        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}