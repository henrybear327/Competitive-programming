#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    int ansA, ansB;
    for (int i = 0; i <= 1000; i++)
        for (int j = i + 1; j <= 1000; j++) {
            if (i + j != n)
                continue;

            if (gcd(i, j) != 1)
                continue;

            if (i + j >= sum) {
                sum = i + j;
                ansA = i;
                ansB = j;
            }
        }

    printf("%d %d\n", ansA, ansB);

    return 0;
}
