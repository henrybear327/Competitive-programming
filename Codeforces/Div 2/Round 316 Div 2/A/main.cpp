#include <bits/stdc++.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main()
{
    int candidate, cities;
    scanf("%d %d", &candidate, &cities);

    int win[candidate];
    memset(win, 0, sizeof(win));
    for (int i = 0; i < cities; i++) {
        int data[candidate];
        memset(data, 0, sizeof(data));

        int max = -1;
        for (int j = 0; j < candidate; j++) {
            scanf("%d", &data[j]);
            max = MAX(max, data[j]);
        }

        for (int j = 0; j < candidate; j++) {
            if (data[j] == max) {
                win[j]++;
                break;
            }
        }
    }

    int max = -1, winner = -1;
    for (int i = 0; i < candidate; i++) {
        if (win[i] > max) {
            max = win[i];
            winner = i;
        }
    }

    printf("%d\n", winner + 1);

    return 0;
}
