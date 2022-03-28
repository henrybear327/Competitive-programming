#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int x = a * 60 * 60 + b * 60;
    int y = c * 60 * 60 + d * 60 + 1;

    if (x < y)
        printf("Takahashi\n");
    else
        printf("Aoki\n");

    return 0;
}
