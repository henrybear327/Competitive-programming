#include <cstdio>
#include <cstdlib>
#include <cstring>

const char *country[6] = {"TW", "USW", "USE", "USC", "JA", "UK"};
const int convert[6] = {0, -14, -12, -13, 1, -8};

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int time;
        char first[10], second[10];

        scanf("%d %s %s", &time, first, second);

        int type1, type2;
        for (int i = 0; i < 6; i++) {
            if (strcmp(first, country[i]) == 0) {
                type1 = i;
                break;
            }
        }

        for (int i = 0; i < 6; i++) {
            if (strcmp(second, country[i]) == 0) {
                type2 = i;
                break;
            }
        }

        // convert to TW
        int hour = time / 100 - convert[type1];
        if (hour >= 24)
            hour -= 24;
        else if (hour < 0)
            hour += 24;

        hour = hour + convert[type2];
        if (hour >= 24)
            hour -= 24;
        else if (hour < 0)
            hour += 24;

        printf("%04d %s\n", hour * 100 + time % 100, country[type2]);
    }

    return 0;
}
