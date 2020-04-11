#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void small1(int n)
{
    int base = 0;
    int row = 1;
    while (n > 0) {
        int rowSum = (1 << base);
        // printf("n = %d, %d\n", n, rowSum);

        if (n - rowSum >= 0) {
            if (row % 2 == 1) {
                for (int i = 1; i <= row; i++)
                    printf("%d %d\n", row, i);
            } else {
                for (int i = row; i >= 1; i--)
                    printf("%d %d\n", row, i);
            }

            base++;
            n -= rowSum;
        } else {
            bool left = (row % 2 == 1 ? true : false);
            for (int i = 1; i <= n; i++) {
                int idx;
                if (left)
                    idx = 1;
                else
                    idx = base + i;

                printf("%d %d\n", row, idx);
                row++;
            }

            break;
        }
        row++;
    }
}

void small2(int n)
{
    int base = 1;
    while ((base + 2) * (base + 1) / 2 < n - 1) {
        base++;
    }

    printf("1 1\n");
    n--;
    int cnt = 1;
    for (int i = 2; i <= base + 1; i++) {
        printf("%d %d\n", i, 2);

        n -= cnt;
        cnt++;
    }

    base = base + 1;
    printf("%d %d\n", base, 1);
    n--;

    base++;
    while (n > 0) {
        printf("%d %d\n", base, 1);
        base++;
        n--;
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    if (n <= 501)
        small1(n);
    else
        small2(n);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d:\n", i);
        solve();
    }

    return 0;
}
