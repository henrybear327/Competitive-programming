#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // observation: NE - SW direction, all diagnals must retain the same number
    // set observation: we can get all desired diagnal permutations without
    // affecting other diagnals

    int n, m;
    scanf("%d %d", &n, &m);
    multiset<int> orig[n + m], res[n + m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            orig[i + j].insert(num);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            res[i + j].insert(num);
        }

    /*
    for (int i = 0; i < n + m; i++) {
        for (auto j : res[i])
            printf("res %d %d\n", i, j);
        for (auto j : orig[i])
            printf("orig %d %d\n", i, j);
    }
    */

    for (int i = 0; i < n + m; i++)
        if (res[i] != orig[i]) {
            printf("NO\n");
            return 0;
        }

    printf("YES\n");

    return 0;
}
