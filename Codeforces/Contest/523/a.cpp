#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);

    int ans = 0;
    /*while (s > 0) {
        s -= n;
        ans++;
    }*/
    ans = (s + n - 1) / n;

    printf("%d\n", ans);

    return 0;
}
