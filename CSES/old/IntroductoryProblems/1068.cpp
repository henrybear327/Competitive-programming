#include <bits/stdc++.h>

using namespace std;

// 3n+1
int main()
{
    long long n; // long long ... oops
    scanf("%lld", &n);
    while (1) {
        printf("%lld ", n);

        if (n == 1)
            break;

        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }

    return 0;
}
