#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    scanf("%s", inp);

    int y = 0, ic = 0;
    for (int i = 0; i < n; i++)
        if (inp[i] == 'Y')
            y++;
        else if (inp[i] == 'I')
            ic++;

    if (ic)
        printf("INDIAN\n");
    else if (y)
        printf("NOT INDIAN\n");
    else
        printf("NOT SURE\n");
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
