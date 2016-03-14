#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[100010] = {'\0'};
    while (fgets(input, 100010, stdin) != NULL) {
        input[strlen(input) - 1] = '\0';
        // scan for AB
        int AB = 0, BA = 0;
        for (int i = 0; i < strlen(input) - 1; i++) {
            if (AB == 0 && input[i] == 'A' && input[i + 1] == 'B') {
                AB = 1;
                i++;
                continue;
            } else if (AB == 1 && input[i] == 'B' && input[i + 1] == 'A') {
                BA = 1;
                i++;
                continue;
            }
        }

        if (AB == 0 || BA == 0) {
            AB = BA = 0;
            for (int i = 0; i < strlen(input) - 1; i++) {
                if (BA == 0 && input[i] == 'B' && input[i + 1] == 'A') {
                    BA = 1;
                    i++;
                    continue;
                } else if (BA == 1 && input[i] == 'A' && input[i + 1] == 'B') {
                    AB = 1;
                    i++;
                    continue;
                }
            }
        }

        if (AB == 1 && BA == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}