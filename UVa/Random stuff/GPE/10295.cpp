#include <bits/stdc++.h>

using namespace std;

char inp[1000000];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    unordered_map<string, int> tb;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%s %d", inp, &val);

        tb[inp] = val;
    }

    for (int i = 0; i < m; i++) {
        int ans = 0;
        while (1) {
            scanf("%s", inp);
            if (inp[0] == '.')
                break;

            ans += tb[inp];
        }
        printf("%d\n", ans);
    }

    return 0;
}
