#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve(int x, int y)
{
    int xx, yy;
    scanf("%d %d", &xx, &yy);

    if (xx == x || yy == y)
        printf("divisa\n");
    else {
        if (xx < x && yy < y)
            printf("SO\n");
        else if (xx < x && yy > y)
            printf("NO\n");
        else if (xx > x && yy > y)
            printf("NE\n");
        else
            printf("SE\n");
    }
}

int main()
{
    int ncase;
    while (scanf("%d", &ncase) != EOF) {
        int x, y;
        scanf("%d %d", &x, &y);

        while (ncase--)
            solve(x, y);
    }

    return 0;
}
