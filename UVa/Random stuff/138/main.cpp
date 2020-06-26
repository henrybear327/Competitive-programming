#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main()
{
    double y = 3;
    for (int i = 0; i < 10; i++) {
        while (1) {
            double x = sqrt((y * y + y) / 2);
            // printf("%f %f\n", x, y);

            if (fabs(floor(x) - x) < EPS) {
                printf("%10d%10d\n", int(x), int(y));
                y++;
                break;
            }
            y++;
        }
    }

    return 0;
}
