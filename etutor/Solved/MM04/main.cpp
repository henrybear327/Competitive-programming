#include <cstdio>

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        long long int num;
        scanf("%lld", &num);

        long long int perfect_num[7] = {6,        28,           496,           8128,
                                        33550336, 8589869056LL, 137438691328LL
                                       };

        bool flag = true;
        for (int i = 0; i < 7; i++) {
            if (num == perfect_num[i]) {
                printf("perfect\n");
                flag = false;
                break;
            }
        }

        if (flag)
            printf("nonperfect\n");
    }

    return 0;
}
