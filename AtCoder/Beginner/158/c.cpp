#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (double i = 1; i <= 1251; i++)
        if ((int)(i * 0.08) == a && b == (int)(i * 0.1)) {
            printf("%d\n", (int)i);
            return 0;
        }
    printf("-1\n");

    return 0;
}
