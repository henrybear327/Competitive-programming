#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n + 1], inp1[n + 1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &inp[i]);
        inp1[i] = inp[i];
    }

    int mn = INT_MAX;
    {
        int cnt = 0;
        for(int i = 1; i <= n - 1; i++) {
            if(inp[i] == i) {
                swap(inp[i], inp[i + 1]);
                cnt++;
            }
        }
        mn = min(mn, cnt);
    }

    {
        int cnt = 0;
        for(int i = n; i >= 2; i--) {
            if(inp1[i] == i) {
                swap(inp1[i], inp1[i - 1]);
                cnt++;
            }
        }
        mn = min(mn, cnt);
    }
    printf("%d\n", mn);
    return 0;
}
