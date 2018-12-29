#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int c = 0;
    while (n--) {
        if (c == k)
            c = 0;
        if (c < k)
            printf("%c", c + 'a');
        c++;
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}
