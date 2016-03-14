#include <cstdio>
#include <cmath>

int main()
{
    int hour, minute;
    while (scanf("%d:%d", &hour, &minute) == 2 && (hour != 0 || minute != 0)) {
        double ans = 0;

        double dhour = (360.0 / 12) * hour + ((360.0 / 12 / 60) * minute);
        double dminute = minute * (360.0 / 60);
        // printf("%f %f\n", dhour, dminute);

        if (dhour > dminute)
            ans = dhour - dminute;
        else
            ans = dminute - dhour;

        ans *= 1000;
        ans = round(ans) / 1000;

        printf("%.3f\n", ans > 180 ? 360.0 - ans : ans);
    }

    return 0;
}
