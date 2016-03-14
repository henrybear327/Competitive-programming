#include <bits/stdc++.h>

using namespace std;

#define err 1e-9

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int n;
        scanf("%d", &n);

        double maxx[10] = {0};
        double mid[10] = {0.0};

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double tmp;
                scanf("%lf", &tmp);

                if (i == j)
                    mid[i] = abs(tmp);
                else
                    maxx[i] += abs(tmp);
            }
            if (maxx[i] >= mid[i])
                flag = false;
        }

        printf("%c", flag ? 'Y' : 'N');
        if (cases == 0)
            printf("\n");
    }

    return 0;
}
