#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    bool ok = true;
    if (y > 2019)
        ok = false;
    else if (y == 2019 && m >= 5)
        ok = false;

    if (ok)
        printf("Heisei\n");
    else
        printf("TBD\n");

    return 0;
}
