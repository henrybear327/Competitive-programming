#include <cstdio>
#include <cstring>

char tmp[1000010], inp1[1000010], inp2[1000010];

void strip_zero(char *tmp, char *inp)
{
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == '0')
            continue;
        else {
            strcpy(inp, tmp + i);
            // printf("%s", inp);
            return;
        }
    }
}

int main()
{
    fgets(tmp, 1000010, stdin);
    strip_zero(tmp, inp1);
    fgets(tmp, 1000010, stdin);
    strip_zero(tmp, inp2);

    int len1 = strlen(inp1), len2 = strlen(inp2);
    int res = strcmp(inp1, inp2);
    if (len1 == len2) {
        if (res == 0)
            printf("=\n");
        else if (res == -1)
            printf("<\n");
        else
            printf(">\n");
    } else if (len1 > len2)
        printf(">\n");
    else
        printf("<\n");

    return 0;
}