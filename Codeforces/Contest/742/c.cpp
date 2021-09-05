#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

long long int solve()
{
    char inp[20];
    scanf("%s", inp);

    long long int a = 0, b = 0;
    int len = strlen(inp);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            a = a * 10 + (inp[i] - '0') % 10;
        } else {
            b = b * 10 + (inp[i] - '0') % 10;
        }
    }

    // printf("%lld %lld\n", a, b);
    return (a + 1) * (b + 1) - 2;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        printf("%lld\n", solve());
    }

    return 0;
}
