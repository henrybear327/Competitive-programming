#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (m < n - 1) {
        printf("Impossible\n");
        return 0;
    }

    vector<ii> g;
    int cnt = 0;
    for (int i = 1; cnt < m && i <= n; i++) {
        for (int j = i + 1; cnt < m && j <= n; j++) {
            if (gcd(i, j) == 1) {
                g.push_back(ii(i, j));
                cnt++;
            }
        }
    }

    if (cnt == m) {
        printf("Possible\n");
        for (auto i : g)
            printf("%d %d\n", i.first, i.second);
    } else
        printf("Impossible\n");

    return 0;
}
