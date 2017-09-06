#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if (inp[i] == i + 1) {
            swap(inp[i], inp[i + 1]);
            cnt++;
        }
    if (inp[n - 1] == n)
        cnt++;

    printf("%d\n", cnt);
    return 0;
}
