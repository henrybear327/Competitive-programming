#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    for (int i = 0; i < n; i++) {
        if (inp[i] == 'L')
            printf("L");
        else if (inp[i] == 'R')
            printf("R");
        else if (inp[i] == 'U')
            printf("D");
        else
            printf("U");
    }
    printf("\n");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
