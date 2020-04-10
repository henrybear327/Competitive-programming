#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n % m == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
