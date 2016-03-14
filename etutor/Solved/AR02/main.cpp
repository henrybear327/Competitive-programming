#include <cstdio>

void solve(int coeff[], int ans[], int curr_power)
{
    int tmp[30] = {0};
    for (int i = 0; i <= curr_power * 2; i++)
        tmp[i] = ans[i];

    for (int i = 0; i < 30; i++)
        ans[i] = 0;

    for (int i = 0; i <= curr_power * 2; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i + j] += tmp[i] * coeff[j];
        }
    }

    return;
}

int main()
{
    int coeff[3], power;
    while (scanf("%d %d %d %d", &coeff[2], &coeff[1], &coeff[0], &power) == 4) {
        int ans[30] = {0};
        for (int i = 0; i < 3; i++)
            ans[i] = coeff[i];

        for (int i = 1; i < power; i++) {
            solve(coeff, ans, i);
        }

        for (int i = 2 * power; i >= 0; i--) {
            printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
        }
    }

    return 0;
}
