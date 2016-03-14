#include <cstdio>

int main()
{
    char input[1000];
    int cases;
    fgets(input, 1000, stdin);
    sscanf(input, "%d", &cases);
    while (cases--) {
        fgets(input, 1000, stdin); // get empty line

        int columns;
        fgets(input, 1000, stdin);
        sscanf(input, "%d", &columns);

        int diff = -1;
        bool flag = true;
        while (columns--) {
            int north, south;
            fgets(input, 1000, stdin);
            sscanf(input, "%d %d", &north, &south);

            if (diff == -1)
                diff = north - south;
            else
                diff = (north - south == diff) ? diff : -10;

            if (diff == -10)
                flag = false;
        }

        if (flag)
            printf("yes\n");
        else
            printf("no\n");

        if (cases)
            printf("\n");
    }

    return 0;
}
