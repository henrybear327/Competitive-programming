#include <bits/stdc++.h>

using namespace std;

int getCnt(int n)
{
    int cnt = 0;
    while (n > 0) {
        if ((n & 1) == 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int quotient = n / 2048;
        int remainder = n % 2048;

        int cnt = quotient + getCnt(remainder);
        printf("%d\n", cnt);
    }

    return 0;
}
