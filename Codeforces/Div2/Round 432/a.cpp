#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);

    if (t < k || t > n)
        printf("%d\n", t < k ? t : k - (t - n));
    else
        printf("%d\n", k);

    return 0;
}
