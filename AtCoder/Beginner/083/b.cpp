#include <bits/stdc++.h>

using namespace std;

bool check(int i, int a, int b)
{
    int res = 0;
    while(i) {
        res += i % 10;
        i /= 10;
    }

    return a <= res && res <= b;
}

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(check(i, a, b))
            ans += i;
    printf("%d\n", ans);

    return 0;
}
