#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int n, m, p, x, y, z;

int main()
{
    int n, m, x, y, z, p;
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);

    x %= 4;
    y %= 2;
    z %= 4;

    int nn = n, mm = m;
    for (int i = 0; i < p; i++) {
        n = nn;
        m = mm;
        int a, b;
        scanf("%d %d", &a, &b);

        for (int j = 0; j < x; j++) {
	    /*
	    1. Draw the rotated rectangle, and mark the distance to the base n and m side
	    2. Examine the distances closly, observe the pattern
	    */
            int ta = b;
            int tb = n - a + 1;

            a = ta;
            b = tb;

            swap(n, m);
        }

        for (int j = 0; j < y; j++)
            b = m + 1 - b;

        for (int j = 0; j < z; j++) {
            int ta = m - b + 1;
            int tb = a;

            a = ta;
            b = tb;

            swap(n, m);
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}
