#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char inp[10];
    scanf("%s", inp);

    char c = inp[0];
    if (c == 'B' || c == 'b')
        printf("BattleShip\n");
    if (c == 'C' || c == 'c')
        printf("Cruiser\n");
    if (c == 'D' || c == 'd')
        printf("Destroyer\n");
    if (c == 'F' || c == 'f')
        printf("Frigate\n");
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
