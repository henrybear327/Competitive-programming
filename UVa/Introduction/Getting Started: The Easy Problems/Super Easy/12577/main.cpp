#include <bits/stdc++.h>

int main()
{
    int count = 1;
    while (1) {
        char input[100];
        fgets(input, 100, stdin);

        if (input[0] == '*')
            break;

        if (strcmp(input, "Hajj\n") == 0)
            printf("Case %d: Hajj-e-Akbar\n", count++);
        else
            printf("Case %d: Hajj-e-Asghar\n", count++);
    }

    return 0;
}
