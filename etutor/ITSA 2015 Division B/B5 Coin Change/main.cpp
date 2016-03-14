#include <cstdio>

const int coin_avail[5] = {1, 5, 10, 20, 50};

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int money;
        scanf("%d", &money);

        long long int DP[15100] = {0};
        DP[0] = 1; // base case

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j + coin_avail[i] <= money; j++) {
                DP[j + coin_avail[i]] += DP[j];
            }
        }

        printf("%lld\n", DP[money]);
    }

    return 0;
}
