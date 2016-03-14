#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);

    char inp[n + 10];
    scanf("%s", inp);

    // solve px + qy = n
    bool cont = true;
    int a, b;
    for (int x = 0; cont && p * x <= n; x++) {
        for (int y = 0; p * x + q * y <= n; y++) {
            if (p * x + q * y == n) {
                cont = false;
                a = x;
                b = y;
            }
        }
    }
    if (cont) {
        printf("-1\n");
        return 0;
    }
    // printf("%d %d\n", a, b);

    int base = -1, newline[1000] = {0};
    for (int i = 1; i <= a; i++) {
        newline[base + p * i] = 1;
    }
    base += a * p;
    for (int i = 1; i <= b; i++)
        newline[base + q * i] = 1;

    printf("%d\n", a + b);
    for (int i = 0; i < n; i++) {
        printf("%c", inp[i]);
        if (newline[i])
            printf("\n");
    }

    return 0;
}
