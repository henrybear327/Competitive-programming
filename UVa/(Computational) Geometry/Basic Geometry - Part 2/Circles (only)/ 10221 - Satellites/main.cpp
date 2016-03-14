#include <bits/stdc++.h>

using namespace std;

#define PI atan(1) * 4

inline double radian(double a)
{
    return a / 180.0 * PI;
}

int main()
{
    int r;
    double a;
    char s[100];
    while(scanf("%d %lf %s", &r, &a, s) == 3) {
        if(strcmp(s, "min") == 0) {
            a /= 60.0;
        }
        while(a > 360.0) {
            a -= 360.0;
        }

        r += 6440;
        a = a > 180.0 ? 360.0 - a : a;

        double one = 2 * r * PI * a / 360.0;
        double two = sqrt(2 * r * r - 2 * r * r * cos(radian(a)));

        printf("%.6f %.6f\n", one, two);
    }

    return 0;
}