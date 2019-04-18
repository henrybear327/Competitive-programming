#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);

    int b[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = c;
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            sum += num * b[j];
        }

        if (sum > 0)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
