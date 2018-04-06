#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);

    int cnt[m];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        cnt[num - 1]++;
    }

    printf("%d\n", *min_element(cnt, cnt + m));

    return 0;
}
