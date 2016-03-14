#include <bits/stdc++.h>

int main()
{
    char input[100];
    const char *greeting[6] = {"HELLO",   "HOLA", "HALLO",
                               "BONJOUR", "CIAO", "ZDRAVSTVUJTE"
                              };
    const char *country[6] = {"ENGLISH", "SPANISH", "GERMAN",
                              "FRENCH",  "ITALIAN", "RUSSIAN"
                             };

    int count = 1;
    while (fgets(input, 100, stdin) != NULL && input[0] != '#') {
        input[strlen(input) - 1] = '\0';
        bool flag = false;
        for (int i = 0; i < 6; i++) {
            if (strcmp(input, greeting[i]) == 0) {
                printf("Case %d: %s\n", count++, country[i]);
                flag = true;
                break;
            }
        }

        if (flag == false)
            printf("Case %d: UNKNOWN\n", count++);
    }
    return 0;
}
