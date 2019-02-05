#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int origN = n;
    int origM = m;

    int g = gcd(n, k);
    n /= g;
    k /= g;

    int g2 = gcd(m, k);
    m /= g2;
    k /= g2;

    if (k <= 2) { // case k = 2 is special lol
        if (k == 1) {
            if (n * 2 <= origN)
                n *= 2;
            else if (m * 2 <= origM)
                m *= 2;
            else {
                printf("NO\n");
                return 0;
            }
        }

        printf("YES\n");
        printf("%d %d\n", 0, 0);
        printf("%d %d\n", n, 0);
        printf("%d %d\n", 0, m);
    } else {
        printf("NO\n");
    }
    return 0;
}
