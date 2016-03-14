#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inpa[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inpa[i]);
    sort(inpa, inpa + n);

    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);

        printf("%d%c", (int)(upper_bound(inpa, inpa + n, tmp) - inpa),
               i == m - 1 ? '\n' : ' ');
    }

    return 0;
}
