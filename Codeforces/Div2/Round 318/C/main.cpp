#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    int ans = -1;
    bool flag = true;
    for (int i = 0; i < cases && flag; i++) {
        int tmp;
        scanf("%d", &tmp);

        while (tmp % 2 == 0)
            tmp /= 2;
        while (tmp % 3 == 0)
            tmp /= 3;

        if (i == 0)
            ans = tmp;
        else
            flag = (tmp == ans);
    }

    printf("%s\n", flag ? "Yes" : "No");

    return 0;
}
