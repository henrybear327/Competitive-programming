#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = n / 2;
    printf("%lld\n", n % 2 == 0 ? (1LL << cnt) : 0);

    return 0;
}
