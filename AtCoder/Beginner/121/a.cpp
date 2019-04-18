#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);

    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", h * w - a * w - b * h + a * b);

    return 0;
}
