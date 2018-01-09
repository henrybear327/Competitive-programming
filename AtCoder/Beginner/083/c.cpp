#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    int i;
    for(i = 0; i < 60; i++) {
        long long int tmp = a * (1LL << i);
        if(tmp > 0 && tmp <= b)
            continue;
        break;
    }
    printf("%d\n", i);

    return 0;
}
