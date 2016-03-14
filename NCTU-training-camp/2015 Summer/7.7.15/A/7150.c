#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int p, a, b, c, d, n;

double price(int k)
{
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6) {
        double max = price(1), interval = 0;
        for (int i = 2; i <= n; i++) {
            max = MAX(max, price(i));
            interval = MAX(interval, max - price(i));
        }
        printf("%.15f\n", interval);
    }

    return 0;
}