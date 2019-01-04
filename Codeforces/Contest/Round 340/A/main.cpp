#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = n / 5;
    n %= 5;
    cnt += (n > 0 ? 1 : 0);
    printf("%d\n", cnt);
    return 0;
}
