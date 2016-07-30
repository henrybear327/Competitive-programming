#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    int len = 1, ans = 1;

    int inp[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    for(int i = 1; i < n; i++) {
        if(inp[i] > inp[i - 1]) {
            len++;
        } else {
            len = 1;
        }

        ans = max(len, ans);
    }

    printf("%d\n", ans);

    return 0;
}
