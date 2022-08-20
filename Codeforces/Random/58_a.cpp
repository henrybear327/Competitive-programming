#include <stdio.h>
#include <string.h>

const char *target = "hello";
int main()
{
    char inp[103];
    scanf("%s", inp);

    int len = strlen(inp);
    int j = 0;
    for (int i = 0; j < 5 && i < len; i++) {
        if (inp[i] == target[j]) {
            j++;
        }
    }

    if (j == 5)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
