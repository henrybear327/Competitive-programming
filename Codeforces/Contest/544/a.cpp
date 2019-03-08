#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int h1, h2, m1, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);

    int c1 = h1 * 60 + m1;
    int c2 = h2 * 60 + m2;
    int diff = c2 - c1;

    diff /= 2;
    diff += c1;
    int h = diff / 60;
    int m = diff % 60;
    printf("%02d:%02d\n", h, m);

    return 0;
}
