#include <bits/stdc++.h>

using namespace std;

// stack size issue on the judge machine
// 4 * 10^6 bytes = 4 * 10^3 KB = 4 MB
char inp[1000000 + 3];
int main()
{
    int n;
    scanf("%d", &n);

    scanf("%s", inp);

    int len = strlen(inp);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int cnt = 0;
        for (int j = i; j < len; j++) {
            if (inp[i] == inp[j]) {
                cnt++;
            } else {
                break;
            }
        }

        ans = max(ans, cnt);
        i = i + (cnt - 1);
    }

    printf("%d\n", ans);

    return 0;
}
