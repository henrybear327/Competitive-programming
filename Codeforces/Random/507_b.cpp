#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &r, &x1, &y1, &x2, &y2);

    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    int ans = (int)ceil(distance / (2 * r));
    printf("%d\n", ans);

    return 0;
}
