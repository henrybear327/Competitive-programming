#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000010];
    fgets(a, 1000010, stdin);
    int n;
    sscanf(a, "%d", &n);
    int flag_1 = 0, flag_2 = 0, flag_3 = 2;
    char b[100010];
    while (n--) {
        flag_1 = 0;
        scanf("%s", a);
        int len = strlen(a);
        // printf("%d\n",len);
        for (int i = 0; i < len; i++) {
            if (a[i] == '1' && i == 0)
                continue;
            else if (a[i] == '0' && i == 0) {
                // printf("0");
                flag_3 = 1;
                break;
            } else if ((a[i] != '0' && flag_3 == 2) || (a[i] == '1' && i != 0)) {
                strcpy(b, a);
                flag_3 = 0;
                flag_1 = 0;
                break;
            } else if (a[i] == '0')
                flag_1++;
        }
        flag_2 += flag_1;
    }
    // printf("%d\n",flag_2);
    if (flag_3 == 0) {
        printf("%s", b);
        for (int i = 0; i < flag_2; i++)
            printf("0");
    }
    if (flag_3 == 1)
        printf("0");
    if (flag_3 == 2) {
        printf("1");
        for (int i = 0; i < flag_2; i++)
            printf("0");
    }
    printf("\n");
    return 0;
}
