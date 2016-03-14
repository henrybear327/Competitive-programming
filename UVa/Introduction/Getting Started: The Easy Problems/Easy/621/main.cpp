#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    char input[1000] = {'\0'};
    fgets(input, 1000, stdin);
    sscanf(input, "%d", &cases);
    //printf("cases %d\n", cases);

    while(cases--) {
        fgets(input, 1000, stdin);
        //printf("%s", input);

        int len = strlen(input) - 1;

        if(len == 1 || len == 2) {
            if(input[0] == '1' || input[0] == '2' || input[0] == '7')
                printf("+\n");
            else
                printf("error: %d\n", len);
        } else if(input[0] == '9' && input[len - 1] == '4')
            printf("*\n");
        else if(input[len -2] == '3' && input[len - 1] == '5')
            printf("-\n");
        else if(input[0] == '1' && input[1] == '9' && input[2] == '0')
            printf("?\n");
        else
            printf("error: %d\n", len);
    }

    return 0;
}