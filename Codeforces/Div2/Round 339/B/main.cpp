#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    char inp[100010];
    fgets(inp, 100010, stdin);

    int n;
    sscanf(inp, "%d", &n);

    bool is_zero = false, has_not_perfect = false;
    int cnt = 0;
    char num[100010];
    for (int i = 0; i < n; i++) {
        scanf("%s", inp);

        if (inp[0] == '0')
            is_zero = true;

        int array[10] = {0};
        int len = strlen(inp);
        for (int i = 0; i < len; i++) {
            array[inp[i] - '0']++;
        }

        bool flag = false;
        for (int j = 2; j < 10; j++) {
            if (array[1] > 1 || array[j] != 0) {
                flag = true;
                has_not_perfect = true;
                strcpy(num, inp);
                break;
            }
        }

        if (flag == false)
            cnt += array[0];
    }

    if (is_zero == true)
        printf("0\n");
    else if (has_not_perfect == true) {
        printf("%s", num);
        for (int i = 0; i < cnt; i++)
            printf("0");
    } else {
        printf("1");
        for (int i = 0; i < cnt; i++)
            printf("0");
    }

    return 0;
}
