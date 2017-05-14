#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int b, ls;
        scanf("%d %d", &b, &ls);

        double r1 = sqrt(b * b + ls * ls), r2 = sqrt(ls * ls - b * b);
        if (r1 - r2 > -1e-9)
            swap(r1, r2);
        printf("%.15f %.15f\n", r1, r2);
    }

    return 0;
}
