#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int cards[53];
        for (int i = 1; i <= 52; i++)
            cards[i] = i;

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);

            int tmp[53];
            for (int j = num; j <= 52; j++) {
                tmp[j - num + 1] = cards[j];
            }
            for (int j = 1; j < num; j++) {
                tmp[j + (52 - num + 1)] = cards[j];
            }
            memcpy(cards, tmp, sizeof(tmp));
        }
        printf("%d\n", cards[52]);
    }

    return 0;
}