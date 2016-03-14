#include <cstdio>
#include <cstring>

int calculation(int num)
{
    int ans = 0;
    while (num >= 10) {
        while (num) {
            ans += num % 10;
            num /= 10;
        }
        num = ans;
        ans = 0;
    }

    return num;
}

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    char name1[100], name2[100];
    while (fgets(name1, 100, stdin) != NULL && fgets(name2, 100, stdin) != NULL) {
        int len1 = strlen(name1), len2 = strlen(name2);

        int v1 = 0, v2 = 0;
        for (int i = 0; i < len1; i++) {
            if ('a' <= name1[i] && name1[i] <= 'z')
                v1 += name1[i] - 'a' + 1;
            else if ('A' <= name1[i] && name1[i] <= 'Z')
                v1 += name1[i] - 'A' + 1;
        }

        for (int i = 0; i < len2; i++) {
            if ('a' <= name2[i] && name2[i] <= 'z')
                v2 += name2[i] - 'a' + 1;
            else if ('A' <= name2[i] && name2[i] <= 'Z')
                v2 += name2[i] - 'A' + 1;
        }

        v1 = calculation(v1);
        v2 = calculation(v2);

        double ratio;
        if (v1 == 0 && v2 == 0)
            ratio = 0;
        else
            ratio = (double)MIN(v1, v2) / (double)MAX(v1, v2) * 100;

        printf("%.2f %%\n", ratio);
    }

    return 0;
}
