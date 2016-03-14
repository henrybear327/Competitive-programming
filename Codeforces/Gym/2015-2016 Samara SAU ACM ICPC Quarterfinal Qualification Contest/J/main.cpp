#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + n);

    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (i >= inp[i]) {
            flag = true;
            ans = i;
        }
    }

    printf("%d\n", flag ? ans + 1 : 0);

    return 0;
}
