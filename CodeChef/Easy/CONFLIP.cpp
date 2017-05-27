#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int j, m, q;
        scanf("%d %d %d", &j, &m, &q);

        int head, tail;
        if (m % 2 == 0)
            head = tail = m / 2;
        else {
            head = m / 2;
            tail = m / 2 + 1;
        }

        if (j == 2)
            swap(head, tail);

        printf("%d\n", q == 1 ? head : tail);
    }
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
