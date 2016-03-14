#include <cstdio>

typedef long long int ll;

ll comb(int x)
{
    if (x < 0)
        return 0;
    else
        return 1LL * (x + 1) * (x + 2) / 2; // la + lb + lc = x, do the math!
}

int main()
{
    int a, b, c, l;
    scanf("%d %d %d %d", &a, &b, &c, &l);

    ll ans = 0;
    for (int i = 0; i <= l; i++) { // test the length from 0 to l
        int sum = a + b + c + i;

        int waya = (sum - 1) / 2 - a + 1;
        int wayb = (sum - 1) / 2 - b + 1;
        int wayc = (sum - 1) / 2 - c + 1;

        if (waya < 0 || wayb < 0 || wayc < 0) // case: 10 1 1
            continue;

        // use test case 1 1 1 2 to really see the workflow
        ans += comb(i); // All possible ways of using the extra length of i
        // (regardless of the correctness of the triangle being
        // formed.)
        ans -= comb(i - waya); // la + waya + lb + lc = i --> do the math!
        ans -= comb(i - wayb);
        ans -= comb(i - wayc);
        ans += comb(i - waya - wayb);
        ans += comb(i - waya - wayc);
        ans += comb(i - wayb - wayc);
        ans -= comb(i - waya - wayb - wayc);
    }

    printf("%lld\n", ans);

    return 0;
}
