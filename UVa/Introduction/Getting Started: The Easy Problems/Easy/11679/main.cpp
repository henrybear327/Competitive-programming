#include <cstdio>
/*
當A銀行發給B銀行債券價值V時，A銀行會增加V元的資金，B銀行會少V元的資金。
現在題目要大家各自償還自己的債務，所以，題目輸入的金額是銀行現有的資金(假設是a, b)，償還之後，A銀行會有a-v的資金，B則拿回了自己的資金，所以b+v。其餘類推。
*/

int main()
{
    int banks, debentures;
    while (scanf("%d %d", &banks, &debentures) == 2 &&
           (banks != 0 && debentures != 0)) {
        int monetary[21] = {0};

        for (int i = 1; i <= banks; i++)
            scanf("%d", &monetary[i]);

        for (int i = 0; i < debentures; i++) {
            int d, c, v;
            scanf("%d %d %d", &d, &c, &v);

            monetary[d] -= v;
            monetary[c] += v;
        }

        bool flag = false;
        for (int i = 1; i <= banks; i++)
            if (monetary[i] < 0)
                flag = true;

        if (flag)
            printf("N\n");
        else
            printf("S\n");
    }

    return 0;
}
