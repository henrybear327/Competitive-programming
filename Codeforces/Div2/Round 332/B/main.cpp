#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    /*
    a 2 3 5 4 7
    f 3 5 6 11 2 22 99

    Let bi = f(ai)

    So, if b1= f(a1) = 5
    Then, f(i) = 5, i = 2, which means a1 = 2
    */

    int f[100100] = {0}, b[100100];

    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (f[tmp] == 0) {
            f[tmp] = i;
        } else {
            f[tmp] = -1;
        }
    }
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int a[100100];
    bool impossible = false, ambiguous = false;
    for (int i = 0; i < m; i++) {
        if (f[b[i]] == 0) {
            impossible = true;
        } else if (f[b[i]] == -1) {
            ambiguous = true;
        } else {
            a[i] = f[b[i]];
        }
    }

    if (impossible)
        printf("Impossible\n");
    else if (ambiguous)
        printf("Ambiguity\n");
    else {
        printf("Possible\n");
        for (int i = 0; i < m; i++)
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
