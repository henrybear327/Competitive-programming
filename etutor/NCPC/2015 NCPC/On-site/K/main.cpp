#include <cstdio>

bool check(int num, int cnt[])
{
    int num_cnt[10] = {0};

    if(num == 0) // Crucial!!
	num_cnt[0]++;

    while (num) {
        num_cnt[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++)
        if (num_cnt[i] > cnt[i])
            return false;

    return true;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int cnt1[10] = {0}, cnt2[10] = {0};
        for (int i = 0; i < 6; i++) {
            int tmp;
            scanf("%d", &tmp);

            cnt1[tmp]++;
        }

        for (int i = 0; i < 6; i++) {
            int tmp;
            scanf("%d", &tmp);

            cnt2[tmp]++;
        }

        int score1 = 0, score2 = 0;
        for (int i = 0; i <= 999999; i++) {
            bool res1 = check(i, cnt1), res2 = check(i, cnt2);
            if ((res1 && res2) || (!res1 && !res2))
                continue;
            else {
                if (res1)
                    score1++;
                else
                    score2++;
            }
        }
        printf("%d %d\n", score1, score2);
    }

    return 0;
}
