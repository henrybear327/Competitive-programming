#include <bits/stdc++.h>

using namespace std;

int main()
{
    // the calculation might go over the range of int32
    long long int n;
    scanf("%lld", &n);

    printf("%lld", n);
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        printf(" %lld", n);
    }

    return 0;
}
