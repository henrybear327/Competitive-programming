#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int cnt[n] = {0};
    for (int i = 0; i < q; i++) {
        int num;
        scanf("%d", &num);
        num--;
        cnt[num]++;
    }

    for (int i = 0; i < n; i++) {
        if (k - (q - cnt[i]) > 0)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
