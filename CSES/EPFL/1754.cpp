#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int num1 = 2 * a - b;
    int num2 = 2 * b - a;

    if (num1 >= 0 && num2 >= 0 && num1 % 3 == 0 && num2 % 3 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        solve();
    }

    return 0;
}
