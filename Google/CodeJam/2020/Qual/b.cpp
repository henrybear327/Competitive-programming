#include <bits/stdc++.h>

using namespace std;

void solve()
{
    char inp[111];
    scanf("%s", inp);

    int cnt = 0, n = strlen(inp);
    for (int i = 0; i < n; i++) {
        int num = inp[i] - '0';

        while (cnt < num) {
            printf("(");
            cnt++;
        }

        while (cnt > num) {
            printf(")");
            cnt--;
        }
        printf("%d", num);
    }

    while (cnt > 0)
        printf(")"), cnt--;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }

    return 0;
}
